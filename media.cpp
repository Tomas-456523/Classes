#include <cstring>
#include "media.h"
using namespace std;

Media::Media() {
	//strcpy(title, "a\0");
	//year = 0;
}
char* Media::getTitle() {
	return title;
}
int Media::getYear() {
	return year;
}
void Media::setTitle(char _title[255]) {
	strcpy(title, _title);
}
void Media::setYear(int _year) {
	year = _year;
}
Media::~Media() {
	
}