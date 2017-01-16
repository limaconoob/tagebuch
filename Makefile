NAME := "tagebuch.dylib"
SRC := libss.c texte.c gnl.c load.c outils.c options.c sag.c

.SILENT: all
.PHONY: default all

default: all

all:
	gcc -shared -o $(NAME) $(SRC)
