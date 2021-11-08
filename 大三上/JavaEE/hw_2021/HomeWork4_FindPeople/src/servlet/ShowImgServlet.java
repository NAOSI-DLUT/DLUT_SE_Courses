package servlet;

import Dao.BaseDao;

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

        String id = request.getParameter("photo");
        System.out.println("idddd:"+id);

       BaseDao bd = new BaseDao();


        // 不需要检查partPath了

        String path = this.getServletContext().getRealPath("/") +"image/" + id + ".jpg";
        System.out.println("path = " + path);

        response.setContentType("image/jpg");
        File file = new File(path);
        if(file.exists()) {
            System.out.println("输出照片");
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
            bd.release();
        } else {
            response.reset();
            PrintWriter out=response.getWriter();
            out.write("无照片数据");
            bd.release();
            return;
        }
    }


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // TODO Auto-generated method stub
        doGet(request, response);
    }

}
