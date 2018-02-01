maze: maze.o fdispose.o init.o search.o show.o
	gcc -o maze maze.o fdispose.o init.o search.o show.o
maze.o: fdispose.h init.h maze.h search.h show.h maze.c
	gcc -c -o maze.o maze.c
fdispose.o: maze.h fdispose.c
	gcc -c -o fdispose.o fdispose.c
init.o: maze.h init.c
	gcc -c -o init.o init.c
search.o: maze.h show.h search.c
	gcc -c -o search.o search.c
show.o: maze.h show.c
	gcc -c -o show.o show.c

clean:
	rm *.o maze 
