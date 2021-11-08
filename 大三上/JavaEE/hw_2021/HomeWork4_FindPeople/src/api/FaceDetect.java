package api;

import org.apache.http.client.methods.CloseableHttpResponse;
import org.json.JSONObject;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FaceDetect  {
    /**
     * 重要提示代码中所需工具类
     * FileUtil,Base64Util,HttpUtil,GsonUtils请从
     * https://ai.baidu.com/file/658A35ABAB2D404FBF903F64D47C1F72
     * https://ai.baidu.com/file/C8D81F3301E24D2892968F09AE1AD6E2
     * https://ai.baidu.com/file/544D677F5D4E4F17B4122FBD60DB82B3
     * https://ai.baidu.com/file/470B3ACCA3FE43788B5A963BF0B625F3
     * 下载
     */
    public static String detect(String filepath1, String filepath2) throws IOException {
        // 请求url
        String url = "https://aip.baidubce.com/rest/2.0/face/v3/match";
        String Filepath1 = filepath1;	//可以本地也可以网络上请求
        String Filepath2 = filepath2;

        String image1 = Base64Util.encode(FileUtil.readFileByBytes(Filepath1));
        String image2 = Base64Util.encode(FileUtil.readFileByBytes(Filepath2));
        try {
//            Map<String, Object> map = new HashMap<>();
//            //map.put对应参数的意思,看百度人脸检测开发文档
//            //https://cloud.baidu.com/doc/FACE/s/yk37c1u4t
//            map.put("image", image);
//            map.put("face_field", "faceshape,facetype,age,beauty");
//            map.put("image_type", "BASE64");
//            map.put("face_type", "LIVE");
//            map.put("quality_control", "LOW");
//            map.put("liveness_control", "NORMAL");
            List<Map<String, Object>> images = new ArrayList<Map<String, Object>>();

            Map<String, Object> map1 = new HashMap<String, Object>();
            map1.put("image", image1);
            map1.put("image_type", "BASE64");
            map1.put("face_type", "LIVE");
            map1.put("quality_control", "LOW");
            map1.put("liveness_control", "NORMAL");

            Map<String, Object> map2 = new HashMap<String, Object>();
            map2.put("image", image2);
            map2.put("image_type", "BASE64");
            map2.put("face_type", "LIVE");
            map2.put("quality_control", "LOW");
            map2.put("liveness_control", "NORMAL");
            images.add(map1);
            images.add(map2);


            String param = GsonUtils.toJson(images);

            // 注意这里仅为了简化编码每一次请求都去获取access_token，线上环境access_token有过期时间， 客户端可自行缓存，过期后重新获取。
            String accessToken = "24.2465c0fabe990ff02f7262ee1c42c459.2592000.1606094929.282335-22867462";

            String result = HttpUtil.post(url, accessToken, "application/json", param);
            System.out.println(result);
            return result;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public static String faceDetecttest(String filepath){

        String token = "24.2465c0fabe990ff02f7262ee1c42c459.2592000.1606094929.282335-22867462";

        String Filepath = filepath;
        String image1 = Base64ImageUtils.GetImageStrFromPath(Filepath);
        String url = "https://aip.baidubce.com/rest/2.0/face/v3/search?access_token="+token;


        Map<String, String> map = new HashMap<String, String>();
        map.put("image", image1);
        map.put("image_type", "BASE64");
        map.put("face_type", "LIVE");
        map.put("quality_control", "LOW");
        map.put("liveness_control", "NORMAL");
        map.put("match_threshold", "70");
        map.put("group_id_list","gropu001");

        Map<String, String> headers = new HashMap<String, String>();
        headers.put("Content-Type", "application/x-www-form-urlencoded");

//        Map<String, String> bodys = new HashMap<String, String>();
//        bodys.put("image", image);
//        bodys.put("image_type", "BASE64");
//        bodys.put("face_fields", "age,beauty,expression,gender,glasses,race,qualities");

        try {
            CloseableHttpResponse response =  HttpClientUtils.doHttpsPost(url,headers, map);
            String res = HttpClientUtils.toString(response);
            //System.out.println(res);
            return res;
        } catch (Exception e) {
            e.printStackTrace();
        }


        return token;
    }

}
