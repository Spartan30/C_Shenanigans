all: helloworld add rps

helloworld: HelloWorld.c
	gcc -std=c11 HelloWorld.c -o HelloWorld.exe

add: Add.c
	gcc -std=c11 Add.c -o Add.exe

rps: RPS.c
	gcc -std=c11 RPS.c -o RPS.exe

clean:
	rm -f *.o *.exe