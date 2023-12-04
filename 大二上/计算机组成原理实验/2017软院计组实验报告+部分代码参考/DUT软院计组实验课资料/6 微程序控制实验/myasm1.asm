                         ORG	0                 ;  伪指令—用来指出文件在内存中存放的起始位置
STRT:
	            JKB	 STRT
                          LDA 	8001H    
                         MOV	R7,A           ;   输入第一操作数给R7         
L1:
	            JKB	L1           
                          LDA	8001H
                         MOV	R6,A            ;  输入第二操作数给R6 

                         MOV	A,#0
                         STA	8002H            
L2:
	            JPB	L2                 ;  打印+ 
                         MOV	A,#0AH
                         STA	8002H             
L3:
	            JPB	L3                    ;打印空格
                         MOV	A,#10H
                         ADD	A,R7    
                         STA	8002H
L4:
	            JPB	L4                   ;打印第一操作数后回车换行
      
                         MOV	A,#9
                          STA	8002H
L5:
	            JPB	L5                               ;      打印= 
                         MOV	A,#0AH
                         STA	8002H
L6:
                         JPB	L6                                   ;  打印空格
                         MOV	A,#10H
                         ADD	A,R6
                         STA	8002H
L7:	
                         JPB	L7                                   ; 打印第二操作数后回车换行
                         MOV	A,#3
                         STA	8002H
L8:
                        JPB	L8                                    ; 打印菱型符号 
                        MOV	A,#0AH
                       STA	8002H
L9:

                                 JPB	L9                                    ;  打印空格
                       MOV	A,R6
                       ADD	A,R7
                       MOV	R0,#10
                       SUB	A,R0                                 ;  将两数相加，再进行减10处理
                       JC	OVER                                 ;判断结果是否大于10，是—跳转到OVER，否—顺序执行
                       STA	8002H
L10:	
                 JPB 	L10                ;打印个位
                 MOV	A,#11H
OUT:	
                 STA	8002H
L11:	
                JPB	 L11               ; 打印十位
                JMP	STRT
OVER:	
                 ADD A,R0
                MOV	 R1,#10H
                ADD	A,R1
                JMP	OUT                ;恢复运算结果，跳转到打印个位