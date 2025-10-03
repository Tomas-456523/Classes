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
	virtual float getDuration();
	virtual void setArtist(char _artist[255]);
	virtual void setPublisher(char _publisher[255]);
	virtual void setDuration(float _duration);
protected:
	char artist[255];
	char publisher[255];
	float duration;
};
#endif