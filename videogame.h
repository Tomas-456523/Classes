#include "media.h"
using namespace std;

//header guard
#ifndef VIDEOGAME
#define VIDEOGAME
class VideoGame : public Media {
public:
	VideoGame();
	virtual ~VideoGame();
	virtual char* getPublisher();
	virtual char* getRating();
	virtual void setPublisher(char _publisher[255]);
	virtual void setRating(char _rating[6]);
protected:
	char publisher[255];
	char rating[6];
};
#endif