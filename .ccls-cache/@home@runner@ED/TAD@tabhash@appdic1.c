#include "./taddic.h"
#include <stdio.h>
#include <string.h>

// gcc appdic1.c taddic.c taddic.h ../tadlista.c -o main.bin
// w/ taddic's in same folder

int main() {
  Dic dicUFS = new_dic(26);         // dicUFs = {}
  adDic(dicUFS, "SP", "Sao Paulo"); // dicUfs["SP"] = "Sao Paulo"

  printf("%d\n", lenDic(dicUFS));
  printf("ESTADO: %s\n", (char *)elemDic(dicUFS, "SP")); // typecast
  return 0;
}