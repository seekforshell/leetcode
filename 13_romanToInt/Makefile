cc=gcc -std=c99
src = $(shell find ./ -name '*.c')

clean:
	rm -rf *.out
all: clean
	$(cc) $(src) -o run.out
