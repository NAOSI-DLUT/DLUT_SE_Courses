package servlet;

import Dao.BaseDao;
import entity.Man;
import service.FIFOCache;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@WebServlet("/SearchServlet")
public class SearchServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final int CACHE_SIZE = 50;


    public SearchServlet() {
        super();
    }

    @Override
    public void init() throws ServletException {
        // TODO 自动生成的方法存根
        super.init();
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
        String query = request.getParameter("query");
        System.out.println("query"+query);
//        String fileName = request.getSession().getServletContext()
//                .getRealPath("/")
//                + "WEB-INF/contact/homework.xls";
//        fileName = fileName.replace("\\", "/");

        HttpSession session = request.getSession();
        Object o = session.getAttribute("cache");
        FIFOCache<String, Man> cache;
        if(o == null) {
            cache = new FIFOCache<>(CACHE_SIZE);
            session.setAttribute("cache", cache);
        } else {
            cache = (FIFOCache) o;
        }
        //通过文件读取的方法
//		ReadFile rf = new ReadFile(fileName, cache);
        BaseDao bd = new BaseDao();

        if (query.length() == 0) {//没有信息转发到原网页
            request.getRequestDispatcher("/account.jsp").include(request, response);
        } else {
            //查询数据 --xy
            query = query.trim();	// 去除首位空格

            ArrayList<Man> manList = (ArrayList<Man>) bd.searchOf(query,1,20);

            request.getRequestDispatcher("/index1.jsp").include(request, response);
            //以上都是将数据读到集合中去
            for (Man man : manList) {
                System.out.println("---------------" + man.getId());
            }
            //下面我们将一些与分页有关的数据进行处理并将其放入session中
            HttpSession hs=request.getSession();
            int dataNum;//数据条数
            int pageNum;//分页总数
            int datainpage = 0;//每页数据条数
            datainpage=100;//每页的数据条数暂且设置成100
            List<Integer> pages = bd.getMaxPages(query,datainpage);
            pageNum = pages.get(0);
            System.out.println("pagenum:"+pageNum);
            dataNum= pages.get(1);
            System.out.println(dataNum);

            bd.release();

            hs.setAttribute("query",query);//设置查询的数据
            hs.setAttribute("dataNum",datainpage);//每页显示的数据条数，用于控制jsp中循环输出结果的条数
            hs.setAttribute("totalPage", pageNum);//一共有多少页
            hs.setAttribute("content", manList);//查询到的所有结果
            hs.setAttribute("pageNum", 1);//初始状态下的页码，从第一页开始
            hs.setAttribute("totalNum", dataNum);//存储一共有多少条数据
            request.getRequestDispatcher("/index2.jsp").include(request, response);
        }
    }
}
