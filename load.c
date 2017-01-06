
#include "outils.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

static void dir_path(char *neko)
{ char *path = getenv("NEKO_PATH");
  int len;
  if (path && !access(path, IS_OK))
  { len = LEN(path);
    NCPY(neko, path, len); }
  else
  { getcwd(neko, 1024);
    len = LEN(neko); }
  NCPY(neko + len, "/tagebuch/", 10; }

static void file_path(char *neko)
{ DIR *dir = opendir(neko);
  if (dir)
  { struct dirent *dp;
    while ((dp = readdir(dir)))
    (void)closedir(dir); }}

/// Retourne le descripteur du fichier où les infos du jour seront écrites
int tag_seite(char *neko)
{ int fd;
  dir_path(neko);
  file_path(neko);
}
