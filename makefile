CC=gcc
OBJ=obj
BIN=bin

all: bin/runTests bin/runTime

obj/heap.o: src/heap.c src/heap.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} -c -o obj/heap.o src/heap.c
obj/testLib.o: src/testLib.c src/testLib.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} -c -o obj/testLib.o src/testLib.c
obj/timeLib.o: src/timeLib.c src/timeLib.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} -c -o obj/timeLib.o src/timeLib.c

bin/runTests: obj/heap.o obj/testLib.o src/runTests.c
	[ -d $(BIN) ] || mkdir -p $(BIN) 
	${CC} -o bin/runTests obj/heap.o obj/testLib.o src/runTests.c

bin/runTime: obj/heap.o obj/testLib.o obj/timeLib.o src/runTime.c
	[ -d $(BIN) ] || mkdir -p $(BIN) 
	${CC} -o bin/runTime obj/heap.o obj/testLib.o obj/timeLib.o src/runTime.c

test: bin/runTests
	bin/runTests
time: bin/runTime
	bin/runTime 17


clean:
	rm -f bin/runTests
	rm -f bin/runTime
	rm -f obj/heap.o
	rm -f obj/testLib.o
	rm -f obj/timeLib.o
	rm -f -d bin
	rm -f -d obj

