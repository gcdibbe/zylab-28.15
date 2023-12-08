#include <iostream>
#include <string>
using namespace std;

class PlaylistNode {
   private:
      string uniqueID; //initialized to "none" in default constructor
      string songName; //initialized to "none" in default constructor
      string artistName; //initialized to "none" in default constructor
      int songLength; //initialized to 0 in default constructor
      PlaylistNode* nextNodePtr; //initialized to 0 in default constructor
      
   public:
      PlaylistNode(); //default
      PlaylistNode(string userID, string userSong, string userArtist, int userLength); //parameterized
      string GetID();
      string GetSongName();
      string GetArtistName();
      int GetSongLength();
      PlaylistNode* GetNext();
      void InsertAfter(PlaylistNode* nodePtr);
      void SetNext(PlaylistNode* nodePtr);
      void PrintPlaylistNode();
};
