
import java.io.*;
public class ReadAndWriteBinaryDemo
{
    public static void main(String[] args) 
    {
        DataInputStream dis = null;
        DataOutputStream dos = null;
        FileInputStream fis = null;
        FileOutputStream fos = null;

        try 
        {
            fis = new FileInputStream("/Users/jiangpeifeng/java/File/DLUT.jpg");
            dis = new DataInputStream(fis);
            fos = new FileOutputStream("/Users/jiangpeifeng/java/File/newPic/DLUT.jpg");
            dos = new DataOutputStream(fos);

            int temp;
            while ((temp = dis.read())!=-1) 
            {
                dos.write(temp);
            }
            System.out.println("读写二进制文件成功！");
        } 
        catch (FileNotFoundException e) 
        {
            //TODO: handle exception
            e.printStackTrace();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
        finally
        {
            try 
            {
                if (dis != null) {
                    dis.close();
                }   
                if (dos != null) {
                    dos.close();
                } 
                if (fos != null) {
                    fos.close();
                }
                if (fis != null) {
                    fis.close();
                }
            } catch (IOException e) {
                //TODO: handle exception
                e.printStackTrace();
            }
        }
    }
}
