clean:
	rm -rf build

build:
	mkdir -p build
	gcc -c -Iinc main.c -o build/main.o	
	gcc -c -Iinc src/cclock.c -o build/cclock.o
	gcc -c -Iinc src/clock.c -o build/clock.o
	gcc -c -Iinc src/display.c -o build/display.o
	gcc -c -Iinc src/ledmatrix.c -o build/ledmatrix.o
	gcc build/*.o -o build/centuryclock-v0.0.0-ubuntu22.04-x64-gcc11.4.0 -Llib -lecall 
run:
	./build/centuryclock-v0.0.0-ubuntu22.04-x64-gcc11.4.0
	
all: clean build run

help:
	@echo "For explicit full-flow run Simulation: make clean build run"
	@echo "For short full-flow run Simulation: make all"