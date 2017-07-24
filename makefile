#@todo make a proper makefile
make:
	g++ main.cpp -o Odin.out

run:
	./Odin.out

clean:
	rm Odin.out