package SearchMan;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.sql.*;
import java.util.*;

/**
 * Servlet implementation class SearchServlet
 */
@WebServlet("/SearchServlet")
public class SearchServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	private static List<Man> manList = null;
	
	private int maxRows;
	private int totalPageCount;
	
       
    /*
         * 构造函数
     */
    public SearchServlet() {
        super();
    }

	/*
	 * get
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) 
			throws ServletException, IOException {
		
		System.out.println("--------------");
		System.out.println("doGet");
		
		//获取查询字符串
		String query;
		if(request.getParameter("query") != null) {
			query = request.getParameter("query");
		} else {
			query = (String)request.getSession().getAttribute("query");
		}
		
		request.getSession().setAttribute("query", query);
		
		String action = request.getParameter("action");		//判断是来自哪里的串
		if(action == null)
			action = "";
		if(action.equals("searchAdmin")) {
			request.setAttribute("from", "admin");
		} else {
			request.setAttribute("from", "normal");
		}
		
		System.out.println("query = " + query);
		if(query == null || query == "") {
			System.out.println("action = " + action);
			if(action.equals("searchAdmin")) {
				request.getRequestDispatcher("AdminPage.jsp").forward(request, response);
				return;
			}
			else {
				request.getRequestDispatcher("FirstSearchPage.jsp").forward(request, response);
				return;
			}
		}
		
		
		//当前页数
		int currentPage;
		if(request.getParameter("currentPage") == null)	{//如果没有设置 
			currentPage = 1;
		} else
			currentPage = Integer.parseInt(request.getParameter("currentPage"));
		request.setAttribute("currentPage", currentPage);
		
		
		
		//获取每页数量
		System.out.println("every page");
		
		int numPerPage;
		String s1 = request.getParameter("updatePerPage");
		String s2 = request.getParameter("numPerPage");
		Object o3 = request.getSession().getAttribute("numPerPage");
		
		if(s1 != null) {		// 有更新
			if(s1 == "") {
				numPerPage = 5;
			} else {
				numPerPage = Integer.parseInt(s1);
			}
			currentPage = 1;
			
		} else {				// 无更新
			if(s2 != null) {		//来自HelloPage
				if(s2 == "")
					numPerPage = 5;
				else
					numPerPage = Integer.parseInt(s2);
			} else {				// 来自翻页
				numPerPage = (Integer)o3;
			}
			
		}
		
		if(numPerPage == 0)
			numPerPage = 5;
		
		request.getSession().setAttribute("numPerPage", numPerPage);
		request.setAttribute("numPerPage", numPerPage);
		
		System.out.println("in SearchServlet currentPage = " + currentPage);
		System.out.println("in SearchServlet numPerPage = " + numPerPage);
		
		
		
		//获取数据库类型
		Database db = new Database();
		
		//获取总页数、总记录条数
		List<Integer> ans = db.getMaxPages(query, numPerPage);
		totalPageCount = ans.get(0);
		maxRows = ans.get(1);
		request.setAttribute("maxRows", maxRows);
		
		System.out.println("in SearchServlet totalPageCount = " + totalPageCount);
		request.setAttribute("totalPageCount", totalPageCount);

		//查询
		manList = (ArrayList<Man>)db.searchOf(query, currentPage, numPerPage);
		request.setAttribute("manList", manList);
		
		System.out.println("manList size = " + manList.size());
		
		//把request转发给JSP
		request.getRequestDispatcher("SplitPages.jsp").forward(request, response);
		
		db.release();
	}

	/*
	 * post
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) 
			throws ServletException, IOException {
		
		doGet(request, response);
	}

	
	
	
}
