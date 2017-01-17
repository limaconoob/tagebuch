
void command(t_lbstat *lib, void **data, char *command)
{ t_tagseite *seite = (t_tagseite *)(*data);
  static int m = 0;
  static t_fck *fragen = NULL;
  if (m == 0)
  { fragen = sag((*seite).fd, (*seite).frage, (*seite).flag);
    //Neko Love Bust
    (*lib).neko.position.cardinal = UpperRight;
    (*lib).infobulle.cardinal = Left;
    (*lib).lock ^= 1;
    neko_say((*lib).infobulle.message, "Ich wolle eine kleine Tagebuch machen, so ich mochte Ihnen ein paar Fragen stellen\nSie konnen mir antworten durch schreiben und dann Enter drücken.\nSie konnen verlassen die Modul mit die Anweisung \"Antwort > ++\"\n\nEnter druck"

/*
    write(0, "\x1B[H", 3);
    while (tmp)
    { write(schreib, "  Frage > ", 10);
      PFD((*tmp).line, schreib);
      PFD("\n", schreib);
      //Neko say *line
      write(schreib, "Antwort > ", 10);
      write(0, "Antwort > ", 10);
      GNL(1, line);
      PFD(*line, schreib);
      PFD("\n", schreib);
      DEL((void**)line);
      tmp2 = (*tmp).next;
      free((*tmp).line);
      free(tmp);
      tmp = tmp2; }
*/

    m = 1; }
  else if (m == 1)
  { neko_say((*lib).infobulle.message, "Ich danke dir fur diese Antworten!\nWenn Sie Fragen hinzufugen oder mehr,\nSie konnen \"neko buch -h\" schreiben in dein Shell,\nso dass ich mehr Informationen Ihnen geben.\n");
    //Neko Happy Bust
    write(0, "\x1B[H", 3);
    (*lib).lock ^= 1;
    m = 2; }
  else if (m == 2 && !NCMP(command, "neko buch ", 10))
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
  { //Neko Happy Seiza
    neko_say((*lib).infobulle.message, "Sie sind in meine Neko-Tagebuch Modul!\nEs war von limaconoob geschriebt.\nDas Git Source ist an:\nhttps://github.com/limaconoob/tagebuch\n\n"); }}
