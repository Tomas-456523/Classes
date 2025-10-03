using namespace std;

#ifndef MEDIA
#define MEDIA
class Media {
public:
	Media();
	virtual ~Media();
	char* getType();
	char* getTitle();
	int getYear();
	void setTitle(char _title[255]);
	void setYear(int _year);

	virtual char* getArtist();
	virtual char* getDirector();
	virtual char* getPublisher();
	virtual float getDuration();
	virtual char* getRating();

	virtual void setArtist(char _artist[255]);
	virtual void setDirector(char _director[255]);
	virtual void setPublisher(char _publisher[255]);
	virtual void setDuration(float _duration);
	virtual void setRating(char _rating[6]);
protected:
	char type[6];
	char title[255];
	int year;
};
#endif