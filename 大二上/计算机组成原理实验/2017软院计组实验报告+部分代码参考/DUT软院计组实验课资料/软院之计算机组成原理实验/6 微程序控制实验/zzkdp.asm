org 0
D0:
	mov r4,#1
	mov r5,#20h
	mov r6,#30h
	mov r7 ,#40h

	mov a,#0
	mov r0,a
	mov a,#10
	mov r1,a

D1:
	mov a,r5
	sub a,r1
	jc D2
	mov r5,a

	mov a,r6
	add  a,r4
	mov r6,a
	jmp D1
D2:
	mov a,r6
	sub a,r1
	jc D3
	mov r6,a

	mov a,r7
	add a,r4
	mov r7,a
	jmp D2
D3:
	mov a,r7
	sub a,r1
	jc P0
	mov r7,a

	mov a,r0
	add a,r4
	mov r7,a
	jmp D3
P0:
	mov a,r0
	sub a,r4
	jc P1

	mov a,r5
	sta 8002h
P01:
	jpb P01

	mov a,r6
	sta 8002h
P02:
	jpb P02

	mov  a,r7
	sta 8002h
P03:
	jpb P03

	mov a,r0
	sta 8002h
P04:
	jpb P04
	
	jmp D0

P1:
	mov a,r7
	sub a,r4
	jc P2

	mov a,r5
	sta  8002h
P11:
	jpb P11

	mov a,r6
	sta 8002h
P12:
	jpb P12

	mov  a,r7
	sta 8002h
P13:
	jpb P13

	jmp D0

P2:
	mov a,r6
	sub a,r4
	jc P3

	mov a,r5
	sta 8002h
P21:
	jpb  P21

	mov a,r6
	sta 8002h
P22:
	jpb P22

	jmp D0

P3:
	mov a,r5
	sta 8002h
P31:
	jpb P31

	jmp D0

 
