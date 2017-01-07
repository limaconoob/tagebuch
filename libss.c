
#include "neko.h"
#include "outils.h"
#include "buch.h"
#include <sys/stat.h>
#include <unistd.h>

// Descritpion du module tagebuch:
//  build : 1 Si le dossier .neko/tagebuch/ n'existe pas, il est créé.
//          2 Si le fichier .neko/tagebuch/[Jour:Mois:Année] n'existe pas,
//            il est créé.
//          3 Indiquer dans le fichier que c'est build
//  start : 1 Si le fichier .neko/tagebuch/[Jour:Mois:Année] n'existe pas,
//            il est créé.
//          2 Si le fichier existe déjà et que start est appelée
//            on ajoutera le temps écoulé en `temps de pause`
//command : Sinon, la Neko va poser des questions et les réponses de
//          l'utilisateur seront stockée dans le fichier.
//unmount : Indiquer dans le fichier que c'est démonté
//    end : Il faut ajouter l'heure à laquelle cette fonction est appelée

void build(t_lbstat *lib, void **data)
{ static t_tagseite seite[1];
  (*seite).flag = Build;
  (*seite).fd = tag_seite(Build);
  *data = &seite; }

void start(t_lbstat *lib, void **data)
{ static t_tagseite seite[1];
  (*seite).flag = Start;
  (*seite).fd = tag_seite(Start);
  *data = &seite; }

void command(t_lbstat *lib, void **data, char *command)
{ t_tagseite *seite = (t_tagseite *)(*data);
  if (!NCMP(command, "neko buch ", 10))
  { char options = 0;
    command += 10;
    command = get_options(command, &options); }
  else if (!NCMP(command, "neko buch", 9))
  {}
}

void end(t_lbstat *lib, void **data)
{ t_tagseite *seite = (t_tagseite *)(*data);
  if ((*seite).fd > 2)
  { close((*seite).fd); }}

int main(void)
{ t_lbstat lib[1];
  unsigned long data;
  data = 0;
//  build(lib, (void**)&data);
  start(lib, (void**)&data);
  end(lib, (void**)&data); }
