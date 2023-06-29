import java.io.File;
import java.io.IOException;
import java.sql.Date;
import java.text.SimpleDateFormat;

/**
 * 常见的File类方法
 * @author 姜沛峰
 */


public class FileMethod
{
    public static void main(String[] args) 
    {
        // 1. 查看文件属性
        File f1 = new File("/Users/jiangpeifeng/java","hello.txt");
        System.out.println("文件名："+f1.getName());
        System.out.println("路径: "+f1.getPath());
        System.out.println("绝对路径: "+f1.getAbsolutePath());
        System.out.println(f1.exists()? "文件存在" : "文件不存在");
        System.out.println(f1.isDirectory()? "是目录":"不是目录");
        if (f1.canRead()) {
            System.out.println("可以读取文件");
        }else
        {
            System.out.println("不可以读取文件");
        }
        if (f1.canWrite()) {
            System.out.println("可以写文件");
        }else{
            System.out.println("不可以写文件");
        }
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
        Date date = new Date(f1.lastModified());
        System.out.println("该文件最后一次修改时间是： "+sdf.format(date));

        // 2. 操作文件
        FileMethod fm = new FileMethod();
        File f2 = new File("/Users/jiangpeifeng/java/test.txt");
        
        try {
            fm.createFile(f2);
        } catch (Exception e) {
            //TODO: handle exception
            e.printStackTrace();
        }
        try {
            fm.deleteFile(f2);
        } catch (Exception e) {
            //TODO: handle exception
            e.printStackTrace();
        }
        File dir = new File("/Users/jiangpeifeng/java");
        fm.listDir(dir);
    }
    // 创建文件, 不能保证成功
    public void createFile(File file) throws IOException
    {
        if (!file.exists()) {
            file.createNewFile();
            System.out.print("创建文件成功！");
        }
    }

    // 删除文件
    public void deleteFile(File file) throws IOException
     {
        if(file.exists())
        {
            file.delete();
            System.out.print("删除文件成功！");
        }
     }
    // 查看目录信息
    public void listDir(File dir) {
        File [] list =  dir.listFiles();
        // 打印目录下所有的子目录和文件
        String info = "当前目录为：" + dir.getName();
        for (int i = 0; i < list.length; i++) 
        {
            info += list[i].getName()+"//";
        }
        System.out.print(info);
    }
    
}