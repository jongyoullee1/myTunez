musicTest: main.c
	gcc main.c songList.c -g -o musicTest

run: musicTest
	./musicTest

clean:
	rm *~	
