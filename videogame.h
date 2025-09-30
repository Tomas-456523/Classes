#include "media.h"
using namespace std;

//header guard
#ifndef VIDEOGAME
#define VIDEOGAME
class VideoGame : public Media {
public:
	VideoGame();
	virtual ~VideoGame();
	char* getPublisher();
	char* getRating();
	void setPublisher(char _publisher[256]);
	void setRating(char _rating[5]);
protected:
	char publisher[256];
	char rating[5];
};
#endif