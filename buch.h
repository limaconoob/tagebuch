#ifndef BUCH_H
#define BUCH_H

int tag_seite(char flag);

typedef enum e_flags
{ Build,
  Start,
  Pause,
  } t_flags;

typedef enum e_options
{ Frage = 0x01,
  Antwort = 0x02,
  Erinnerung = 0x04,
  } t_flags;

typedef struct s_tagseite
{ int fd;
  int flag; } t_tagseite;

#endif
