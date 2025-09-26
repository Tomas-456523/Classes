using namespace std;

class Media {
public:
	Media();
	virtual ~Media();
	char* getTitle();
	int getYear();
protected:
	char* title;
	int year;
};