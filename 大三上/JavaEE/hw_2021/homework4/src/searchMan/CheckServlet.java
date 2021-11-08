package searchMan;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/CheckServlet")
public class CheckServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
	private static String adminUserName = "root";
	private static String adminUserPwd = "123456";
    
    public CheckServlet() {
        super();
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.setCharacterEncoding ("utf-8");
		response.setCharacterEncoding("utf-8");
		
		String role = (String)request.getParameter("role");
		System.out.println("role = " + role);
		
		String uname = (String)request.getParameter("username");
		String upwd = (String)request.getParameter("userpwd");
		PrintWriter out=response.getWriter();
		
		if(uname == null || upwd == null || uname == "" || upwd == "") {
			out.print("<script charset=UTF-8>alert('Please enter name and password!');window.location.href='LogIn.jsp'</script>");
			return;
		}
		
		request.getSession().setAttribute("from", role);
		if(role.equals("normal")) {
			
			System.out.println("if role=normal");
			
			Database db = new Database();
			String manPwd = db.getPwd(uname);
			
			System.out.println("uname:" + uname + " realpwd:" + manPwd);
			
			if(manPwd.equals("") || manPwd.equals(upwd) == false) {
				out.print("<script charset=UTF-8>alert('Fail to log in!');window.location.href='LogIn.jsp'</script>");
				db.release();
				return;
			}
			
			request.getSession().setAttribute("id", uname);
			request.getRequestDispatcher("UserPage.jsp").forward(request, response);
			db.release();
			return;
			
		} else {
			
			System.out.println("if role=admin");
			
			if(uname.equals(adminUserName)==false || upwd.equals(adminUserPwd) == false) {
				out.print("<script charset=UTF-8>alert('Fail to log in!');window.location.href='LogIn.jsp'</script>");
				return;
			}
			
			request.getRequestDispatcher("AdminPage.jsp").forward(request, response);
			return;
			
		}
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}

}
