package Vote;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.*;


@WebServlet("/GetResultServlet")
public class GetResultServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public GetResultServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.setCharacterEncoding ("utf-8");
		response.setCharacterEncoding("utf-8");
		
		System.out.println("in Get Result Servlet");
		
		String userid1 = (String)request.getAttribute("userid");
		if(userid1 != null) 
			System.out.println("userid1 = " + userid1);
		else
			System.out.println("userid1 is null");
		
		String userid2 = request.getParameter("userid");
		String userid = (userid1==null||userid1.equals(""))?userid2:userid1;
		request.setAttribute("userid", userid);
		
		System.out.println("userid = " + userid);
		
		Database db = new Database();
		List<VoteObject> result = db.getVoteResult();
		
		request.setAttribute("voteResult", result);
		System.out.println("voteresult size = " + result.size());
		
		db.release();
		
		request.getRequestDispatcher("VoteResult.jsp").forward(request, response);
		return;
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
