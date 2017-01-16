
void command(t_lbstat *lib, void **data, char *command)
{ t_tagseite *seite = (t_tagseite *)(*data);
  if (!NCMP(command, "neko buch ", 10))
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
  {}
}

