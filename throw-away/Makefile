SHELL = /bin/sh

OBJS = gstreamerX11-example.cpp
CFLAGS = `pkg-config --cflags --libs gstreamer-1.0`
CC = g++

example: ${OBJ}
	${CC} ${OBJS} -o $@ ${CFLAGS}

clean:
	-rm *.o example