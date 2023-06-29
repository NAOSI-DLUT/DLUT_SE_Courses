import java.io.FileInputStream;
import java.io.IOException;

public class FileInputStreamDemo {
    public static void main(String[] args) throws IOException
    {
        FileInputStream fis = new FileInputStream("/Users/jiangpeifeng/java/hello.txt");
        int data;
        System.out.println("可读取的字节数: "+ fis.available());
        System.out.print("文件内容为：");
        while ((data = fis.read())!= -1) 
        {
            System.out.print((char)data + " ");
        }
        fis.close();
    }
}
