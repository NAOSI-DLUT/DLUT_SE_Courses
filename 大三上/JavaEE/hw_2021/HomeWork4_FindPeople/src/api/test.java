package api;

import org.json.JSONObject;

import java.io.IOException;

/**
 * @author:dzc
 * @date2020-10-24 10:59
 */


public class test {
    public static void main(String[] args) throws IOException {
//        String path = "E:\\dzc_workingplace\\学习资料\\大三上\\J2EE\\javaEE\\4\\classes\\artifacts\\4_war_exploded\\image\\201892478.jpg";
//        String res = FaceDetect.faceDetecttest(path);
//        System.out.println(res);
        String path1 = "E:\\dzc_workingplace\\学习资料\\大三上\\J2EE\\javaEE\\4\\classes\\artifacts\\4_war_exploded\\image\\201892001.jpg";
        String path2 = "E:\\dzc_workingplace\\学习资料\\大三上\\J2EE\\javaEE\\4\\classes\\artifacts\\4_war_exploded\\image\\201892478.jpg";
        String res = FaceDetect.faceDetecttest(path1);
        //System.out.println(res);
        if(res.contains("SUCCESS")) {
            System.out.println("查有此人！");
        }else{
            System.out.println("查无此人！");
        }
    }
}
