
	org 0
MM:
	mov r0,#1
	mov r1,#1
	mov r2,#1
	mov r3,#1
M0:

	mov a,#1
	mov r4,a
	mov a,#0
	mov r5,a
	mov a,#0
	mov r6,a
	mov a,#0
	mov r7,a
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
	jc MM
	mov  r2,a

	mov a,r6
	add a,r1
	mov r6,a

	mov a,r7
	add a,r0
	mov r7,a
	jmp M2
	

