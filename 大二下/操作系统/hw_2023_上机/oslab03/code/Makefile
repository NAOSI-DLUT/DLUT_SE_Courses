srcs=ppipe.c
objs=ppipe.o
opts=-g -c
all:ppipe
ppipe: $(objs)
	gcc $(objs) -o ppipe
ppipe.o: $(srcs)
	gcc $(opts) $(srcs)
clean:
	rm ppipe *.o