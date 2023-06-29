include ../Make.defines

PROGS =	client server

all:	${PROGS}

client:	client.o
		${CC} ${CFLAGS} -o $@ client.o ${LIBS}

server:	server.o
		${CC} ${CFLAGS} -o $@ server.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}