package SearchMan;

import java.io.*;
import java.util.*;

import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

/**
 * Servlet implementation class SearchServlet
 */
@WebServlet("/SearchServlet")
public class SearchServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static int CACHE_SIZE = 3;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SearchServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) 
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		System.out.println("doGet ing...");
		
		//一些基础设置和标题
		String fileName = request.getSession().getServletContext()
                .getRealPath("/")
                + "WEB-INF/contact/homework.xls";
        fileName = fileName.replace("\\", "/");
		
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
		out.println("<html><head><title>软院找人</title></head>");
		out.println("<body bgcolor=\"white\"><font size=4>");
		
		// 得到session、cache、ReadFile
		HttpSession session = request.getSession();
		Object o = session.getAttribute("cache");
		FIFOCache<String, Man> cache = null;
		if(o == null) {
			cache = new FIFOCache<>(CACHE_SIZE);
			session.setAttribute("cache", cache);
		} else {
			cache = (FIFOCache) o;
		}
		
		ReadFile rf = new ReadFile(fileName, cache); 
		
		String query = request.getParameter("query");
		
		out.println("<form method=get>软院找人系统<p> ");
		
		//输入文字框和提交按钮
		out.println("<input type=\"text\" name=\"query\"/>");
		out.println("<input type=\"submit\" value=\"Search\"></form>");
		
		if(query!= null) {
			out.println("You are asking for " + query + "<p>");
			query = query.trim();	// 去除首位空格
			
			ArrayList<Man> manList = rf.search(query);
			Iterator<Man> it = manList.iterator();
			while(it.hasNext()) {
				Man man = it.next();
				out.println("the content is " + man.printMan() + "<p>");
			}
			
		}
		
		out.println("</font></body></html>");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		System.out.println("doPost ing...");
		
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		doGet(request, response);
	}

}
