org 0
start:
in0:
            jkb in0
            lda 8001h
            mov r0,a

in1:
	jkb in1
	lda 8001h
	mov r1,a
in2:
	jkb in2
	lda 8001h
	mov r2,a
in3:
	jkb in3
	lda 8001h
	mov r3,a

print:
	mov a,#0ah
	sta 8002h
lp1:
	jpb lp1
	
	sta 8002h
lp2:
	jpb lp2
	mov a,r1
	sta 8002h
lp3:
	jpb lp3
	mov a,#10h
	add a,r0
	sta 8002h
lp4:
	jpb lp4
	mov a,#9
	sta 8002h
lp11:
	jpb lp11
	mov a,#0ah
	sta 8002h
lp22:
	jpb lp22
	mov a,r3
	sta 8002h
lp33:
	jpb lp33
	mov a,#10h
	add a,r2
	sta 8002h
lp44:
	jpb lp44
	mov a,#9h
	sta 8002h
lpp5:
	jpb lpp5
	mov a,#0ah
	sta 8002h
lpp6:
	jpb lpp6
M0:

	mov r4,#1
	
	mov r5,#0
	
	mov r6,#0
	
	mov r7,#0
	
M1:
	mov a,r3
	sub a,r4
	jc M2
	mov r3,a

	mov a,r5
	add a,r1
	mov r5,a

	mov a,r6
	add  a,r0
	mov r6,a
	jmp M1
M2:
	mov a,r2
	sub a,r4
	jc D0
	mov  r2,a

	mov a,r6
	add a,r1
	mov r6,a

	mov a,r7
	add a,r0
	mov r7,a
	jmp M2
D0:
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
	mov r0,a
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

	mov a,#10h
	add a,r0
	sta 8002h
P04:
	jpb P04
	
	jmp start

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

	mov  a,#10h
	add a,r7
	sta 8002h
P13:
	jpb P13

	jmp start

P2:
	mov a,r6
	sub a,r4
	jc P3

	mov a,r5
	sta 8002h
P21:
	jpb  P21

	mov a,#10h
	add a,r6
	sta 8002h
P22:
	jpb P22

	jmp start

P3:
	mov a,#10h
	add a,r5
	sta 8002h
P31:
	jpb P31

	jmp  start


	





