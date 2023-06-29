/* 编写JAVA程序，实现接收用户输入的正整数，输出该数的阶乘
要求：限制输入的数据在1-10之间，无效数据进行提示，结束程序
输出结果如：4！=1*2*3*4=24 
*****************************************************
Copyright by : Peifeng Jiang && Yixing Ke ©All Rights Reserved 
Date: 2021.6.28
Version:1.0
*/
import java.util.*;
public class Factorial {
    public static void main(String[] args) {
        int  in,result  = 1, flag;
        Scanner input = new Scanner(System.in);
        do{
            System.out.println("请输入一个1-10之间的数");
            in = input.nextInt();
            result = in;
            if(in > 10 || in < 1){
                System.out.println("请输入合法数字");
                continue;
            }
            else{
                break;
            }
        } while(true);
        System.out.println("********************");
        System.out.print(in+"!="+in);
        for(int i = in - 1; i > 1; i--){
            System.out.print("*" + i);
            result = result * i;
        }
        System.out.print("*"+"1=" + result+"\n");
        System.out.println("********************");
    }  
} 