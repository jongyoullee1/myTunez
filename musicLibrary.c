#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songList.h"
#include "musicLibrary.h"

void add_song(song_node * table[], char * name1, char * artist1){
  int index = *artist1 - 'a';
  table[index] = in_order(table[index], name1, artist1;)
}

//UNTESTED HERE ON OUT
song_node * search_for_song(song_node * table[], char * name1, char * artist1){
  int index = *artist - 'a';
  return find_song_name(table[index]);
}

void search_for_artist(song_node * table[], char * artist1){
  int index = *artist - 'a';
  song_node * start = find_song_name(table[index]);
  while (start && strcmp(start->artist, artist1) == 0)
    print_song(start);
}

void print_songList(song_node * table[], char * letter){
  int index = *letter - 'a';
  print_list(table[index]);
}
/*
void print_artists_songs(song_node * table[], char * artist){

}

void print_library(song_node * table[]){

}

void shuffle(song_node * table[]){

}

void delete_song(song_node * table[], char * name1, char * artist1){

}

void delete_all(song_node * table[]){

}
*/
