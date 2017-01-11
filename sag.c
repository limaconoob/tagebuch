
#include "buch.h"
#include "outils.h"
#include <unistd.h>

void sag(int schreib, int lese, char flag)
{ char **line;
	write(0, "\x1B[?1049h\x1B[2J\x1B[H", 16);
	if (flag == Start)
/// NEED + 1 Dans le message s'il n'y a pas de '\n' et s'il y en a aussi
	//Neko go TopRight
	//Neko bulle Right
	//Neko Love Bust
	//Neko say "Sie sind in meine Neko-Tagebuch Modul!\nEs war von limaconoob geschriebt.\nDas Git Source ist an:\nhttps://github.com/limaconoob/tagebuch"
	//sleep(2);
	//Neko Happy Seiza
	//Neko say "Ich wolle eine kleine Tagebuch machen, so\n
	//					ich möchte Ihnen ein paar Fragen stellen!\n
	//					Sie können mir antworten durch schreiben\n
	//					und dann Enter drücken.
	//					Sie können verlassen die Modul mit\n
	//					die Anweisung \"Antwort > ++\"\n"
	{ ; }

	while (GNL(lese, line))
	{ write(schreib, "  Frage > ", 10);
		PFD(*line, schreib);
		PFD("\n", schreib);
		//Neko say *line
		write(schreib, "Antwort > ", 10);
		write(0, "Antwort > ", 10);
		DEL((void**)line);
		GNL(1, line);
		PFD(*line, schreib);
		PFD("\n", schreib);
		DEL((void**)line); }
	//Neko Happy Bust
	//Neko say "Ich danke dir für diese Antworten!\n
	//					Wenn Sie Fragen hinzufügen oder mehr,\n
	//					Sie können \"neko buch -h\" schreiben\n
	//					in dein Shell für mehr Informationen.\n
	write(0, "\x1B[2J\x1B[H\x1B[?1049l", 16);
}

