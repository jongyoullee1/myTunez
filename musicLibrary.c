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
