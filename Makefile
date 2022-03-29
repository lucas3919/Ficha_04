COMPILER=gcc

bin: main.c
	$(COMPILER) -o $@
.PHONY: run clean

run:
	./bin
clean:
	rm bin