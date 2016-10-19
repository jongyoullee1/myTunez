#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songList.h"

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

void print_song(song_node *n){
  if (n)
    printf("%s -- %s \n", n->artist, n->name );
  else
    printf("no song\n");
}

song_node * find_random(song_node *list) {
  int len=len_song_list(list);
  int ran=rand()%len;
  //  printf("random %d\n",ran);
  int i;
  for (i=0;i<ran;i++) {
    list=list->next;
  }
  return list;
}

int len_song_list(song_node *list) {
  int count=0;
  while (list) {
    count++;
    list=list->next;
  }
  return count;
}

song_node * remove_node(song_node *list,song_node *to_remove) {
  if (list==to_remove) {
    song_node * ret = list->next;
    list->next = NULL;
    return ret;
  }
  song_node *ret=list;
  song_node *bef=list;
  list = list->next;

  while (list) {
    if (list == to_remove) {
      bef->next = list->next;
      list->next = NULL;
      break;
    }
    bef=bef->next;
    list = list->next;
  }
  return ret;

}

song_node * free_list(song_node *n ) {

  song_node *f = n;
  while ( n ) {
    n = n->next;
    printf("freeing node: %s -- %s\n", f->artist, f->name );
    free(f);
    f = n;    
  }
  return n;
}

int main() {
  srand(time(NULL));
  song_node *s = 0;

  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing printing and inserting in order:\n");
  printf("At the beginning:\n");
  print_list(s);
  printf("Adding \"twinkle twinkle\":\n");
  s=insert_front(s,"twinkle twinkle", "garett");
  print_list(s);
  printf("Adding \"happy birthday\":\n");
  s=in_order(s,"happy birthday","guest");
  print_list(s);
  printf("Adding \"purple\":\n");
  s=in_order(s,"purple","guest");
  print_list(s);
  printf("Adding \"uuu\":\n");
  s=in_order(s,"uuu","guadalupe");
  print_list(s);
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by title:\n");
  printf("Finding \"twinkle twinkle\" in s:\n");
  print_song(find_song_name(s, "twinkle twinkle"));
  printf("Finding \"uuu\" in s:\n");
  print_song(find_song_name(s, "uuu"));
  printf("Finding \"doesn't exist boi\" in s:\n");
  print_song(find_song_name(s, "doesn't exist boi"));
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by artist:\n");
  printf("Finding guest's song in s:\n");
  print_song(find_song_artist(s, "guest"));
  printf("Finding anon's song in s:\n");
  print_song(find_song_artist(s, "anon"));
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing finding a random song:\n");
  printf("Finding random song in s:\n");
  print_song(find_random(s));
    printf("Finding random song in s:\n");
  print_song(find_random(s));
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing removing a node (removing uuu node):\n");
  printf("Removed uuu:\n");
  s = remove_node(s, find_song_name(s, "uuu"));
  print_list(s);
  printf("\n");
  free_list(s);

  
  return 0;
}
