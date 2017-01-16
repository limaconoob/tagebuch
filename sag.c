
#include "buch.h"
#include "outils.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_fckup
{ char *line;
  struct s_fckup *next; } t_fckup;

void sag(int schreib, int lese, char flag)
{ static t_fckup *fck[1];
  *fck = NULL;
  t_fckup *tmp;
  t_fckup *tmp2;
  char *line[1];
  *line = NULL;
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
        *fck = tmp; }}}}
