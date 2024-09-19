gcc -c consumer.c ipc.c
gcc consumer.o ipc.o -o consumer
gcc -c producer.c ipc.c
gcc producer.o ipc.o -o producer
