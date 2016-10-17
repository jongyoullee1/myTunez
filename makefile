musicTest: songList.c
	gcc songList.c -g -o musicTest

run: musicTest
	./musicTest

clean:
	rm *~	
