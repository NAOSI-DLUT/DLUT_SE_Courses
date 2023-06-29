import java.io.*;
import java.io.FileOutputStream;
public class FileOutputStreamDemo 
{
    public static void main(String[] args) 
    {
        try {
            String str = "好好学习，天天向上！";
            byte[] words = str.getBytes();
            FileOutputStream fos = new FileOutputStream("/Users/jiangpeifeng/java/hello.txt",true);
            fos.write(words, 0 , words.length);
            System.out.println("hello文件已经更新");
            fos.close();
        } catch (IOException e) {
            //TODO: handle exception
            System.out.println("更新文件出错");
        }
    }
}