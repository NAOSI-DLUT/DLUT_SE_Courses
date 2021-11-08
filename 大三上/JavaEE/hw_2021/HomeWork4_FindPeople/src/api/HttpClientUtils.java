package api;

import org.apache.http.*;
import org.apache.http.client.config.AuthSchemes;
import org.apache.http.client.config.CookieSpecs;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.protocol.HttpClientContext;
import org.apache.http.config.Registry;
import org.apache.http.config.RegistryBuilder;
import org.apache.http.conn.socket.ConnectionSocketFactory;
import org.apache.http.conn.socket.PlainConnectionSocketFactory;
import org.apache.http.conn.ssl.NoopHostnameVerifier;
import org.apache.http.conn.ssl.SSLConnectionSocketFactory;
import org.apache.http.cookie.Cookie;
import org.apache.http.impl.client.*;
import org.apache.http.impl.conn.PoolingHttpClientConnectionManager;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.util.EntityUtils;
 
import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManager;
import javax.net.ssl.X509TrustManager;
import java.io.IOException;
import java.net.CookieStore;
import java.security.KeyManagementException;
import java.security.NoSuchAlgorithmException;
import java.security.cert.CertificateException;
import java.security.cert.X509Certificate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
 
/**
 * HttpClient4.5.X实现的工具类
 * 可以实现http和ssl的get/post请求
 */
public class HttpClientUtils{
    //创建HttpClientContext上下文
    private static HttpClientContext context = HttpClientContext.create();
 
    //请求配置
    private static RequestConfig requestConfig = RequestConfig.custom()
                    .setConnectTimeout(120000)
                    .setSocketTimeout(60000)
                    .setConnectionRequestTimeout(60000)
                    .setCookieSpec(CookieSpecs.STANDARD_STRICT)
                    .setExpectContinueEnabled(true)
                    .setTargetPreferredAuthSchemes(Arrays.asList(AuthSchemes.NTLM, AuthSchemes.DIGEST))
                    .setProxyPreferredAuthSchemes(Arrays.asList(AuthSchemes.BASIC)).build();
 
    //SSL的连接工厂
    private static SSLConnectionSocketFactory socketFactory = null;
 
    //信任管理器--用于ssl连接
    private static TrustManager manager = new X509TrustManager() {
 
 
        public void checkClientTrusted(X509Certificate[] x509Certificates, String s) throws CertificateException {
 
        }
 
        public void checkServerTrusted(X509Certificate[] x509Certificates, String s) throws CertificateException {
 
        }
 
        public X509Certificate[] getAcceptedIssuers() {
            return null;
        }
    };
 
    //ssl请求
    private static void enableSSL() {
        try {
            SSLContext sslContext = SSLContext.getInstance("TLS");
            sslContext.init(null, new TrustManager[]{manager}, null);
            socketFactory = new SSLConnectionSocketFactory(sslContext, NoopHostnameVerifier.INSTANCE);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        } catch (KeyManagementException e) {
            e.printStackTrace();
        }
    }
 
    /**
     * https get请求
     * @param url
     * @param data
     * @return
     * @throws IOException
     */
    public static CloseableHttpResponse doHttpsGet(String url, String data){
        enableSSL();
        Registry<ConnectionSocketFactory> socketFactoryRegistry = RegistryBuilder.<ConnectionSocketFactory>create()
                                                   .register("http", PlainConnectionSocketFactory.INSTANCE)
                                                   .register("https", socketFactory).build();
 
        PoolingHttpClientConnectionManager connectionManager = new PoolingHttpClientConnectionManager(socketFactoryRegistry);
 
        CloseableHttpClient httpClient = HttpClients.custom()
                                        .setConnectionManager(connectionManager)
                                        .setDefaultRequestConfig(requestConfig).build();
 
        HttpGet httpGet = new HttpGet(url);
 
        CloseableHttpResponse response = null;
 
        try {
            response = httpClient.execute(httpGet, context);
        }catch (Exception e){
            e.printStackTrace();
        }
 
        return response;
    }
 
