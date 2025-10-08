//the header file for the videogame subclass

#include "media.h" //imports necessary modules
using namespace std;

#ifndef VIDEOGAME //header guard to prevent redefinition errors
#define VIDEOGAME
class VideoGame : public Media {
public:
	VideoGame(); //creation function
	virtual ~VideoGame(); //virtual destructor function
	virtual char* getPublisher(); //returns the publisher of the game
	virtual char* getRating(); //returns the rating of the game
	virtual void setPublisher(char _publisher[255]); //sets the publisher to whatever the input was
	virtual void setRating(char _rating[6]); //sets the rating to the input

	virtual void printSelf(); //prints all the data of the video game
protected:
	char publisher[255]; //the publisher of the video game
	char rating[6]; //what the game is rated (ESRB)
};
#endif