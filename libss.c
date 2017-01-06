
#include "neko.h"
#include "outils.h"
#include <sys/stat.h>

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

void build(t_lbstat *state, void **data)
{ char neko[1024];
  BZE(neko, 1024);
  char *path = getenv("NEKO_PATH");
  if (path)
  { NCPY(neko, path, strlen(path));
    mkdir("bonjour", 0);
  }
  else
  { getcwd(neko, 1024);
  }
}

void start(t_lbstat *state, void **data)
{ g }
