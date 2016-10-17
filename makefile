musicTest: myTunez.c
	gcc myTunez.c -g -o musicTest

run: musicTest
	./musicTest

clean:
	rm *~	
