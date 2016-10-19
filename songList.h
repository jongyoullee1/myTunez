#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef IMPORTED
#define IMPORTED

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * create_node(char *name1, char *artist1);
song_node * insert_front(song_node *s,char *name1,char *artist1);
song_node * find_song_name(song_node *list, char * song_title);
song_node * find_song_artist(song_node *list, char * song_artist);
void print_list(song_node *n );
void print_song(song_node *n);
song_node * find_random(song_node *list);
int len_song_list(song_node *list);
song_node * remove_node(song_node *list,song_node *to_remove) ;
song_node * free_list(song_node *n );

#endif
