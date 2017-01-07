
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

void build(t_lbstat *state, void **data)
{ char neko[1024];
  BZE(neko, 1024);
  dir_path(neko);
  if (!mkdir(neko, 0))
  { chmod(neko, 0755); }
}
