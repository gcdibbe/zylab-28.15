#include "PlaylistNode.h"

PlaylistNode::PlaylistNode() {
   this->uniqueID = "none"; //initialized to "none" in default constructor
   this->songName = "none"; //initialized to "none" in default constructor
   this->artistName = "none"; //initialized to "none" in default constructor
   this->songLength = 0; //initialized to 0 in default constructor
   this->nextNodePtr = NULL; //initialized to 0 in default constructor
}

PlaylistNode::PlaylistNode(string userID, string userSong, string userArtist, int userLength) {
   this->uniqueID = userID;
   this->songName = userSong;
   this->artistName = userArtist;
   this->songLength = userLength;
   this->nextNodePtr = NULL;
}

string PlaylistNode::GetID()  {return this->uniqueID; }
string PlaylistNode::GetSongName()  {return this->songName;  } 
string PlaylistNode::GetArtistName()   {return this->artistName;   }
int PlaylistNode::GetSongLength()   {return this->songLength;  }
PlaylistNode* PlaylistNode::GetNext()  {return this->nextNodePtr; }

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
   PlaylistNode* tempNext;
   tempNext = this->nextNodePtr;
   this->nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = tempNext;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
   this->nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
   cout << "Unique ID: " << this->uniqueID << endl;
   cout << "Song Name: " << this->songName << endl;
   cout << "Artist Name: " << this->artistName << endl;
   cout << "Song Length (in seconds): " << this->songLength << endl;
}
