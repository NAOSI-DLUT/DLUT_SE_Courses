                         ORG	0                 ;  αָ�����ָ���ļ����ڴ��д�ŵ���ʼλ��
STRT:
	            JKB	 STRT
                          LDA 	8001H    
                         MOV	R7,A           ;   �����һ��������R7         
L1:
	            JKB	L1           
                          LDA	8001H
                         MOV	R6,A            ;  ����ڶ���������R6 

                         MOV	A,#0
                         STA	8002H            
L2:
	            JPB	L2                 ;  ��ӡ+ 
                         MOV	A,#0AH
                         STA	8002H             
L3:
	            JPB	L3                    ;��ӡ�ո�
                         MOV	A,#10H
                         ADD	A,R7    
                         STA	8002H
L4:
	            JPB	L4                   ;��ӡ��һ��������س�����
      
                         MOV	A,#9
                          STA	8002H
L5:
	            JPB	L5                               ;      ��ӡ= 
                         MOV	A,#0AH
                         STA	8002H
L6:
                         JPB	L6                                   ;  ��ӡ�ո�
                         MOV	A,#10H
                         ADD	A,R6
                         STA	8002H
L7:	
                         JPB	L7                                   ; ��ӡ�ڶ���������س�����
                         MOV	A,#3
                         STA	8002H
L8:
                        JPB	L8                                    ; ��ӡ���ͷ��� 
                        MOV	A,#0AH
                       STA	8002H
L9:

                                 JPB	L9                                    ;  ��ӡ�ո�
                       MOV	A,R6
                       ADD	A,R7
                       MOV	R0,#10
                       SUB	A,R0                                 ;  ��������ӣ��ٽ��м�10����
                       JC	OVER                                 ;�жϽ���Ƿ����10���ǡ���ת��OVER����˳��ִ��
                       STA	8002H
L10:	
                 JPB 	L10                ;��ӡ��λ
                 MOV	A,#11H
OUT:	
                 STA	8002H
L11:	
                JPB	 L11               ; ��ӡʮλ
                JMP	STRT
OVER:	
                 ADD A,R0
                MOV	 R1,#10H
                ADD	A,R1
                JMP	OUT                ;�ָ�����������ת����ӡ��λ