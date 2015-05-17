tele:telemain.o datadispose.o filedispose.o timehold.o
	gcc -o tele telemain.o datadispose.o filedispose.o timehold.o

telemain.o:telemain.h datadispose.h filedispose.h timehold.h telemain.c
	gcc -c -o telemain.o telemain.c

datadispose.o:telemain.h timehold.h datadispose.c
	gcc -c -o datadispose.o datadispose.c

filedispose.o:telemain.h filedispose.c
	gcc -c -o filedispose.o filedispose.c

timehold.o:timehold.h timehold.c
	gcc -c -o timehold.o timehold.c

clean:
	rm -f tele telemain.o datadispose.o filedispose.o timehold.o
