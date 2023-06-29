import java.io.FileWriter;

import java.io.*;
public class BufferWriterDemo {
    public static void main(String[] args) {
        try {
            // 计数器变量，用来代表行数
            int counter = 1;

            // 创建一个FileWriter对象fw, 它的参数设置为那个要写入的文件
            FileWriter fw = new FileWriter("/Users/jiangpeifeng/java/File/writeme.txt");
            BufferedWriter bw = new BufferedWriter(fw);

            // 创建一个FileReader对象fr, 它的参数设置为那个要读出的文件
            FileReader fr = new FileReader("/Users/jiangpeifeng/java/File/readme.txt");
            BufferedReader br = new BufferedReader(fr);

            // 创建一个String对象用来容纳fr读出的每一行
            String line = br.readLine();

            // 只要读出文件的下一行不是空（文件没有结束) 就讲fr读出的那一行写入fw所指向的文件的那一行，并且在行首标注行号
            while (line != null) 
            {
                // 写引用标注行号
                bw.write("第"+counter+"行:"+line);

                // 写引用换行
                bw.newLine();

                // 更新写引用所指向的文件
                bw.flush();

                // 读引用换行
                line = br.readLine();

                // 行号自增
                counter++;
            }

            // 关闭Buffer写流
            bw.close();

            // 关闭File写流
            fw.close();

            // 关闭Buffer读流
            br.close();

            // 关闭File读流
            fr.close();
            
        } catch (IOException e) {
            //TODO: handle exception
            System.out.print("文件读取出错！");
        }
    }
}
