quesbank: exfile.o operate.o paper.o query.o quesbank.o
	gcc -o quesbank exfile.o operate.o paper.o query.o quesbank.o
exfile.o: quesbank.h exfile.c
	gcc -c -o exfile.o exfile.c
operate.o: quesbank.h operate.c
	gcc -c -o operate.o operate.c
paper.o: exfile.h quesbank.h paper.c
	gcc -c -o paper.o paper.c
query.o: quesbank.h query.c
	gcc -c -o query.o query.c
quesbank.o: quesbank.h exfile.h quesbank.c
	gcc -c -o quesbank.o quesbank.c

clean:
	rm *.o quesbank
