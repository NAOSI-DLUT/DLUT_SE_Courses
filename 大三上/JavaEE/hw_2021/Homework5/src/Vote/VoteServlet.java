package Vote;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/VoteServlet")
public class VoteServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public VoteServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.setCharacterEncoding ("utf-8");
		response.setCharacterEncoding("utf-8");
		
		System.out.println("in VoteServlet");
		
		String name = request.getParameter("choose");
		if(name == null)
			System.out.println("null name");
		System.out.println("name " + name);
		PrintWriter out=response.getWriter();
		if(name == null || name == "") {
			out.print("<script charset=UTF-8>alert('Error! Please choose again!');window.location.href='GetVoteServlet'</script>");
			return;
		}
		
		Database db = new Database();
		boolean flag = db.addVoteNum(name);
		
		String userid1 = (String)request.getAttribute("userid");
		String userid2 = request.getParameter("userid");
		if(userid1 == null && userid2 == null)
			System.out.println("both null");
		String userid = (userid1==null||userid1.equals(""))?userid2:userid1;
		request.setAttribute("userid", userid);
		
		if(flag == true) {
			System.out.println("userid = " + userid);
			boolean fflag = db.delUserChances(userid);
			if(fflag == false) {
				db.release();
				out.print("<script charset=UTF-8>alert('Error when delete chances!')</script>");
				request.getRequestDispatcher("GetResultServlet").forward(request, response);
			} else {
				db.release();
				out.print("<script charset=UTF-8>alert('Sucessfully Voted!')</script>");
				request.getRequestDispatcher("GetResultServlet").forward(request, response);
			}
		} else {
			db.release();
			out.print("<script charset=UTF-8>alert('Failed!')</script>");
			request.getRequestDispatcher("GetResultServlet").forward(request, response);
		}

		return;
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
