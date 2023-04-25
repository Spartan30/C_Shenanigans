all: helloworld

helloworld: HelloWorld.c
	gcc HelloWorld.c -o HelloWorld

clean:
	rm -f *.o HelloWorld