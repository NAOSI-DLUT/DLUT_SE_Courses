package org.apache.struts.actions;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.struts.Globals;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.config.MessageResourcesConfig;
import org.apache.struts.config.ModuleConfig;
import org.apache.struts.util.MessageResources;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Locale;
import java.util.Map;

/**
	DispatchAction类的转发逻辑比较简单，并且存在问题。
	<input type="submit" name="method" value="add"/>
	提交按钮的文字就是函数名称。安全性差，代码暴露，另外，按钮的文本可能是中文，按钮的文本可能包含空格等特殊字符。
	
	所以，必须改进。LookupDispatchAction继承自DispatchAction，继承了DispatchAction类的execute函数。
	execute函数：1)获取控制器的各个控制函数的名称，2)然后使用反射机制完成dispatch
	
	LookupDispatchAction类继承了DispatchAction类的execute函数。
	
	LookupDispatchAction类改写了(override) getMethodName这个重要的函数。修改了获取函数名称这个方法。
	根据函数名称进行dispatch这个逻辑没有做任何改变。
	
	所以，接下来分析一下LookupDispatchAction这个类的获取函数名称的过程。重点当然是"look up"
	
	DispatchAction类的getMethodName函数很简单，通过配置文件指定参数名称
	<action path="/calc" type="action.CalcAction" name="calcForm" input="/calc.jsp" 
		parameter="method"/>
	然后客户端提交指定参数的值，也就是函数名称
	<input type="submit" name="method" value="add"/>
	

	struts支持资源文件，在struts配置文件中声明资源文件
	<message-resources parameter="ApplicationResources" />
	然后在类加载路径中创建资源文件ApplicationResources.properties, 资源文件（属性文件）内容如下
		
		button.add=Add
		button.subtract=Subtract
		button.multiply=Multiply
		button.divide=Divide
		
	name(key)当然是程序命名，value是输出的标签文本，或者按钮文本之类的。资源文件中的值也可以是中文字符。
	资源文件中，name是唯一的，这是容易理解的。value允许重复。但是，value通常也是唯一的。
	
	使用了资源文件，并且支持国际化的提交按钮的代码如下：
	<html:form action="/calc">
		
		<html:submit property="method">
			<bean:message key="button.add"/>
		</html:submit>
		<html:submit property="method">
			<bean:message key="button.subtract"/>
		</html:submit>
	</html:form>
	
	struts的action配置没有变化，还是简单的设定参数
	<action path="/calc" type="action.CalcAction" name="calcForm" input="/calc.jsp" parameter="method"/>
	
	CalcAction不再继承DispatchAction了，而是继承抽象类LookupDispatchAction类，LookupDispatchAction类继承DispatchAction
	
	如何体现"lookup"呢？设计一个字典（也就是一个映射集合，Map），然后，提供key到控制函数名称的映射，
	抽象类LookupDispatchAction定义了一个抽象函数，protected abstract Map getKeyMethodMap(), 派生类需要实现该函数，例如：
	
	@Override
	public void Map getKeyMethodMap() {
		Map map = new HashMap();
		map.put("button.add", "add");	
		map.put("button.delete", "delete");
		return map;
	}
	该函数要求返回一个映射集合(可以称为函数字典)，key是资源文件中的key，value是函数名称，同学们，看到这里，接下来的代码我们大概能猜到。
	
	
	DispatchAction声明的下面的这个函数，我们要”改写“（override）它。
	protected String getMethodName(ActionMapping mapping, ActionForm form,
        HttpServletRequest request, HttpServletResponse response,
        String parameter) throws Exception 
		
	getMethodName的代码实现，根据parameter指定的浏览器端提交的参数名称，例如parameter="method",然后从请求对象中获取参数method的值
	根据这个值，在资源键值映射数据中”反向”查到keyName，然后再到“函数字典”中得到函数名称。
	
	资源文件中的name-value数据（key-value），存储到Map集合中，形式为：value-name。
	客户端提交的参数数据，根据value得到keyname, 
	然后从函数字典中根据keyname获取method name.


*/

