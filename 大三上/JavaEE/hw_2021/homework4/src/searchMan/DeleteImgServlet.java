package searchMan;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/DeleteImgServlet")
public class DeleteImgServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       

    public DeleteImgServlet() {
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
		}
		
		String path = this.getServletContext().getRealPath("/") + partPath;
		System.out.println("path = " + path);
		
		File file = new File(path);
		response.reset();
		PrintWriter out=response.getWriter();
		if (file.isFile() && file.exists()) {
			file.delete();
			
			boolean flag = db.deleteFile(id);
			if(flag == true) {
				out.print("<script charset=UTF-8>alert('Successfully deleted!');window.location.href='UserPage.jsp'</script>");
				db.release();
				return;
			} else {
				out.print("<script charset=UTF-8>alert('Fail to delete in database!');window.location.href='UserPage.jsp'</script>");
				db.release();
				return;
			}
		} else {
			out.print("<script charset=UTF-8>alert('No picture found!');window.location.href='UserPage.jsp'</script>");
			db.release();
			return;
		}
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
