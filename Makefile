
NAME := "tagebuch.dylib"
SRC := libss.c texte.c gnl.c load.c outils.c options.c sag.c command.c

default: all

all:
	gcc -shared -o $(NAME) $(SRC)

clean:
  rm $(NAME)

re: clean all

SILENT: all
.PHONY: default all clean re
