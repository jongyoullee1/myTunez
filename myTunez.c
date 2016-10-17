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
  if (strcmp(s->artist, artist1) > 0) return insert_front(s,name1,artist1);
  song_node *retVal=s;
  song_node *bef=s;
  s = s->next;
  while (s) {
    int aCmpVal = strcmp(s->artist, artist1);
    if (aCmpVal > 0 ||
	(aCmpVal == 0 && strcmp(s->name, name1) > 0)){
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

/* song_node * in_order(song_node *s,char * name1, char * artist1) { */
/*   if (strcmp(s->name, name1) > 0) return insert_front(s,name1,artist1); */
/*   song_node *retVal=s; */
/*   song_node *bef=s; */
/*   s = s->next; */
/*   while (s) { */
/*     if (strcmp(s->name, name1) > 0) { */
/*       song_node *new = insert_front(s,name1,artist1); */
/*       bef->next = new; */
/*       return retVal; */
/*      } */
/*     s = s->next; */
/*     bef = bef->next; */
/*   } */
/*   song_node * toInsert = create_node(name1, artist1); */
/*   bef->next = toInsert; */
/*   return retVal; */
/* } */

song_node * find_song_name(song_node *list, char * song_title){
  while (list){
    if (strcmp(list->name, song_title) == 0)
      break;
    list = list->next;
  }
  return list;
}

song_node * find_song_artist(song_node *list, char * song_artist){
  while (list){
    if (strcmp(list->artist, song_artist) == 0)
      break;
    list = list->next;
  }
  return list;
}

void print_list(song_node *n ) {

  printf("[ ");
  
  while(n) {
    printf("%s -- %s ", n->artist, n->name );
    n = n->next;
  }
  printf("]\n");
}

int main() {

  song_node *s = 0;

  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing printing and inserting in order:\n");
  printf("At the beginning:\n");
  print_list(s);
  printf("Adding \"twinkle twinkle\":\n");
  s=insert_front(s,"twinkle twinkle", "anon");
  print_list(s);
  printf("Adding \"happy birthday\":\n");
  s=in_order(s,"happy birthday","guest");
  print_list(s);
  printf("Adding \"purple\":\n");
  s=in_order(s,"purple","guest");
  print_list(s);
  printf("Adding \"uuu\":\n");
  s=in_order(s,"uuu","a");
  print_list(s);
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by title:\n");
  printf("Finding \"twinkle twinkle\" in s:\n");
  print_list(find_song_name(s, "twinkle twinkle"));
  printf("Finding \"uuu\" in s:\n");
  print_list(find_song_name(s, "uuu"));
  printf("Finding \"doesn't exist boi\" in s:\n");
  print_list(find_song_name(s, "doesn't exist boi"));
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by artist:\n");
  printf("Finding guest's song in s:\n");
  print_list(find_song_artist(s, "guest"));
  printf("Finding anon's song in s:\n");
  print_list(find_song_artist(s, "anon"));
  printf("\n");
  printf("========================================\n");
  printf("\n");

  
  return 0;
}
