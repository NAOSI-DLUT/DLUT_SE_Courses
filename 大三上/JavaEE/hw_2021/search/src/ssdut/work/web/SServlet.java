package ssdut.work.web;

import org.json.JSONObject;

import javax.websocket.*;
import javax.websocket.server.PathParam;
import javax.websocket.server.ServerEndpoint;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

@ServerEndpoint("/ws/{user}")
public class SServlet {
    private String currentUser;

    private static final Map<String, Session> sessionMap = new HashMap<>();

    //连接打开时执行
    @OnOpen
    public void onOpen(@PathParam("user") String user, Session session) {
        currentUser = user;
        sessionMap.put(user, session);
        System.out.println(user);
    }

    //收到消息时执行
    @OnMessage
    public String onMessage(String message, Session session) throws IOException {
//        System.out.println(currentUser + "：" + message);
        JSONObject json = new JSONObject(message);
        String msg = null;
        String msgTo = null;
        if(json.has("message")){
            msg = json.getString("message");
        }
        if(json.has("msgTo")){
            msgTo = json.getString("msgTo");
        }
        Session s = sessionMap.get(msgTo);
        if(s.isOpen()){
            s.getBasicRemote().sendText(currentUser+"说："+msg);
        }
        s = sessionMap.get(currentUser);
        if(s.isOpen()){
            s.getBasicRemote().sendText(currentUser+"说："+msg);
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

