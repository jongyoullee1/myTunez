#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songList.h"

int main() {

  song_node * s = NULL;

  printf("\n");
  printf("========================================\n");
  printf("Testing song list functions\n");
  printf("========================================\n");
  printf("\n");

  printf("Testing printing and inserting in order:\n\n");
  printf("At the beginning:\n");
  print_list(s);
  printf("Adding \"sir duke\":\n");
  s=insert_front(s,"sir duke", "stevie wonder");
  print_list(s);
  printf("Adding \"brave\":\n");
  s=in_order(s,"brave","sara bareilles");
  print_list(s);
  printf("Adding \"i choose you\":\n");
  s=in_order(s,"i choose you" "sara bareilles");
  print_list(s);
  printf("Adding \"superstition\":\n");
  s=in_order(s,"superstition","stevie wonder");
  print_list(s);
  printf("Adding \"stamina\":\n");
  s=in_order(s,"stamina","sia");
  print_list(s);
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by title:\n\n");
  printf("Finding \"sir duke\" in s:\n");
  print_song(find_song_name(s, "sir duke"));
  printf("Finding \"brave\" in s:\n");
  print_song(find_song_name(s, "brave"));
  printf("Finding \"doesn't exist boi\" in s:\n");
  print_song(find_song_name(s, "doesn't exist boi"));
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by artist:\n\n");
  printf("Finding stevie wonder's song in s:\n");
  print_song(find_song_artist(s, "stevie wonder"));
  printf("Finding anon's song in s:\n");
  print_song(find_song_artist(s, "anon"));
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing finding a random song:\n\n");
  printf("Finding random song in s:\n");
  print_song(find_random(s));
  printf("Finding random song in s:\n");
  print_song(find_random(s));
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing removing a node:\n\n");
  printf("Removing \"i choose you\" node:\n");
  s = remove_node(s, find_song_name(s, "i choose you"));
  print_list(s);
  printf("\n");
  free_list(s);


  //=============================================================


  srand(time(NULL));
 
  song_node * table[26];
  int i;
  for (i = 0; i < 26; i++){
    table[i] = NULL;
  }
  
  printf("\n");
  printf("========================================\n");
  printf("Testing music library functions\n");
  printf("========================================\n");
  printf("\n");

  printf("Testing adding songs:\n\n");
  printf("Adding harry chapin: cats in the cradle:\n");
  add_song(table, "cats in the cradle", "harry chapin");
  printf("h list: ");
  print_list(table[7]);
  printf("Adding imagine dragons: time:\n");
  add_song(table, "time", "imagine dragons");
  printf("i list: ");
  print_list(table[8]);
  printf("Adding ingrid michaelson: hell no:\n");
  add_song(table, "hell no", "ingrid michaelson");
  printf("i list: ");
  print_list(table[8]);
  printf("Adding idina menzel: let it go:\n");
  add_song(table, "let it go", "idina menzel");
  printf("i list: ");
  print_list(table[8]);
  printf("Adding adele: turning tables:\n");
  add_song(table, "turning tables", "adele");
  printf("a list: ");
  print_list(table[0]);
  printf("Adding imagine dragons: i bet my life:\n");
  add_song(table, "i bet my life", "imagine dragons");
  printf("i list: ");
  print_list(table[8]);
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by title:\n\n");
  printf("Looking for turning tables by adele:\n");
  print_song(search_for_song(table, "turning tables", "adele"));
  printf("Looking for i bet my life by imagine dragons:\n");
  print_song(search_for_song(table, "i bet my life", "imagine dragons"));
  printf("Looking for doesn't exist by imagine dragons:\n");
  print_song(search_for_song(table, "doesn't exist", "imagine dragons"));
  printf("\n");
  printf("========================================\n");
  printf("\n");

  
  printf("Testing searching for artist:\n\n");
  printf("Looking for imagine dragons:\n");
  print_artists_songs(table, "imagine dragons");
  printf("Looking for idina menzel:\n");
  print_artists_songs(table, "idina menzel");
  printf("Looking for taylor swift:\n");
  print_artists_songs(table, "taylor swift");
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing printing out a list given a letter:\n\n");
  printf("print list for a:\n");
  print_songList(table, 'a');
  printf("print list for i:\n");
  print_songList(table, 'i');
  printf("print list for c:\n");
  print_songList(table, 'm');
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing printing out the whole library:\n");
  print_library(table);
  printf("\n");
  printf("========================================\n");
  printf("\n");

  printf("Testing shuffle:\n\n");
  shuffle(table);
  printf("\n");
  printf("========================================\n");
  printf("\n");
  
  printf("Testing deleting a song\n");
  printf("Deleting imagine dragons: time:\n");
  delete_song(table, "time", "imagine dragons");
  printf("i list: ");
  print_list(table[8]);
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing deleting EVERYTHING\n");
  delete_all(table);
  print_library(table);
 
  return 0;
}
