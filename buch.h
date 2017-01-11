#ifndef BUCH_H
#define BUCH_H

#include "neko.h"

void dir_path(char *neko);
int tag_seite(char flag, int frage);
int zuh_fragen(char flag);
char *get_option(char *command, char *option);
void error_option(t_lbstat *lib, char error);
void sag(int schreib, int lese, char flag);

typedef enum e_flags
{ Build,
  Start,
  Pause,
	Antwort,
  Wait, } t_flags;

typedef enum e_options
{ Frage = 102,
  Help = 104,
  Erinnerung = 101,
  } t_options;

typedef struct s_tagseite
{ int fd;
	int frage;
  int flag; } t_tagseite;

#endif
