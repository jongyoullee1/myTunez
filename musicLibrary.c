#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songList.h"
#include "musicLibrary.h"

void add_song(song_node * table[], char * name1, char * artist1){
  song_node * song = create_node(name1, artist1);
  int index = *artist1 - 'a';
  //  song_node * list = table[index];
  table[index] = in_order(table[index], song);
}

song_node * search_for_song(song_node * table[], char * name1, char * artist1){

}

song_node * search_for_artist(song_node * table[], char * artist1){

}

void print_songList(song_node * table[], char * letter){

}

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
