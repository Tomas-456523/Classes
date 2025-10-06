#include "media.h"
using namespace std;

#ifndef MUSIC
#define MUSIC
class Music : public Media {
public:
	Music();
	virtual ~Music();
	virtual char* getArtist();
	virtual char* getPublisher();
	virtual int getDuration();
	virtual void setArtist(char _artist[255]);
	virtual void setPublisher(char _publisher[255]);
	virtual void setDuration(int _duration);

	virtual void printSelf();
protected:
	char artist[255];
	char publisher[255];
	int duration;
};
#endif