#ifndef BUCH_H
#define BUCH_H

void dir_path(char *neko);
int tag_seite(char flag);

typedef enum e_flags
{ Build,
  Start,
  Pause,
  Wait, } t_flags;

typedef enum e_options
{ Frage = 102,
  Antwort = 97,
  Erinnerung = 101,
  } t_flags;

typedef struct s_tagseite
{ int fd;
  int flag; } t_tagseite;

#endif
