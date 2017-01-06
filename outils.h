#ifndef OUTILS_H
#define OUTILS_H
  int LEN(char *str);
  void BZE(void *ptr, int size);
  int GNL(int fd, char **line);
  int NCMP(void *ptr1, void *ptr2, int size);
  char *SUB(char *str, int start, int len);
  void NCPY(void *ptr1, void *ptr2, int size);
  char **SPL(char *str, char c);
  void DEL(void **data);
  char *DUP(char *str);
  void NCHT(t_character *car, void *ptr2, int size);
#endif
