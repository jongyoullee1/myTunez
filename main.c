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
  printf("Testing searching for songs by title:\n\n");
  printf("Finding \"twinkle twinkle\" in s:\n");
  print_song(find_song_name(s, "twinkle twinkle"));
  printf("Finding \"uuu\" in s:\n");
  print_song(find_song_name(s, "uuu"));
  printf("Finding \"doesn't exist boi\" in s:\n");
  print_song(find_song_name(s, "doesn't exist boi"));
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by artist:\n\n");
  printf("Finding guest's song in s:\n");
  print_song(find_song_artist(s, "guest"));
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
  printf("Removing uuu node:\n");
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
  
  printf("\n");
  printf("========================================\n");
  printf("Testing music library functions\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing adding songs:\n\n");
  printf("Adding aaa: mary had a little lamb to the library:\n");
  add_song(table, "mary had a little lamb", "aaa");
  printf("a list: ");
  print_list(table[0]);
  printf("Adding abb: baba black sheep to the library:\n");
  add_song(table, "baba black sheep", "abb");
  printf("a list: ");
  print_list(table[0]);
  printf("Adding bee: honey to the library:\n");
  add_song(table, "honey", "bee");
  printf("b list: ");
  print_list(table[1]);
  printf("Adding a: hhhhhhh to the library:\n");
  add_song(table, "hhhhhhh", "a");
  printf("a list: ");
  print_list(table[0]);
  printf("Adding aaa: ave maria to the library:\n");
  add_song(table, "ave maria", "aaa");
  printf("a list: ");
  print_list(table[0]);
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing searching for songs by title:\n\n");
  printf("Looking for honey by bee:\n");
  print_song(search_for_song(table, "honey", "bee"));
  printf("Looking for mary had a little lamb by aaa:\n");
  print_song(search_for_song(table, "mary had a little lamb", "aaa"));
  printf("\n");
  printf("========================================\n");
  printf("\n");

  /*
  printf("Testing searching for artist:\n\n");
  printf("Looking for aaa:\n");
  print_artists_songs(search_for_artist(table, "aaa"));
  printf("Looking for bee:\n");
  print_artists_songs(search_for_artist(table, "bee"));
  printf("Looking for box:\n");
  print_artists_songs(search_for_artist(table, "box"));
  printf("Looking for gg:\n");
  print_artists_songs(search_for_artist(table, "gg"));

  printf("\n");
  printf("========================================\n");
  printf("\n");
*/

  printf("Testing printing out a list given a letter:\n\n");
  printf("print list for a:\n");
  print_songList(table, 'a');
  printf("print list for b:\n");
  print_songList(table, 'b');
  printf("print list for c:\n");
  print_songList(table, 'c');

  printf("\n");
  printf("========================================\n");
  printf("\n");
  /*
  printf("Testing printing out the whole library:\n");
  print_library(table);
  */
  
  printf("Testing deleting a song\n");
  printf("Deleting aaa: ave maria:\n");
  delete_song(table, "ave maria", "aaa");
  print_list(table[0]);
  printf("\n");
  printf("========================================\n");
  printf("\n");
  printf("Testing deleting EVERYTHING\n");
  delete_all(table);
  print_library(table);


  return 0;
}
