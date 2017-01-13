
#include "buch.h"
#include "outils.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_fckup
{ char *line;
  struct s_fckup *next; } t_fckup;

void sag(int schreib, int lese, char flag)
{ t_fckup *fck[1];
  *fck = NULL;
  t_fckup *tmp;
  t_fckup *tmp2;
  char **line;

	while (GNL(lese, line))
	{ if (*fck)
    { (*tmp).next = (t_fckup*)malloc(sizeof(t_fckup));
      tmp = (*tmp).next;
      (*tmp).line = *line;
      (*tmp).next = NULL; }
    else
    { tmp = (t_fckup*)malloc(sizeof(t_fckup));
      (*tmp).line = *line;
      (*tmp).next = NULL;
      *fck = tmp; }}

	write(0, "\x1B[?1049h\x1B[2J\x1B[H", 16);
	if (flag == Start)
/// NEED + 1 Dans le message s'il n'y a pas de '\n' et s'il y en a aussi
	//Neko go TopRight
	//Neko bulle Right
	//Neko Love Bust
	//Neko say "Sie sind in meine Neko-Tagebuch Modul!\nEs war von limaconoob geschriebt.\nDas Git Source ist an:\nhttps://github.com/limaconoob/tagebuch"
	//sleep(2);
	//Neko Happy Seiza
	//Neko say "Ich wolle eine kleine Tagebuch machen, so\n
	//					ich möchte Ihnen ein paar Fragen stellen!\n
	//					Sie können mir antworten durch schreiben\n
	//					und dann Enter drücken.
	//					Sie können verlassen die Modul mit\n
	//					die Anweisung \"Antwort > ++\"\n"
	{ ; }

  if (*fck)
  { tmp = *fck;
    while (tmp)
    { write(schreib, "  Frage > ", 10);
		  PFD((*tmp).line, schreib);
		  PFD("\n", schreib);
		  //Neko say *line
		  write(schreib, "Antwort > ", 10);
		  write(0, "Antwort > ", 10);
		  GNL(1, line);
		  PFD(*line, schreib);
		  PFD("\n", schreib);
		  DEL((void**)line);
      tmp2 = (*tmp).next;
      free((*tmp).line);
      free(tmp);
      tmp = tmp2; }}
	//Neko Happy Bust
	//Neko say "Ich danke dir für diese Antworten!\n
	//					Wenn Sie Fragen hinzufügen oder mehr,\n
	//					Sie können \"neko buch -h\" schreiben\n
	//					in dein Shell für mehr Informationen.\n
	write(0, "\x1B[2J\x1B[H\x1B[?1049l", 16);
}
