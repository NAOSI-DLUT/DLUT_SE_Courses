head = dask.h
srcs = dask.cpp
objs = dask.o
opts = -w -g -c
all: dask
dask: $(objs)
	g++ $(objs) -o dask
dask.o: $(srcs) $(head)
	g++ $(opts) $(srcs)
clean:
	rm dask *.o