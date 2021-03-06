
#include "neko.h"
#include "outils.h"
#include "buch.h"
#include "texte.h"
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

// Descritpion du module tagebuch:
//  build : 1 Si le dossier .neko/tagebuch/ n'existe pas, il est créé.
//          2 Indiquer dans le fichier que c'est build
//  start : Si le fichier .neko/tagebuch/[Jour:Mois:Année] n'existe pas,
//          il est créé.
//command : Sinon, la Neko va poser des questions et les réponses de
//          l'utilisateur seront stockée dans le fichier.
//unmount : Indiquer dans le fichier que c'est démonté
//    end : Il faut ajouter l'heure à laquelle cette fonction est appelée

void build(t_lbstat *lib, void **data)
{ static t_tagseite seite[1];
  (*seite).flag = Build;
	(*seite).frage = openner("fragen");
	(*seite).erinn = openner("todo_list");
  (*seite).fd = tag_seite(Build, (*seite).frage);
  *data = &seite; }

void start(t_lbstat *lib, void **data)
{ static t_tagseite seite[1];
  (*seite).flag = Start;
	(*seite).frage = openner("fragen");
	(*seite).erinn = openner("todo_list");
  (*seite).fd = tag_seite(Start, (*seite).frage);
  *data = &seite; }

void end(t_lbstat *lib, void **data)
{ t_tagseite *seite = (t_tagseite *)(*data);
  PFD("Déconnexion du tty: ", (*seite).fd);
  PFD(ttyname(0), (*seite).fd);
  PFD("\nHeure: ", (*seite).fd);
  time_t k = time(NULL);
  char *tmp = ctime(&k);
  write((*seite).fd, &tmp[11], 8);
  write((*seite).fd, "\n\n", 2);
  if ((*seite).fd > 2)
  { close((*seite).fd); }
  if ((*seite).frage > 2)
  { close((*seite).frage); }
  if ((*seite).erinn > 2)
  { close((*seite).erinn); }}

int main(void)
{ t_lbstat lib[1];
  int k = 0;
  while (k < SPEC_CHARACTER_MAX)
  { ((*lib).message[k]).glyph = 0;
    k += 1; }
  unsigned long data;
  data = 0;
//  build(lib, (void**)&data);
  start(lib, (void**)&data);
	char c[50];
	BZE(c, 50);
  while (read(1, c, 49))
	{ if (*c == 'q')
		{ break; }
		else
		{ command(lib, (void**)&data, c); }
		BZE(c, 50); }
  end(lib, (void**)&data); }
