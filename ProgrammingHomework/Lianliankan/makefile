Lianliankan:llkan.o create.o judge.o play.o show.o
	gcc -o Lianliankan llkan.o create.o judge.o play.o show.o
llkan.o:show.h llkan.h create.h play.h llkan.c
	gcc -c -o llkan.o llkan.c
create.o: llkan.h create.c
	gcc -c -o create.o create.c
judge.o: judge.c llkan.h
	gcc -c -o judge.o judge.c
play.o: play.c llkan.h show.h judge.h
	gcc -c -o play.o play.c
show.o: show.c llkan.h
	gcc -c -o show.o show.c

clean:
	rm -f *.o Lianliankan
