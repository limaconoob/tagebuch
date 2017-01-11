
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
  (*seite).fd = tag_seite(Build);
	(*seite).frage = zuh_fragen(Build);
  *data = &seite; }

void start(t_lbstat *lib, void **data)
{ static t_tagseite seite[1];
  (*seite).flag = Start;
  (*seite).fd = tag_seite(Start);
	(*seite).frage = zuh_fragen(Start);
  *data = &seite; }

void command(t_lbstat *lib, void **data, char *command)
{ t_tagseite *seite = (t_tagseite *)(*data);
  if (!NCMP(command, "neko buch ", 10))
  { char option = 0;
    command += 10;
    command = get_option(command, &option);
    if (option == Erinnerung)
    { PFD(command, (*seite).fd); }
    else if (option == Frage)
    { PFD(command, (*seite).frage); }
    else if (option == Help)
    {}
    else
    { error_option(lib, *command); }}
  else if (!NCMP(command, "neko buch\0", 10))
  {}
}

void end(t_lbstat *lib, void **data)
{ t_tagseite *seite = (t_tagseite *)(*data);
  PFD("Déconnexion du tty: ", (*seite).fd);
  PFD(ttyname(0), (*seite).fd);
  PFD("\nHeure: ", (*seite).fd);
  time_t k = time(NULL);
  char *tmp = ctime(&k);
  write((*seite).fd, &tmp[11], 8);
  write((*seite).fd, "\n", 1);
  if ((*seite).fd > 2)
  { close((*seite).fd); }
  if ((*seite).frage > 2)
  { close((*seite).frage); }}

int main(void)
{ t_lbstat lib[1];
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
