package searchMan;

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/ShowImgServlet")
public class ShowImgServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    
    public ShowImgServlet() {
        super();
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String id = (String)request.getSession().getAttribute("id");

		Database db = new Database();
		
		String partPath = db.getPath(id);
		// 不需要检查partPath了
		
		String path = this.getServletContext().getRealPath("/") + partPath;
		System.out.println("path = " + path);
		
		response.setContentType("image/jpeg");
		File file = new File(path);
		if(file.exists()) {
			InputStream in = new FileInputStream(path);
			response.reset();
			OutputStream os = response.getOutputStream();  //创建输出流
			byte[] b = new byte[1024];  
			while (in.read(b) != -1) {
				os.write(b);
			}
			in.close(); 
			os.flush();
			os.close();
			db.release();
		} else {
			response.reset();
			PrintWriter out=response.getWriter();
			out.print("<script charset=UTF-8>alert('No picture found!');window.location.href='UserPage.jsp'</script>");
			db.release();
			return;
		}
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
