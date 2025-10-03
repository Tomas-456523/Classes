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
	virtual float getDuration();
	virtual void setDirector(char _director[255]);
	virtual void setRating(char _rating[6]);
	virtual void setDuration(float _duration);
protected:
	char director[255];
	char rating[6];
	float duration;
};
#endif