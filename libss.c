
#include "neko.h"
#include "outils.h"
#include "buch.h"
#include <sys/stat.h>
#include <unistd.h>

// Descritpion du module tagebuch:
//  start : 1 Si le fichier .neko/tagebuch/[Jour:Mois:Année] n'existe pas,
//            il est créé.
//          2 Si le fichier existe déjà et que start est appelée
//            on ajoutera le temps écoulé en `temps de pause`
//command : Sinon, la Neko va poser des questions et les réponses de
//          l'utilisateur seront stockée dans le fichier.
//  build : 1 Si le dossier .neko/tagebuch/ n'existe pas, il est créé.
//          2 Si le fichier .neko/tagebuch/[Jour:Mois:Année] n'existe pas,
//            il est créé.
//          3 Indiquer dans le fichier que c'est build
//unmount : Indiquer dans le fichier que c'est démonté
//    end : Il faut ajouter l'heure à laquelle cette fonction est appelée

void dir_path(char *neko)
{ char *path = getenv("NEKO_PATH");
  int len;
  if (path && !access(path, IS_OK))
  { len = LEN(path);
    NCPY(neko, path, len); }
  else
  { getcwd(neko, 1024);
    len = LEN(neko); }
  NCPY(neko + len, "/tagebuch/", 10; }

void build(t_lbstat *state, void **data)
{ char neko[1024];
  BZE(neko, 1024);
  dir_path(neko);
  if (!mkdir(neko, 0))
  { chmod(neko, 0755); }
}
