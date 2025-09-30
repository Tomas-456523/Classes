using namespace std;

#ifndef MEDIA
#define MEDIA
class Media {
public:
	Media();
	virtual ~Media();
	char* getTitle();
	int getYear();
	void setTitle(char _title[256]);
	void setYear(int _year);
protected:
	char title[256];
	int year;
};
#endif