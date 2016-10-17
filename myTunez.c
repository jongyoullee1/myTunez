#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * create_node(char *name1, char *artist1){
  song_node *new = (song_node *) malloc(sizeof(song_node));
  strcpy(new->name,name1);
  strcpy(new->artist,artist1);
  new->next = 0;
  return new;
}

song_node * insert_front(song_node *s,char *name1,char *artist1) {
  song_node *new = create_node(name1, artist1);
  new->next=s;
  return new;
}

song_node * in_order(song_node *s,char * name1, char * artist1) {
  if (strcmp(s->name, name1) > 0) return insert_front(s,name1,artist1);
  song_node *retVal=s;
  song_node *bef=s;
  s = s->next;
  while (s) {
    if (strcmp(s->name, name1) > 0) {
      song_node *new = insert_front(s,name1,artist1);
      bef->next = new;
      return retVal;
     }
    s = s->next;
    bef = bef->next;
  }
  song_node * toInsert = create_node(name1, artist1);
  bef->next = toInsert;
  return retVal;
}

void print_list(song_node *n ) {

  printf("[ ");
  
  while(n) {
    printf("%s ", n->name );
    n = n->next;
  }
  printf("]\n");
}

int main() {

  song_node *s = 0;

  print_list(s );

  s=insert_front(s,"twinkle twinkle", "anon");
  print_list( s );
  s=in_order(s,"happy birthday","guest");
  print_list( s );
  s=in_order(s,"ppy birthday","guest");
  print_list( s );
  s=in_order(s,"uuu","a");
  print_list( s );
  
  return 0;
}
