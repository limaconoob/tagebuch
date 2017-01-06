NAME := "tagebuch.dylib"
SRC := libss.c

.SILENT: all
.PHONY: default all

default: all

all:
	gcc -shared -o $(NAME) $(SRC)
