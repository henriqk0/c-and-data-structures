#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tadlista.h"

char *strip(char *s){
  int ultimo = strlen(s) - 1;
  if(s[ultimo] == '\n')
    s[ultimo] = '\0';
  return s;  
}

Lista insereOrdenado(Lista l, char *s){
  if(lenLista(l) == 0){
    appendLista(l,s);
    return l;
  }
  else {
    char *aux;
    for(int i=0; i < lenLista(l); i++){
      aux = (char *)elemLista(l,i);
      if((strcmp(aux,s) > 1) || (strcmp(aux,s) == 0)){
        insereLista(l,s,i);
        return l;
      }
    }
    appendLista(l,s);
  } 
  return l;
}

Lista loadListaOrdenado(char *filename){
  Lista l = new_lista();
  FILE *arq = fopen(filename,"rt");
  char linha[64];
  char *dadolst;

  while(!feof(arq)){
    (void)fgets(linha,64,arq);
    dadolst = (char *)malloc(64 * sizeof(char));
    strcpy(dadolst,linha);
    strip(dadolst);
    insereOrdenado(l,dadolst);    
  }
  return l;  
}

void print_lista(Lista lst){
  for(int i=0; i < lenLista(lst)-1; i++){
    printf("%s, ",(char *)elemLista(lst,i));
  }
  printf("%s",(char *)elemLista(lst,lenLista(lst)-1));
}

int main(){
  Lista lst = new_lista();
  lst = loadListaOrdenado("dados2clonagem.txt");
  insereOrdenado(lst,"JABUTICABA");
  print_lista(lst);
  printf("\n");
  return 0;
}