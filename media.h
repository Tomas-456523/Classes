//header file for media parent class

using namespace std; //imports necessary module


#ifndef MEDIA //header guard to prevent redefinition errors
#define MEDIA
class Media {
public:
	Media(); //creation function
	virtual ~Media(); //virtual destructor function
	char* getType(); //returns the type of the media (eg. "movie")
	char* getTitle(); //returns the title of the media
	int getYear(); //returns the year of publication of the media
	void setTitle(char _title[255]); //sets the title to whatever the inputted char array was
	void setYear(int _year); //sets the year to the inputted value

	//the rest of these functions are not used by all subclasses, but must be defined here to be callable
	virtual char* getArtist();
	virtual char* getDirector();
	virtual char* getPublisher();
	virtual int getDuration();
	virtual char* getRating();

	virtual void setArtist(char _artist[255]);
	virtual void setDirector(char _director[255]);
	virtual void setPublisher(char _publisher[255]);
	virtual void setDuration(int _duration);
	virtual void setRating(char _rating[6]);

	virtual void printSelf();
protected:
	char type[6]; //the type of media that it is (eg. "vgame")
	char title[255]; //the title of the media
	int year; //the year of publication of the media
};
#endif