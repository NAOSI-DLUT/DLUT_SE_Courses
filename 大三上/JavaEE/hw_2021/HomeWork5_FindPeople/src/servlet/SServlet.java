package servlet;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

import javax.servlet.http.HttpSession;
import javax.websocket.CloseReason;
import javax.websocket.OnClose;
import javax.websocket.OnError;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
import javax.websocket.Session;
import javax.websocket.server.PathParam;
import javax.websocket.server.ServerEndpoint;

@ServerEndpoint("/ws/{user}")
public class SServlet {
    private String currentUser;

    private static Set<Session> sessions = new HashSet<>();

    //连接打开时执行
    @OnOpen
    public void onOpen(@PathParam("user") String user, Session session) {
        currentUser = user;
        System.out.println("Connected ... " + session.getId());
        sessions.add(session);
        List<String> online =  new ArrayList<>();
        online.add(user);
        HashMap<String,ArrayList<String>> hs = new HashMap<>();
        hs.put("ol", (ArrayList<String>) online);

        System.out.println(user);
    }

    //收到消息时执行
    @OnMessage
    public String onMessage(String message, Session session) throws IOException {
        System.out.println(currentUser + "：" + message);
        //发送给所有人
        for (Session s : sessions) {
            if (s.isOpen()) {
                s.getBasicRemote().sendText(currentUser+"说:"+message);
            }
        }
        return null;
    }

    //连接关闭时执行
    @OnClose
    public void onClose(Session session, CloseReason closeReason) {
        System.out.println(String.format("Session %s closed because of %s", session.getId(), closeReason));
    }

    //连接错误时执行
    @OnError
    public void onError(Throwable t) {
        t.printStackTrace();
    }
}