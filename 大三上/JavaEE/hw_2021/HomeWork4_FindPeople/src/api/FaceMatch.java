package api;

import com.baidu.aip.face.AipFace;
import org.json.JSONObject;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FaceMatch {

//    /**
//    * 重要提示代码中所需工具类
//    * FileUtil,Base64Util,HttpUtil,GsonUtils请从
//    * https://ai.baidu.com/file/658A35ABAB2D404FBF903F64D47C1F72
//    * https://ai.baidu.com/file/C8D81F3301E24D2892968F09AE1AD6E2
//    * https://ai.baidu.com/file/544D677F5D4E4F17B4122FBD60DB82B3
//    * https://ai.baidu.com/file/470B3ACCA3FE43788B5A963BF0B625F3
//    * 下载
//    */
//	[
//	    {
//	        "image": "sfasq35sadvsvqwr5q...",
//	        "image_type": "BASE64",
//	        "face_type": "LIVE",
//	        "quality_control": "LOW",
//	        "liveness_control": "HIGH"
//	    },
//	    {
//	        "image": "sfasq35sadvsvqwr5q...",
//	        "image_type": "BASE64",
//	        "face_type": "IDCARD",
//	        "quality_control": "LOW",
//	        "liveness_control": "HIGH"
//	    }
//	]
//    public static String faceMatch(String param,String accessToken) {
//        // 请求url
//        String url = "https://aip.baidubce.com/rest/2.0/face/v3/match";
//        try {
//            String param = GsonUtils.toJson(map);
//            System.out.println("param="+param);
////            // 注意这里仅为了简化编码每一次请求都去获取access_token，线上环境access_token有过期时间， 客户端可自行缓存，过期后重新获取。
////            String result = HttpUtil.post(url, accessToken, "application/json", param);
//            System.out.println(result);
//            return result;
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
//        return null;
//    }
	

	public static final String accessToken = "需要自己在百度AI平台申请对应类型的";
	public static final Double  SCORE= 80.00;
	public static String checkErrorMessage(String code) {
		switch(code) {
		case "0":
			return "成功";
			
		case "223113":
			return "人脸被遮挡";
			
		case "223114":
			return "人脸模糊";
			
		case "223115":
			return "人脸光照不好";
			
		case "223116":
			return "人脸不完整";
			
		case "223120":
			return "活体检测未通过";
			
		case "223121":
			return "请勿遮挡左眼";
			
		case "223122":
			return "请勿遮挡右眼";
			
		case "223123":
			return "请勿遮挡左脸";
			
		case "223124":
			return "请勿遮挡右脸";
			
		case "223125":
			return "请勿遮挡下巴";
			
		case "223126":
			return "请勿遮挡鼻子";
			
		case "223127":
			return "请勿遮挡嘴巴";
			
			default:
				return "其他错误类型，请向管理员反馈";
			
		}
	}

	public static void search(String path) throws IOException {
		AipFace client = new AipFace("22867462","11ApLitx8vKhOCVAhGAfSIUR","m8KMdimi5Xz0G3S2r43SofY5GG4USYnv");
		client.setConnectionTimeoutInMillis(2000);
		client.setSocketTimeoutInMillis(60000);

		byte[] bytes = FileUtil.readFileByBytes(path);


//
//		Map<String,Object> map = new HashMap<>();
//
//		HashMap<String, String> options = new HashMap<>();
//		options.put("match_threshold", "70");
//		JSONObject jsonObject = aipFace.search(image,"BASE64","person",options);;
//		if(jsonObject.get("result").equals(null)){
//			map.put("message",jsonObject.getString("error_msg"));
//			System.out.println("查无此人");
//		}else{
//			System.out.println(jsonObject);
//			JSONObject result = (JSONObject) jsonObject.get("result");
//			JSONObject user = (JSONObject) result.getJSONArray("user_list").get(0);
//			String id =user.getString("user_id");
//			System.out.println(result);
//			//return ResponseEntity.status(200).body(SearchResponseVo.fromList(searchService.findPerson("id",id)));
//
//		}
		HashMap<String, String> options = new HashMap<String, String>();
		options.put("max_face_num", "3");
		options.put("match_threshold", "70");
		options.put("quality_control", "NORMAL");
		options.put("liveness_control", "LOW");
		options.put("user_id", "233451");
		options.put("max_user_num", "3");


		String image = java.util.Base64.getEncoder().encodeToString(bytes);
		String imageType = "BASE64";
		String groupIdList = "3,2";

		// 人脸搜索
		JSONObject res = client.search(image, imageType, groupIdList, options);
		System.out.println(res.toString(2));
	}

	public static String match(String image1,String image2) {


		// 请求url
		String url = "https://aip.baidubce.com/rest/2.0/face/v3/match";
		try {

//			byte[] bytes1 = FileUtil.readFileByBytes("D:\\images\\22.jpg");
//			byte[] bytes2 = FileUtil.readFileByBytes("D:\\images\\33.jpg");
//			byte[] bytes2 = Base64Util.encode(FileUtil.readFileByBytes("D:\\images\\33.jpg"));
//			String image1 = Base64Util.encode(bytes1);
//			String image2 = Base64Util.encode(bytes2);

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

			String result = HttpUtil.post(url, accessToken, "application/json", param);
			return result;
		} catch (Exception e) {
			e.printStackTrace();
		}
		return null;
	}

//	public static void main(String[] args) {
//		FaceMatch.match();
//	}
}
