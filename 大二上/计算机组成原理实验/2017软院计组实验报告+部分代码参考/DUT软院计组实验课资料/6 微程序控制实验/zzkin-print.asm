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
	mov a,#4
	sta 8002h
p1:
	jpb p1
	mov a,#0ah
	sta 8002h
p2:
	jpb p2
	mov a,r1
	sta 8002h
p3:
	jpb p3
	mov a,#10h
	add a,r0
	sta 8002h
p4:
	jpb p4
	mov a,#9
	sta 8002h
p11:
	jpb p11
	mov a,#0ah
	sta 8002h
p22:
	jpb p22
	mov a,r3
	sta 8002h
p33:
	jpb p33
	mov a,#10h
	add a,r2
	sta 8002h
p44:
	jpb p44
	mov a,#0ah
	sta 8002h
pp5:
	jpb pp5
	sta 8002h
pp6:
	jpb pp6

	





