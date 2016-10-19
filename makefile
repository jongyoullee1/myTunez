musicTest: main.c
	gcc main.c songList.c musicLibrary.c -g -o myTunezTest

run: myTunezTest
	./myTunezTest

clean:
	rm *~
