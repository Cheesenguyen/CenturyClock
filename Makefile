clean:
	rm -rf build

build:
	mkdir -p build
	gcc -c  -Iinc main.c -o build/main.o	
	gcc -c  -Iinc src/*.c 
	mv *.o build/
	gcc build/*.o -Llib -lecall -o build/main

run:
	./build/main
	
all: clean build run

help:
	@echo "For explicit full-flow run Simulation: make clean build run"
	@echo "For short full-flow run Simulation: make all"