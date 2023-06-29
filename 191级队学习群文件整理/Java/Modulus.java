/*
*****************************************************************
 *Description:编写JAVA程序，实现输出1--100之间所有不能被7整除的数，并求和
 *要求：每输出4个数据换行显示
 *****************************************************************
 *Copyright by : Peifeng Jiang && Yixing Ke ©All Rights Reserved 
 *Date: 2021.6.28
 *Version:1.0
 *****************************************************************
 *  */  
public class Modulus {
    public static void main(String[] args) {
        int sum = 0, mod, counter = -1; 
        System.out.print("输出不能被7整除的数：");
        for(int i = 0; i <= 100; i++){
            
            if(i % 7 != 0){
                sum = sum + i;
                counter++;
                if(counter%4 == 0)
                {
                    System.out.println(" ");
                    System.out.print("第"+(counter/4+1)+"行：");
                }
                System.out.print(i+ " ");
            }
        }
        System.out.println("\nsum="+sum);
    }
    
}
