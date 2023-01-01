package org.apache.struts.actions;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * 同一个后端控制器类，对应多个<action>，也就是说，同一个后端控制器可以有多个控制函数，
 * 例如，CalcAction类，有add,subtract,multiply,divide函数，DispatchAction类的execute函数完成dispatch
 * 那么如何dispatch呢？execute函数如何转发调用到add,subtract,multipy,divide函数呢？
 * MappingDispatchAction函数改写（覆盖，override)了getMethodName函数，该函数返回的控制函数名称来自
 * <action>元素的parameter属性的值。这样，可以把有一定相关性，聚合性的函数封装在一个后端控制器中。
 * 然后为这个后端控制器定义多个path。例如：
 * 
 * <action path="/add" type="action.CalcAction" parameter="add"/>
 * <action path="/subtract" type="action.CalcAction" parameter="subtract"/>
 * <action path="/multiply" type="action.CalcAction" parameter="multiply"/>
 * <action path="/divide" type="action.CalcAction" parameter="divide"/>
 * 
 * 只要action.CalcAction类继承MappingDispatchAction类就可以了。
 * parameter直接定义控制函数名称。
*/
public class MappingDispatchAction extends DispatchAction {
  
    // 这个函数没有存在的必要，直接继承DispatchAction类就可以了。
    // 毫无意义的覆盖。
    protected String getParameter(ActionMapping mapping, ActionForm form,
        HttpServletRequest request, HttpServletResponse response)
        throws Exception {

        return mapping.getParameter();

    }

    // MappingDispatchAction唯一有意义的函数，覆盖了DispatchAction类的getMethodName函数。
    protected String getMethodName(ActionMapping mapping, ActionForm form,
        HttpServletRequest request, HttpServletResponse response,
        String parameter) throws Exception {

        // 派发的控制函数的函数名称就是在<action>元素中parameter属性的值。
        return parameter;
    }
}
