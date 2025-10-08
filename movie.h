//the header file for the movie subclass

#include "media.h" //imports necessary modules
using namespace std;

#ifndef MOVIE //header guard to prevent redefinition errors
#define MOVIE
class Movie : public Media {
public:
	Movie(); //the creation function
	virtual ~Movie(); //virtual destructor function
	virtual char* getDirector(); //returns the director of the movie
	virtual char* getRating(); //returns the rating of the movie
	virtual int getDuration(); //returns the duration of the movie in seconds
	virtual void setDirector(char _director[255]); //sets the director of the movie to the inputted char array
	virtual void setRating(char _rating[6]); //sets the rating of the movie to the input
	virtual void setDuration(int _duration); //sets the duration of the movie to the input

	virtual void printSelf(); //prints all the data of the movie object
protected:
	char director[255]; //the name of the director who directed the movie
	char rating[6]; //the rating of the movie (MPAA)
	int duration; //the duration of the movie (in seconds)
};
#endif