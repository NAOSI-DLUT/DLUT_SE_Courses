package servlet;

import Dao.BaseDao;
import entity.Man;

import java.io.IOException;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class jumpServlet
 */
@WebServlet("/jumpServlet")
public class jumpServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public jumpServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");
		String string = request.getParameter("info");//获得输入的页码
		if(string.length()!=0) {
			//确实传过来了想要跳转的页码
			HttpSession hr =request.getSession();
			int PageNum=Integer.parseInt(string);
			int totalPage=(int)hr.getAttribute("totalPage");
			if ((PageNum <= totalPage) && PageNum >= 1) {//页码合法，只需要将页码放进会话然后返回界面重新输出即可
				hr.setAttribute("pageNum", PageNum);
			}
			BaseDao bd = new BaseDao();
			String query = (String) hr.getAttribute("query");
			int NumPage = (int) hr.getAttribute("dataNum");
			ArrayList<Man> manList = (ArrayList<Man>) bd.searchOf(query,PageNum,NumPage);
			hr.setAttribute("content",manList);
		}
		request.getRequestDispatcher("/index1.jsp").include(request, response);
		request.getRequestDispatcher("/index2.jsp").include(request, response);
	}

}
