/*6_9
 编程计算汽车的平均速度 */
#include<stdio.h>

int main()
{     
	 int iStartPost,iEndPost;
	 int iStartHour, iStarMinute, iStarSecond ;
	 int iEndHour, iEndMinute, iEndSecond ;
	 int iElapsedTS,iElapsedHour,iElapsedMinute,iElapsedSecond ;
	 double dElapsedTime,dVelocity;

	 printf( "所有输入数据为整数\n" 
			 "开始里程？\n");     
   scanf("%d",&iStartPost) ;
   printf( "开始时间（时，分，秒）？\n") ;     
   scanf("%d:%d:%d",&iStartHour,&iStarMinute ,&iStarSecond );
     
	 printf( "结束里程？\n" );
     scanf("%d",&iEndPost);
     printf("结束时间（时，分，秒）？\n") ;   
	 scanf("%d:%d:%d",&iEndHour,&iEndMinute ,&iEndSecond) ;
    
	 /*计算行驶时间（秒）*/
	iElapsedTS = ( iEndHour * 3600 + iEndMinute * 60 + iEndSecond )
		 - ( iStartHour * 3600 + iStarMinute * 60 + iStarSecond ) ;
	/*转换成小时/分钟/秒*/ 
	iElapsedHour = iElapsedTS / 3600 ;
	iElapsedMinute = iElapsedTS % 3600 / 60 ;
	iElapsedSecond = iElapsedTS % 60 ;
    /* 转换成小时(小数)*/
	dElapsedTime = iElapsedHour + iElapsedMinute / 60.0 
		               + iElapsedSecond / 3600.0 ;
	/*计算平均速度（公里/小时）*/  
	dVelocity = (iEndPost - iStartPost) / dElapsedTime ;

   	printf( "汽车行驶了%d公里\n" ,iEndPost - iStartPost);
    printf( "消耗时间%d小时%d分%d秒,平均速度:%f公里/小时\n " ,
		     iElapsedHour,iElapsedMinute ,iElapsedSecond,dVelocity);

	return 0;
}

