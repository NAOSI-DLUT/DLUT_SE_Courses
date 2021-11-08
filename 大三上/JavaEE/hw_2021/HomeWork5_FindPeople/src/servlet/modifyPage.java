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
 * Servlet implementation class modifyPage
 */
@WebServlet("/modifyPage")
public class modifyPage extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public modifyPage() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");
		HttpSession hs = request.getSession();
		String string;
		string = request.getParameter("info1");
		if (string.length() != 0) {
			int dataNum = Integer.parseInt(string); // 获取想要每页输出的条数
			if (dataNum > 0) {
				int totalNum = (int) hs.getAttribute("totalNum");
				// 获取总共的数据条数，用于下面计算多少页
				int pageNumber;
				// 总共有多少页，计算出来然后再放进去，用于设置之后的显示
				if (totalNum % dataNum == 0) {
					pageNumber = totalNum / dataNum;
				} else {
					pageNumber = totalNum / dataNum + 1;
				}
				hs.setAttribute("dataNum", dataNum);
				hs.setAttribute("pageNum", 1);
				hs.setAttribute("totalPage", pageNumber);
				HttpSession hr=request.getSession();
				BaseDao bd = new BaseDao();
				String query = (String) hr.getAttribute("query");
				int NumPage = (int) hr.getAttribute("dataNum");
				ArrayList<Man> manList = (ArrayList<Man>) bd.searchOf(query,1,NumPage);
				hr.setAttribute("content",manList);
			}
		}
		request.getRequestDispatcher("/index1.jsp").include(request, response);
		request.getRequestDispatcher("/index2.jsp").include(request, response);
	}

}
