
#include "outils.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define INC(x) NCPY(&file_name[3], x, 2); break;

#include <stdio.h>

/// Stocke dans `neko` le chemin du dossier parent `tagebuch`
static void dir_path(char *neko)
{ char *path = getenv("NEKO_PATH");
  int len;
  if (path && !access(path, X_OK | R_OK))
  { len = LEN(path);
    NCPY(neko, path, len); }
  else
  { getcwd(neko, 1024);
    len = LEN(neko); }
  NCPY(neko + len, "/tagebuch/", 10); }

void time_filler(char *the_time, char *file_name)
{ if (the_time[8] == ' ')
  { the_time[8] = '0'; }
  file_name[0] = the_time[8];
  file_name[1] = the_time[9];
  file_name[2] = '.';
  switch(the_time[4] + the_time[5] + the_time[6])
  { case 281:
      INC("01");
    case 269:
      INC("02");
    case 288:
      INC("03");
    case 291:
      INC("04");
    case 295:
      INC("05");
    case 301:
      INC("06");
    case 299:
      INC("07");
    case 285:
      INC("08");
    case 296:
      INC("09");
    case 294:
      INC("10");
    case 307:
      INC("11");
    case 268:
      INC("12"); }
  file_name[5] = '.';
  NCPY(&file_name[6], &the_time[20], 4); }

/// Stocke dans `neko` le chemin du fichier où les infos du jour seront écrites
static void file_path(char *neko)
{ DIR *dir = opendir(neko);
  time_t tmp = time(NULL);
  char *the_time = ctime(&tmp);
  char file_name[11];
  BZE(file_name, 11);
  if (dir && the_time)
  { struct dirent *dp;
    time_filler(the_time, file_name);
    printf("THE_TIME::%s\n", the_time);
    printf("FILE_NAME::%s\n", file_name);
    /*while ((dp = readdir(dir)))*/
    (void)closedir(dir); }}

/// Retourne le descripteur du fichier où les infos du jour seront écrites
int tag_seite(char *neko)
{ int fd;
  dir_path(neko);
  mkdir(neko, 0);
  chmod(neko, 0755);
  file_path(neko);
  return (0); }

int main(void)
{ char neko[1024];
  BZE(neko, 1024);
  printf("FD::%d\n", tag_seite(neko)); }
