all: helloworld add rps

helloworld: HelloWorld.c
	gcc HelloWorld.c -o HelloWorld.exe

add: Add.c
	gcc Add.c -o Add.exe

rps: RPS.c
	gcc RPS.c -o RPS.exe

clean:
	rm -f *.o *.exe