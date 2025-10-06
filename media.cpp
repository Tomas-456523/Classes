#include <cstring>
#include "media.h"
using namespace std;

Media::Media() {
	strcpy(type, "media\0");
}
char* Media::getType() {
	return type;
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

char* Media::getArtist() {
	return NULL;
}
char* Media::getDirector() {
	return NULL;
}
char* Media::getPublisher() {
	return NULL;
}
int Media::getDuration() {
	return 0;
}
char* Media::getRating() {
	return NULL;
}
void Media::setArtist(char _artist[255]) {

}
void Media::setDirector(char _director[255]) {

}
void Media::setPublisher(char _publisher[255]) {

}
void Media::setDuration(int _duration) {

}
void Media::setRating(char _rating[6]) {

}
void Media::printSelf() {

}