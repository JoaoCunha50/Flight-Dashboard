CC = gcc
CFLAGS= -Wall -Iincludes -g -Ipath/to/glib/include `pkg-config --cflags glib-2.0`
LDFLAGS= `pkg-config --libs glib-2.0` -lm

all: main test

main: src/main.o src/batch.o src/interactive.o src/statistics.o  src/files.o src/query1.o src/query2.o src/query3.o src/query4.o src/query5.o src/query6.o src/query7.o src/query8.o src/query9.o src/interpreter.o src/parser.o src/passengers.o src/reservations.o src/flights.o src/users.o src/schedules.o
	$(CC) $^ $(LDFLAGS) $(CFLAGS) -o programa-principal

test: src/tests.o src/statistics.o  src/files.o src/query1.o src/query2.o src/query3.o src/query4.o src/query5.o src/query6.o src/query7.o src/query8.o src/query9.o src/interpreter.o src/parser.o src/passengers.o src/reservations.o src/flights.o src/users.o src/schedules.o
	$(CC) $^ $(LDFLAGS) $(CFLAGS) -o programa-testes

src/main.o : src/main.c
src/batch.o : src/batch.c
src/statistics.o : src/statistics.c
src/files.o : src/files.c
src/query1.o : src/query1.c
src/query2.o : src/query2.c
src/query3.o : src/query3.c
src/query4.o : src/query4.c
src/query5.o : src/query5.c
src/query6.o : src/query6.c
src/query7.o : src/query7.c
src/query8.o : src/query8.c
src/query9.o : src/query9.c
src/interpreter.o : src/interpreter.c
src/parser.o : src/parser.c
src/passengers.o : src/passengers.c
src/reservations.o : src/reservations.c
src/flights.o : src/flights.c
src/schedules.o : src/schedules.c
src/users.o : src/users.c
src/interactive.o : src/interactive.c
src/tests.o : src/tests.c

clean:
	rm -f programa-principal programa-testes src/*.o 
	rm -r Resultados ErrosTestes
