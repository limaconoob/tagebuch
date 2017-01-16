
#include "buch.h"
#include "outils.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_fckup
{ char *line;
  struct s_fckup *next; } t_fckup;

    //neko_say((*lib).infobulle.message, "Sie sind in meine Neko-Tagebuch Modul!\nEs war von limaconoob geschriebt.\nDas Git Source ist an:\nhttps://github.com/limaconoob/tagebuch\n\n");
    //Neko Happy Seiza

void sag(int schreib, int lese, char flag)
{ static t_fckup *fck[1];
  *fck = NULL;
  t_fckup *tmp;
  t_fckup *tmp2;
  char **line;
  static int m = 0;

  if (flag == Start)
  { while (GNL(lese, line))
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

    write(0, "\x1B[H", 3);
    (*lib).neko.position.cardinal = UpperRight;
    (*lib).infobulle.cardinal = Left;
    (*lib).lock ^= 1;
    neko_say((*lib).infobulle.message, "Ich wolle eine kleine Tagebuch machen, so ich mochte Ihnen ein paar Fragen stellen\nSie konnen mir antworten durch schreiben und dann Enter drücken.\nSie konnen verlassen die Modul mit die Anweisung \"Antwort > ++\"\n\nEnter druck"

    //Neko Love Bust

    if (m == 0 && *fck)
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
        tmp = tmp2; }
      m = 1; }
    else if (m == 1)
    { neko_say((*lib).infobulle.message, "Ich danke dir fur diese Antworten!\nWenn Sie Fragen hinzufugen oder mehr,\nSie konnen \"neko buch -h\" schreiben in dein Shell,\nso dass ich mehr Informationen Ihnen geben.\n");
      //Neko Happy Bust
      write(0, "\x1B[H", 3);
      (*lib).lock ^= 1;
      m = 2; }}}
