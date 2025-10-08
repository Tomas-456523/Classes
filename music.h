//the header file for the music subclass

#include "media.h" //imports necessary modules
using namespace std;

#ifndef MUSIC //header guard to prevent redefinition errors
#define MUSIC
class Music : public Media {
public:
	Music(); //creation function
	virtual ~Music(); //virtual destructor function
	virtual char* getArtist(); //returns the artist who made the music
	virtual char* getPublisher(); //returns the publisher of the music
	virtual int getDuration(); //returns the duration (in seconds) of the music
	virtual void setArtist(char _artist[255]); //sets the artist to the input
	virtual void setPublisher(char _publisher[255]); //sets the publisher to the input
	virtual void setDuration(int _duration); //sets the duration to the input

	virtual void printSelf(); //prints all of this music's data
protected:
	char artist[255]; //the name of the artist who made the music
	char publisher[255]; //the name of the publisher who published the music
	int duration; //how long the music lasts in seconds
};
#endif