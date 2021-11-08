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
 * Servlet implementation class PageServlet
 */
@WebServlet("/PageServlet")
public class PageServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PageServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");
		HttpSession hr=request.getSession();
		int PageNum=Integer.parseInt(request.getParameter("pageNum"));
		
		//接受传过来的页面数，也就是第几页，用来判断截取那，这个只是用来确定上一页下一页的，边界已经在jsp中搞完了，因此这里只需要将获取的页码放会话
		//然后返回界面重新输出即可
		BaseDao bd = new BaseDao();
		hr.setAttribute("pageNum", PageNum);
		String query = (String) hr.getAttribute("query");
		int NumPage = (int) hr.getAttribute("dataNum");
		ArrayList<Man> manList = (ArrayList<Man>) bd.searchOf(query,PageNum,NumPage);
		hr.setAttribute("content",manList);

		bd.release();

		request.getRequestDispatcher("/Index1.jsp").include(request, response);
		request.getRequestDispatcher("/index2.jsp").include(request, response);

	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) {
		// TODO Auto-generated method stub
		try {
			doGet(request,response);
		} catch (ServletException | IOException e) {
			e.printStackTrace();
		}
	}

}
