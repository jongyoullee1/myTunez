#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songList.h"

int main() {


  song_node * s = NULL;

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
  //  free_list(s);

  srand(time(NULL));
 
  song_node * table[26];
  int i;
  for (i = 0; i < 26; i++){
    table[i] = NULL;
  }
  
  printf("Adding aaa's song to the library:\n");
  add_song(table, "mary had a little lamb", "aaa");
  print_list(table[0]);
  printf("Adding abb's song to the library:\n");
  add_song(table, "baba black sheep", "abb");
  print_list(table[0]);
  printf("Adding bee's song to the library:\n");
  add_song(table, "honey", "bee");
  print_list(table[1]);
  printf("Adding a's song to the library:\n");
  add_song(table, "hhhhhhh", "a");
  print_list(table[0]);


  

  
  
  return 0;
}
