build:
	gcc -g -o bin/tempscale src/main.c

debug:
	make build
	gdb bin/tempscale

tempscale:
	make build
	bin/tempscale
