
#include "neko.h"
#include "outils.h"
#include "buch.h"
#include "texte.h"

void error_option(t_lbstat *lib, char error)
{ char message[SPEC_CHARACTER_MAX];
  BZE(message, SPEC_CHARACTER_MAX);
  NCPY(message, "Je ne connais   pas l'option '", 30);
  message[30] = error;
  NCPY(&message[31], "'pour le module  Neko Tagebuch!  ", 33);
  NCPY(&message[63], "", 16);
  neko_say((*lib).message, message); }

char *get_option(char *command, char *option)
{ while (*command && (*command == ' ' || *command == '\t'))
  { command += 1; }
  if (*command == '-' && LEN(command) > 3)
  { command += 1;
    if (*command == Frage || *command == Help || *command == Erinnerung)
    { *option = *command; }
    else
    { *option = -1;
      return (command); }
    command += 2; }
  return (command); }
