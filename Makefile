clean:
	rm -rf build

build:
	mkdir -p build
	gcc -c -Iinc main.c -o build/main.o	
	gcc -c -Iinc src/cclock.c -o build/cclock.o
	gcc -c -Iinc src/clock.c -o build/clock.o
	gcc -c -Iinc src/display.c -o build/display.o
	gcc -c -Iinc src/ecall.c -o build/ecall.o
	gcc -c -Iinc src/ledmatrix.c -o build/ledmatrix.o
	gcc build/*.o -Llib -lecall -o build/main
run:
	./build/main
	
all: clean build run

help:
	@echo "For explicit full-flow run Simulation: make clean build run"
	@echo "For short full-flow run Simulation: make all"