SHELL = /bin/sh

OBJS = gstreamer-example.cpp
OBJS1 = rtsp-server.c
OBJS2 = gstreamer-inception.cpp
OBJS3 = openCV-sample.cpp
OBJS4 = v4l2grab.c
CFLAGS = `pkg-config --cflags --libs gstreamer-1.0`
CFLAGS2 =`pkg-config --cflags --libs gstreamer-1.0 gstreamer-audio-1.0`
CFLAGS1 = `pkg-config --cflags --libs opencv4`
CC = g++
cc = gcc

example: ${OBJ}
	${CC} ${OBJS} -o $@ ${CFLAGS}
inception: ${OBJ}
	${CC} ${OBJS2} -o $@ ${CFLAGS2}
rtsp: ${OBJ}
	${cc} ${OBJS1} -o $@ ${CFLAGS}
openCV: ${OBJ}
	${CC} ${OBJS3} -o $@ ${CFLAGS1}
v4l: ${OBJ}
	${cc} ${OBJS4} -o $@
clean:
	-rm example rtsp inception openCV