package Vote;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/AdminServlet")
public class AdminServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

    public AdminServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.setCharacterEncoding ("utf-8");
		response.setCharacterEncoding("utf-8");
		
		String action = request.getParameter("action");
		System.out.println("action = " + action);
		
		Database db = new Database();
		PrintWriter out=response.getWriter();
		
		if(action.equals("resetAllChances")) {
			boolean flag1 = db.resetAllChances();
			if(flag1) {
				db.release();
				out.print("<script charset=UTF-8>alert('Successfully reseted!');window.location.href='AdminPage.jsp'</script>");
				return;
			} else {
				db.release();
				out.print("<script charset=UTF-8>alert('Fail to reset!');window.location.href='AdminPage.jsp'</script>");
				return;
			}
		}
		
		else {
			String id = request.getParameter("id");
			if(id == null || id.equals("")) {
				db.release();
				out.print("<script charset=UTF-8>alert('Please enter a id of user!');window.location.href='AdminPage.jsp'</script>");
				return;
			}
			
			if(db.ifHasUser(id) == false) {
				db.release();
				out.print("<script charset=UTF-8>alert('Wrong id!');window.location.href='AdminPage.jsp'</script>");
				return;
			}
			
			boolean flag2 = db.setInactive(id);
			if(flag2) {
				db.release();
				out.print("<script charset=UTF-8>alert('Successfully setted inactive!');window.location.href='AdminPage.jsp'</script>");
				return;
			} else {
				db.release();
				out.print("<script charset=UTF-8>alert('Fail to set!');window.location.href='AdminPage.jsp'</script>");
				return;
			}
		}
		
		
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
