//URL for Github repository: 
//Team member 1: Gabriella Doan

#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {   
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   string userID, userSong, userArtist;
   int userLength;
   
   PlaylistNode* currNode;
   PlaylistNode* lastNode;
   
   headNode = new PlaylistNode();
   lastNode = headNode; //currently the last node in linked list
   
   if(option == 'q') {
      return headNode;
   }
   else if(option =='a') {
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> userID;
      cout << "Enter song's name:" << endl;
      cin >> userSong;
      cout << "Enter artist's name:" << endl;
      cin >> userArtist;
      cout << "Enter song's length:" << endl;
      cin >> userLength;
      
      currNode = new PlaylistNode(userID, userSong, userArtist, userLength);
      lastNode->SetNext(currNode);
      lastNode = currNode;
   }
   else if(option == 'd') {
      currNode = headNode;
      string artist;
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> artist;
      
      while(currNode->GetNext() != NULL) {
         if(currNode->GetArtistName() == artist) {
            currNode->PrintPlaylistNode();
         }
         currNode = currNode->GetNext();
      }
   }
   else if(option == 's') {
      currNode = headNode;
      string artist;
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:" << endl;
      cin >> artist;
      
      while(currNode->GetNext() != NULL) {
         if(currNode->GetArtistName() == artist) {
            currNode->PrintPlaylistNode();
         }
         currNode = currNode->GetNext();
      }
   }
   else if(option == 't') {
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      currNode = headNode;
      int sum;
      
      while(currNode->GetNext() != NULL) {
         sum = sum + currNode->GetSongLength();
         currNode = currNode->GetNext();
      }
      
      cout << "Total time: " << sum << " seconds" << endl;
   }
   else if(option == 'o') {
      currNode = headNode;
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      while(currNode->GetNext() != NULL) {
         currNode->PrintPlaylistNode();
         currNode = currNode->GetNext();
      }
   }/*
   cout << "Choose an option:" << endl;
   cin >> option;
   return ExecuteMenu(option, playlistTitle, headNode);*/
}

int main() {
   string playlistTitle;
   char option;
   
   PlaylistNode* headNode = new PlaylistNode();
   
   cout << "Enter playlist's title:" << endl << endl;
   getline(cin, playlistTitle);
   PrintMenu(playlistTitle);
   
   cout << endl ;
   cout << "Choose an option:" << endl;
   cin >> option;

   headNode = ExecuteMenu(option, playlistTitle, headNode);
   
   return 0;
}
