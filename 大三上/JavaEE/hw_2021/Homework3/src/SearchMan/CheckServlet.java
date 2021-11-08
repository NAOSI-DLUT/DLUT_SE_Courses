package SearchMan;

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;



@WebServlet("/CheckServlet")
public class CheckServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
	private static String username = "root";
	private static String userpwd = "123456";
    
    public CheckServlet() {
        super();
        
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.setCharacterEncoding ("utf-8");
		response.setCharacterEncoding("utf-8")
		;
		String role = (String)request.getParameter("role");
		
		System.out.println("role = " + role);
		
		if(role.equals("normal")) {
			System.out.println("if role=normal");
			request.getRequestDispatcher("FirstSearchPage.jsp").forward(request, response);
			return;
			
		} else {
			
			String uname = (String)request.getParameter("username");
			String upwd = (String)request.getParameter("userpwd");
			
			PrintWriter out=response.getWriter();
			
			if(uname == null || upwd == null) {
				out.print("<script charset=UTF-8>alert('Fail to log in!');window.location.href='ChooseRolePage.jsp'</script>");
				return;
			}
				
			if(uname.equals(username)==false || upwd.equals(userpwd)==false) {
				out.print("<script charset=UTF-8>alert('Fail to log in!');window.location.href='ChooseRolePage.jsp'</script>");
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
