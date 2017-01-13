
#include "buch.h"
#include "outils.h"
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define INC(x) NCPY(&file_name[3], x, 2); break;

#include <stdio.h>

/// Stocke dans `neko` le chemin du dossier parent `tagebuch`
void dir_path(char *neko)
{ char *path = getenv("NEKO_PATH");
  int len;
  if (path && !access(path, X_OK | R_OK))
  { len = LEN(path);
    NCPY(neko, path, len); }
  else
  { getcwd(neko, 1024);
    len = LEN(neko); }
  NCPY(neko + len, "/tagebuch/", 10); }

static void time_filler(char *the_time, char *file_name)
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
static int file_path(char *neko, char flag, int frage)
{ time_t tmp = time(NULL);
  char *the_time = ctime(&tmp);
  char file_name[11];
  BZE(file_name, 11);
  int fd;
  time_filler(the_time, file_name);
	NCPY(&neko[LEN(neko)], file_name, 10);
	fd = open(neko, O_CREAT | O_EXCL);
  chmod(neko, 0666);
	if (fd == -1)
  { fd = open(neko, O_RDWR | O_APPEND);
    if (flag == Start)
    { PFD("Connecté sur le tty: ", fd);
			PFD(ttyname(0), fd);
			write(fd, "\nHeure: ", 8);
			write(fd, &the_time[11], 8);
			write(fd, "\n\n", 2); }
		else if (flag == Pause)
		{ PFD("La pause c'est finie à ", fd);
			write(fd, &the_time[11], 8);
			write(fd, "\n\n", 2); }}
	else
  { fd = open(neko, O_RDWR | O_APPEND);
		PFD("Début de journée: ", fd);
		write(fd, &the_time[11], 8);
		write(fd, "\n\n", 2);
		PFD("Connecté sur le tty: ", fd);
		PFD(ttyname(0), fd);
		write(fd, "\nHeure: ", 8);
		write(fd, &the_time[11], 8);
		write(fd, "\n\n", 2); 
		sag(fd, frage, flag); }
  return (fd); }

/// Retourne le descripteur du fichier où les infos du jour seront écrites
int tag_seite(char flag, int frage)
{ char neko[1024];
  BZE(neko, 1024);
  dir_path(neko);
  mkdir(neko, 0);
  chmod(neko, 0755);
  return (file_path(neko, flag, frage)); }

int openner(char *file)
{ char neko[1024];
  BZE(neko, 1024);
  dir_path(neko);
  mkdir(neko, 0);
  chmod(neko, 0755);
	NCPY(&neko[LEN(neko)], file, LEN(file));
  open(neko, O_CREAT);
  chmod(neko, 0666);
	return(open(neko, O_RDWR | O_APPEND)); }