public abstract class LookupDispatchAction extends DispatchAction {

    private static final Log LOG = LogFactory.getLog(LookupDispatchAction.class);
    protected Map localeMap = new HashMap(); 	// Map<Locale,Map<String,String>>
    protected Map keyMethodMap = null;			// Map<String,String>

    private Map initLookupMap(HttpServletRequest request, Locale userLocale) {
		
        Map lookupMap = new HashMap();
        this.keyMethodMap = this.getKeyMethodMap();

        // 获取模块配置，struts 支持模块开发（一个项目通常会分解为多个模块）
        // 同学们可以理解有多个类似struts-config.xml的配置文件。
        ModuleConfig moduleConfig =
            (ModuleConfig) request.getAttribute(Globals.MODULE_KEY);  // 通常根据uri获取模块配置

        // 读取该模块的配置文件中的资源文件的配置。
        // 在struts-config.xml文件中可以有多个这样的资源配置，例如在struts-config.xml中的声明
        //  <message-resources parameter="ApplicationResources" />
        //  <message-resources key="aaa" parameter="res.aaa.AResources" />
        //  <message-resources key="bbb" parameter="res.bbb.BResources" />

        // 获取所在模块的资源配置信息。一个模块可以有多个资源文件，见上面的配置信息。
        // MessageResourcesConfig对象有parameter和key属性。
        MessageResourcesConfig[] mrc = 
            moduleConfig.findMessageResourcesConfigs();

        // 这个注释不准确。Look through all module's MessageResources
        // 遍历每个message-resources
        for (int i = 0; i < mrc.length; i++) {
            MessageResources resources =
                this.getResources(request, mrc[i].getKey());

            // 开始处理资源文件中的一部分name:value pair数据。主要是根据函数字典进行数据遍历。
            // Look for key in MessageResources
            Iterator iter = this.keyMethodMap.keySet().iterator();

            while (iter.hasNext()) {
                String key = (String) iter.next();
                String text = resources.getMessage(userLocale, key);	// 支持国际化

                // Found key and haven't added to Map yet, so add the text
                if ((text != null) && !lookupMap.containsKey(text)) {
                    lookupMap.put(text, key);	// 考试内容，注意是text:key映射，不是key:text映射！
            }
        }

        return lookupMap;
    }

    // 派生类必须覆盖这个抽象函数
    protected abstract Map getKeyMethodMap();


    // 参数keyName就是浏览器端提交的参数信息，例如：method=Add
    // keyName是Add，根据这个value，找到button.add这个key
    protected String getLookupMapName(HttpServletRequest request,
        String keyName, ActionMapping mapping)
        throws ServletException {
        // Based on this request's Locale get the lookupMap
        Map lookupMap = null;

        synchronized (localeMap) {
            Locale userLocale = this.getLocale(request);	// 获取浏览器的区域语言,从Action类继承过来的。
            lookupMap = (Map) this.localeMap.get(userLocale);
            if (lookupMap == null) {
                lookupMap = this.initLookupMap(request, userLocale);
                this.localeMap.put(userLocale, lookupMap);
            }
        }

        // 从value:key映射集合中，获取key
        String key = (String) lookupMap.get(keyName);	// 资源文件中的value:key构成的映射集合

        // Find the method name
        String methodName = (String) keyMethodMap.get(key);	// 在函数字典中lookup up到函数名称

        return methodName;	// 返回函数名称
    }

    // 考试重点
    // LookupDispatchAction类的核心实现，根据浏览器提交的参数数据，以及函数字典，获取派发的函数名称！
    @Override
    protected String getMethodName(ActionMapping mapping, ActionForm form,
        HttpServletRequest request, HttpServletResponse response,
        String parameter) throws Exception {
			
        // 从浏览器端发送过来的参数获取标签文本、按钮文本之类的参数值
        String keyName = request.getParameter(parameter);

        if ((keyName == null) || (keyName.length() == 0)) {
            return null;
        }

        String methodName = getLookupMapName(request, keyName, mapping);

        return methodName;
    }
}
