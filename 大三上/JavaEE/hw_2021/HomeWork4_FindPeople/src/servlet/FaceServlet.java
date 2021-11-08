package servlet;

import api.FaceDetect;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.util.List;


@WebServlet("/FaceServlet")
public class FaceServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;


    public FaceServlet() {
        super();
    }


    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {

        doPost(request, response);

    }


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {

        response.setCharacterEncoding("utf-8");

        PrintWriter out=response.getWriter();

        //String id1 = request.getParameter("id");

        // 检测是否为多媒体上传
        if (!ServletFileUpload.isMultipartContent(request)) {
            System.out.println("Error: 表单必须包含 enctype=multipart/form-data");
            return;
        }

        // 获取路径来存储文件
        //String path = "D:";
        //System.out.println(this.getServletContext().getRealPath(""));
        String path = this.getServletContext().getRealPath("/") + "identify";
        System.out.println("图片存储路径：" + path);

        // 根据路径名创建一个 File实例
        File file = new File(path);
        if (!file.exists()) {
            file.mkdir();       // 如果不存在则创建此路径的目录
        }

        DiskFileItemFactory factory = new DiskFileItemFactory();
        ServletFileUpload upload = new ServletFileUpload(factory);
        // 中文处理
        upload.setHeaderEncoding("utf-8");

        boolean flag = false;
        try {

            // 解析请求的内容提取文件数据
            List<FileItem> formItems = upload.parseRequest(request);
            if (formItems != null && formItems.size() > 0) {
                // 迭代表单数据
                for (FileItem item : formItems) {
                    // 处理不在表单中的字段
                    String[] name = item.getName().toString().split("\\.");
                    String id = name[0];
                    if (!item.isFormField()) {
                        System.out.println("提交的是文件 ！");
                        String fileName = item.getName();
                        System.out.println("上传的文件名：" + fileName);

                        // 获取文件名后缀, 返回 "."在文件名最后出现的索引, 就是文件后缀名
                        // 给文件设置名字
                        String prefix = fileName.substring(fileName.lastIndexOf(".") + 1);
                        String fileSaveName = id + "." + prefix; // id.后缀
                        System.out.println("文件名："+fileSaveName);
                        // 获取文件输入流
                        InputStream inputStream = item.getInputStream();
                        // 创建文件输出流，用于向指定文件名的文件写入数据
                        FileOutputStream fileOutputStream = new FileOutputStream(path + "/" + fileSaveName);
                        int index = 0;

                        // 从输入流读取数据的下一个字节，到末尾时返回 -1
                        while ((index = inputStream.read()) != -1) {
                            fileOutputStream.write(index);  // 将指定字节写入此文件输出流
                        }

                        // 关闭流
                        inputStream.close();
                        fileOutputStream.close();
                        item.delete();
                    }
                    String realPath = path + "\\" + item.getName();
                    System.out.println(realPath);
                    String res = FaceDetect.faceDetecttest(realPath);
                    if(res.contains("SUCCESS")){
                        request.setAttribute("information",id);
                        request.getRequestDispatcher("TestServlet").forward(request, response);
                    }else{
                        out.print("<script charset=UTF-8>alert('can't find any person!');</script>");
                        return;
                    }
                }
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

}
