package searchMan;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/ChangePwdServlet")
public class ChangePwdServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public ChangePwdServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.setCharacterEncoding ("utf-8");
		response.setCharacterEncoding("utf-8");
		
		String oldpwd = request.getParameter("oldpwd");
		String newpwd = request.getParameter("newpwd");
		String confirmpwd = request.getParameter("confirmpwd");
		
		String username = (String)request.getSession().getAttribute("id");
		System.out.println("In Changepwd \n username id: " + username);
		
		response.reset();
		PrintWriter out=response.getWriter();
		
		if(oldpwd == null || newpwd == null || confirmpwd == null || oldpwd == "" || newpwd == "" || confirmpwd == "") {
			out.print("<script charset=UTF-8>alert('Please enter passwords!');window.location.href='ChangePwd.jsp'</script>");
			return;
		}
		
		if(newpwd.equals(oldpwd)) {
			System.out.println("newpwd is equal to old pwd");
			out.print("<script charset=UTF-8>alert('Same password!');window.location.href='ChangePwd.jsp'</script>");
			return;
		}
		
		if(newpwd.equals(confirmpwd) == false) {
			System.out.println("wrong confirmpwd");
			response.reset();
			out.print("<script charset=UTF-8>alert('Please confirm your new password.');window.location.href='ChangePwd.jsp'</script>");
			return;
		}
		
		Database db = new Database();
		String realpwd = db.getPwd(username);
		if(realpwd.equals(oldpwd)==true) {
			
			boolean flag = db.changePwd(username, newpwd);
			
			if(flag) {
				out.print("<script charset=UTF-8>alert('Success!');window.location.href='UserPage.jsp'</script>");
			} else {
				out.print("<script charset=UTF-8>alert('Fail!');window.location.href='ChangePwd.jsp'</script>");
			}
		} else {
			out.print("<script charset=UTF-8>alert('Wrong password!');window.location.href='ChangePwd.jsp'</script>");
		}
		
		db.release();
		return;
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
