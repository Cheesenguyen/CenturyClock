clean:
	rm -rf build

build:
	mkdir -p build
	gcc -c  -Iinc main.c -o build/main.o		
	gcc build/main.o -Llib -lecall -o build/main

run:
	./build/main
all: clean build run

help:
	@echo "For explicit full-flow run Simulation: make clean build run"
	@echo "For short full-flow run Simulation: make all"