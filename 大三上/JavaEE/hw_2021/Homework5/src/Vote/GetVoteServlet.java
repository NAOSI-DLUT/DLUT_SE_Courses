package Vote;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.*;


@WebServlet("/GetVoteServlet")
public class GetVoteServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public GetVoteServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		request.setCharacterEncoding ("utf-8");
		response.setCharacterEncoding("utf-8");
		
		Database db = new Database();
		
		System.out.println("in getVoteServlet");
		String userid1 = (String)request.getAttribute("userid");
		String userid2 = request.getParameter("userid");
		String userid = (userid1==null||userid1.equals(""))?userid2:userid1;
		System.out.println("userid:" + userid);
		request.setAttribute("userid", userid);
		
		int chances = db.getUserChances(userid);
		PrintWriter out=response.getWriter();
		System.out.println("chances = " + chances);
		
		if(chances == 0) {
			db.release();
			out.print("<script charset=UTF-8>alert('You have no chances to vote!')</script>");
			request.getRequestDispatcher("GetResultServlet").forward(request, response);
			return;
		}
		
		List<String> result = db.getVoteInfo();
		request.setAttribute("voteInfo", result);
		
		System.out.println("voteinfo size = " + result.size());
		
		db.release();
		
		request.getRequestDispatcher("VotePage.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
