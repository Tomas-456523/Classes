#include "media.h"
using namespace std;

#ifndef MUSIC
#define MUSIC
class Music : public Media {
public:
	Music();
	virtual ~Music();
	char* getArtist();
	char* getPublisher();
	float getDuration();
	void setArtist(char _artist[256]);
	void setPublisher(char _publisher[256]);
	void setDuration(float _duration);
protected:
	char artist[256];
	char publisher[256];
	float duration;
};
#endif