    /**
     * https post请求 参数为名值对
     * @param url
     * @param headers
     * @param bodys
     * @return
     * @throws IOException
     */
    public static CloseableHttpResponse doHttpsPost(String url, Map<String, String> headers, Map<String, String> bodys) {
        enableSSL();
        Registry<ConnectionSocketFactory> socketFactoryRegistry = RegistryBuilder.<ConnectionSocketFactory>create()
                                                       .register("http", PlainConnectionSocketFactory.INSTANCE)
                                                       .register("https", socketFactory).build();
 
        PoolingHttpClientConnectionManager connectionManager = new PoolingHttpClientConnectionManager(socketFactoryRegistry);
 
        CloseableHttpClient httpClient = HttpClients.custom()
                                         .setConnectionManager(connectionManager)
                                         .setDefaultRequestConfig(requestConfig).build();
 
        HttpPost httpPost = new HttpPost(url);
 
        for (Map.Entry<String, String> e : headers.entrySet()) {
            httpPost.addHeader(e.getKey(), e.getValue());
        }
 
        if (bodys != null) {
            List<NameValuePair> nameValuePairList = new ArrayList<NameValuePair>();
            for (String key : bodys.keySet()) {
                nameValuePairList.add(new BasicNameValuePair(key, bodys.get(key)));
            }
            UrlEncodedFormEntity formEntity = new UrlEncodedFormEntity(nameValuePairList, Consts.UTF_8);
            formEntity.setContentType("application/x-www-form-urlencoded; charset=UTF-8");
            httpPost.setEntity(formEntity);
        }
 
        CloseableHttpResponse response = null;
        try {
            response = httpClient.execute(httpPost, context);
        }catch (Exception e){}
        return response;
    }
    /**
     * https post请求 参数为名值对
     * @param url
     * @param values
     * @return
     * @throws IOException
     */
    public static CloseableHttpResponse doHttpsPost(String url, List<NameValuePair> values) {
        enableSSL();
        Registry<ConnectionSocketFactory> socketFactoryRegistry = RegistryBuilder.<ConnectionSocketFactory>create()
                                                       .register("http", PlainConnectionSocketFactory.INSTANCE)
                                                       .register("https", socketFactory).build();
 
        PoolingHttpClientConnectionManager connectionManager = new PoolingHttpClientConnectionManager(socketFactoryRegistry);
 
        CloseableHttpClient httpClient = HttpClients.custom()
                                         .setConnectionManager(connectionManager)
                                         .setDefaultRequestConfig(requestConfig).build();
 
        HttpPost httpPost = new HttpPost(url);
 
        UrlEncodedFormEntity entity = new UrlEncodedFormEntity(values, Consts.UTF_8);
 
        httpPost.setEntity(entity);
 
        CloseableHttpResponse response = null;
        try {
            response = httpClient.execute(httpPost, context);
        }catch (Exception e){}
        return response;
    }
 
    /**
     * http get
     * @param url
     * @param data
     * @return
     */
    public static CloseableHttpResponse doGet(String url, String data) {
 
        java.net.CookieStore cookieStore = (CookieStore) new BasicCookieStore();
 
        CloseableHttpClient httpClient = HttpClientBuilder.create()
                            .setKeepAliveStrategy(new DefaultConnectionKeepAliveStrategy())
                            .setRedirectStrategy(new DefaultRedirectStrategy())
                            .setDefaultCookieStore((org.apache.http.client.CookieStore) cookieStore)
                            .setDefaultRequestConfig(requestConfig).build();
 
        HttpGet httpGet = new HttpGet(url);
 
        CloseableHttpResponse response = null;
 
        try {
            response = httpClient.execute(httpGet, context);
        }catch (Exception e){}
        return response;
    }
 
    /**
     * http post
     *
     * @param url
     * @param values
     * @return
     */
    public static CloseableHttpResponse doPost(String url, List<NameValuePair> values) {
        CookieStore cookieStore = (CookieStore) new BasicCookieStore();
        CloseableHttpClient httpClient = HttpClientBuilder.create()
                            .setKeepAliveStrategy(new DefaultConnectionKeepAliveStrategy())
                            .setRedirectStrategy(new DefaultRedirectStrategy())
                            .setDefaultCookieStore((org.apache.http.client.CookieStore) cookieStore)
                            .setDefaultRequestConfig(requestConfig).build();
 
        HttpPost httpPost = new HttpPost(url);
 
        UrlEncodedFormEntity entity = new UrlEncodedFormEntity(values, Consts.UTF_8);
 
        httpPost.setEntity(entity);
 
        CloseableHttpResponse response = null;
        try {
            response = httpClient.execute(httpPost, context);
        }catch (Exception e){}
        return response;
    }
 
 
    /**
     * 直接把Response内的Entity内容转换成String
     *
     * @param httpResponse
     * @return
     */
    public static String toString(CloseableHttpResponse httpResponse) {
        // 获取响应消息实体
        String result = null;
        try {
            HttpEntity entity = httpResponse.getEntity();
            if (entity != null) {
                result = EntityUtils.toString(entity,"UTF-8");
            }
        }catch (Exception e){}finally {
            try {
                httpResponse.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return result;
    }
 
 
 
    public static void main(String[] args){
       //使用其测试百度云API---获取token
       //url: http://console.bce.baidu.com/ai
 
        String APPID ="10201425"; //管理中心获得
 
        //百度人脸识别应用apikey
        String API_KEY = "WVsGWvDxyn55hW8P0UR8shbo"; //管理中心获得
 
        //百度人脸识别应用sercetkey
        String SERCET_KEY = "z0uSr16LGyTNIMRRnP6f8jCLMLXAYkIj"; //管理中心获得
 
        //百度人脸识别token 有效期一个月
        String TOKEN = null;
 
 
        String access_token_url = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials"
                                   +"&client_id="+API_KEY +"&client_secret="+SERCET_KEY;
 
        CloseableHttpResponse response =  HttpClientUtils.doHttpsGet(access_token_url,null);
 
        System.out.println(HttpClientUtils.toString(response));
 
 
        //得到token = 24.1d786b9cdbdd8ac7cf55d56c7f38372b.2592000.1509244497.282335-10201425
 
 
    }
 
 
 
 
 
 
 
}
 
