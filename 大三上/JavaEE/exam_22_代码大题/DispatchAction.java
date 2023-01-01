package org.apache.struts.actions;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import java.util.HashMap;

/**
	这是一个抽象类，派生类（后端控制器）继承该类，但是不会覆盖其方法（有时候也称函数），该类并无抽象方法。
	仅仅是增加多个后端控制方法罢了。
	
	例如，增删改查的业务逻辑，通常写上4个后端控制器类，CreateAction,RetrieveAction,UpdateAction,DeleteAction
	这些后端控制器类都继承Action类，实现执行函数，也就是覆盖Action类的execute函数。
		public ActionForward execute(	ActionMapping mapping,
										ActionForm form,
										HttpServletRequest request,
										HttpServletResponse response)
            throws Exception
			
	这样的设计导致后端控制器类数量太多，并且没有体现出聚合性，封装性。
	可以把这几个类的execute方法，封装在同一个类中，当然，函数声明重复了。
	然后把这些函数的函数名称修改一下，例如create函数，retrieve函数，update函数，delete函数。
	前端控制器org.apache.struts.action.ActionServlet的控制流程当然没有改变，它会调用后端控制器的execute函数。
	
	那么DispatchAction这个抽象类的execute方法的实现
	就是根据浏览器端（客户端）发送过来的url或者queryString来完成分发(dispatch)!
	DispatchAction这个类的execute方法的具体实现就是根据查询字符串(queryString)中的某个参数数据
	完成dispatch，例如，execute方法dispatch到create,retrieve,update,delete方法。
	
	既然我们已经理解了DispatchAction类的execute函数的设计需求，那么，同学们，你们会写出来
	DispatchAction类的execute函数吗？
	
	有两个问题需要知道，1. 后端控制器类继承DispatchAction类，增加多个控制函数，函数名称未知（输入输出参数都是不变的）。
	2. 根据查询字符串中的什么参数的值来完成转发(dispatch)？
	
	解决办法，在struts配置文件中指定使用什么参数，在struts配置文件中定义参数的名称。然后由
	参数的值决定调用哪个控制函数，调用过程当然使用的是Java反射机制。
	
	例如,struts配置文件
	<action path="/calc" type="action.CalcAction" name="calcForm" input="/calc.jsp" parameter="method"/>
	
	calc form表单中的四个提交按钮
	<input type="submit" name="method" value="add"/>
	<input type="submit" name="method" value="subtract"/>
	<input type="submit" name="method" value="multiply"/>
	<input type="submit" name="method" value="divide"/>
	
	同学们，通过这种方法，AddAction,SubtractAction,MultiplyAction,DivideAction的后端控制器数量
	就被减少到只写一个后端控制器类，CalcAction, 继承自DispatchAction，在CalcAction中定义四个控制函数即可。
	
	public ActionForward add(ActionMapping mapping,ActionForm form,HttpServletRequest request,HttpServletResponse response) throws Exception
	public ActionForward subtract(ActionMapping mapping,ActionForm form,HttpServletRequest request,HttpServletResponse response) throws Exception
	public ActionForward multiply(ActionMapping mapping,ActionForm form,HttpServletRequest request,HttpServletResponse response) throws Exception
	public ActionForward divide(ActionMapping mapping,ActionForm form,HttpServletRequest request,HttpServletResponse response) throws Exception
	
*/

public abstract class DispatchAction extends BaseAction {
    protected static Log log = LogFactory.getLog(DispatchAction.class);
    protected Class clazz = this.getClass();
	
	// methods这个map集合是缓存的目的，因为反射机制有点慢。
	// key: String, method name, value: Method object
	// 声明为HashMap<String,Method> methods更好，类型安全，更准确，否者HashMap，鬼知道这个集合里面都有啥。
    protected HashMap methods = new HashMap();  

    // execute函数的输入参数的类型，反射机制使用。同时，也是扩展的控制函数的参数类型。
    protected Class[] types =
        {
            ActionMapping.class, ActionForm.class, HttpServletRequest.class,
            HttpServletResponse.class
        };
	
	// 最重要的算法实现，完成dispatch
    public ActionForward execute(ActionMapping mapping, ActionForm form,
        HttpServletRequest request, HttpServletResponse response)
        throws Exception {

        // 从配置文件中获取parameter的名，例如，method
        String parameter = getParameter(mapping, form, request, response);

        // 从请求对象中，获取由parameter的值指定的控制函数的名称
		// String name = request.getParameter(parameter)
        String name = getMethodName(mapping, form, request, response, parameter);	// 考试内容
		
		// name的值就是控制函数的名称，例如add,subtract,multipy,divide之类的。

        // Prevent recursive calls, 避免递归，扩展的控制函数的名称不能是execute
        if ("execute".equals(name) || "perform".equals(name)) {
            String message =
                messages.getMessage("dispatch.recursive", mapping.getPath());
            log.error(message);
            throw new ServletException(message);
        }

		// 动态调用控制函数，完成dispatch! 
		// 控制流程是前端控制器调用CalcAction类的execute函数（继承自DispatchAction）
		// 然后execute函数将调用转发到add函数，subtract函数等等。
		
        // Invoke the named method, and return the result
        return dispatchMethod(mapping, form, request, response, name);
    }

    
    protected ActionForward dispatchMethod(ActionMapping mapping,
        ActionForm form, HttpServletRequest request,
        HttpServletResponse response, String name)
        throws Exception {
      
        // Identify the method object to be dispatched to
        Method method = null;

        try {
            method = getMethod(name);	// 根据函数名称，找到函数对象。
        } catch (NoSuchMethodException e) {
            String message =
                messages.getMessage("dispatch.method", mapping.getPath(), name);
            log.error(message, e);
            String userMsg =
                messages.getMessage("dispatch.method.user", mapping.getPath());
            throw new NoSuchMethodException(userMsg);
        }

        ActionForward forward = null;

        try {
			// Java反射机制，执行某个对象的函数，动态调用。考试重点。
            Object[] args = { mapping, form, request, response };
            forward = (ActionForward) method.invoke(this, args);

        }
		
        // Return the returned ActionForward instance
        return (forward);
    }

    protected String getParameter(ActionMapping mapping, ActionForm form,
        HttpServletRequest request, HttpServletResponse response)
        throws Exception {

        // 从struts-config.xml配置文件中读取action元素的parameter属性的值。
		// 当然是ActionMapping类封装的功能了。ActionMapping类不考。
        String parameter = mapping.getParameter();	// 算法重点

        return parameter;
    }

    // 根据函数名称获取函数对象，需要调用Class类的的getMethod函数，Java的反射机制！
    protected Method getMethod(String name)
        throws NoSuchMethodException {
		// 同步，加锁，这个性能不好，同学们如何解决？不使用同步代码可以吗？
        synchronized (methods) {	// Action是单实例对象，注意methods线程安全。
            Method method = (Method) methods.get(name);

            if (method == null) {
                method = clazz.getMethod(name, types);	// 重点，Java反射机制
				// 保存到Map集合中，下次再调用getMethod函数直接从Map集合中读取，不再调用反射。
                methods.put(name, method);	
            }

            return (method);
        }
    }

    
    protected String getMethodName(ActionMapping mapping, ActionForm form,
        HttpServletRequest request, HttpServletResponse response,
        String parameter) throws Exception {
        //从请求对象中获取参数数据,HttpServletRequest中的获取参数的方法一定要掌握，考试重点。
        return request.getParameter(parameter);
    }
}
