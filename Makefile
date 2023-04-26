all: helloworld add

helloworld: HelloWorld.c
	gcc HelloWorld.c -o HelloWorld.exe

add: Add.c
	gcc Add.c -o Add.exe

clean:
	rm -f *.o *.exe