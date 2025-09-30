#include "media.h"
using namespace std;

#ifndef MOVIE
#define MOVIE
class Movie : public Media {
public:
	Movie();
	virtual ~Movie();
	char* getDirector();
	char* getRating();
	float getDuration();
	void setDirector(char _director[256]);
	void setRating(char _rating[6]);
	void setDuration(float _duration);
protected:
	char director[256];
	char rating[6];
	float duration;
};
#endif