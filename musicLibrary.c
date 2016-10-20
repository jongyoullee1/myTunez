#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songList.h"
#include "musicLibrary.h"

void add_song(song_node * table[], char * name1, char * artist1){
  int index = *artist1 - 'a';
  table[index] = in_order(table[index], name1, artist1);
}

song_node * search_for_song(song_node * table[], char * name1, char * artist1){
  int index = *artist1 - 'a';
  return find_song_name(table[index], name1);
}

void print_songList(song_node * table[], char letter){
  int index = letter - 'a';
  print_list(table[index]);
}
/*
//returns pointer to first occurence of artist
song_node * search_for_artist(song_node * table[], char * artist1){
  int index = *artist1 - 'a';
  printf("part 0\n");
  song_node * start = find_song_artist(table[index], artist1);
  print_song(start);
  printf("part 1\n");
  return start;
  }

void print_artists_songs(song_node * table[], char * artist){
  //  int index = *artist - 'a';
  song_node * start = search_for_artist(table, artist);
  if (!start) printf("no songs found for this artist\n");
  else {
    while (start && strcmp(start->artist, artist) == 0) {
      print_song(start);
      printf(" ");
      start=start->next;
    }
  }
}*/

void print_library(song_node * table[]){
  char letter;
  for (letter = 'a'; letter < 'a' + 26; letter++) {
    printf("%c: ", letter);
    print_songList(table, letter);
  }
}
/*
void shuffle(song_node * table[]){
  int count;
  for (count = 3; count > 0; count--)
    
  }*/

void delete_song(song_node * table[], char * name1, char * artist1){
  int index = *artist1 - 'a';
  table[index] = remove_node(table[index], find_song_name(table[index], name1));
}

void delete_all(song_node * table[]){
  int i;
  for (i=0; i < 26; i++){
    song_node * list = table[i];
    while (list)
      list = remove_node(list, list);
    table[i] = NULL;
  }

}
