#include "media.h"
using namespace std;

#ifndef MOVIE
#define MOVIE
class Movie : public Media {
public:
	Movie();
	virtual ~Movie();
	virtual char* getDirector();
	virtual char* getRating();
	virtual int getDuration();
	virtual void setDirector(char _director[255]);
	virtual void setRating(char _rating[6]);
	virtual void setDuration(int _duration);

	virtual void printSelf();
protected:
	char director[255];
	char rating[6];
	int duration;
};
#endif