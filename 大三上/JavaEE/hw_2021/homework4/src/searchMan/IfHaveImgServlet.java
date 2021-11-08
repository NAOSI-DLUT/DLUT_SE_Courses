package searchMan;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/IfHaveImgServlet")
public class IfHaveImgServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       

    public IfHaveImgServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String id = (String)request.getSession().getAttribute("id");

		Database db = new Database();
		
		String partPath = db.getPath(id);
		System.out.println("partPath: " + partPath);
		
		if(partPath == null || partPath.equals("")) {
			
			System.out.println("in partPath is null");
			response.reset();
			PrintWriter out=response.getWriter();
			out.print("<script charset=UTF-8>alert('No picture found!');window.location.href='UserPage.jsp'</script>");
			db.release();
			return;
			
		} else {
			
			request.getRequestDispatcher("ShowImg.jsp").forward(request, response);
		}
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
