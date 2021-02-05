SHELL = /bin/sh

# Build tools and flags
OBJS = src/main.c
CC = gcc

app: ${OBJ}
	${CC} ${OBJS} -o $@

clean:
	-rm main

