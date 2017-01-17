#ifndef BUCH_H
#define BUCH_H

#include "neko.h"

typedef enum e_flags
{ Build,
  Start,
  Pause,
	Antwort,
  Wait, } t_flags;

typedef enum e_options
{ Help = 104,
  Erinnerung = 101,
  Frage = 102,
  } t_options;

typedef struct s_fckup
{ char *line;
  struct s_fckup *next; } t_fckup;

typedef struct s_tagseite
{ int fd;
	int frage;
  t_fckup *fragen[1];
	int erinn;
  int flag; } t_tagseite;

void dir_path(char *neko);
int tag_seite(char flag, int frage);
int openner(char *file);
char *get_option(char *command, char *option);
void error_option(t_lbstat *lib, char error);
void sag(int schreib, int lese, char flag, t_fckup **fck);

#endif
