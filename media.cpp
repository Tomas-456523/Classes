//this file defines the main parent media class

#include <cstring> //import necessary modules
#include "media.h"
using namespace std;

//on creation, clarifies that this is type "media"
Media::Media() {
	strcpy(type, "media\0");
}
//these are functions that every subclass has
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
//destructor function
Media::~Media() {
	
}
//these are all placeholder functions that the subclasses may use
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
//prints all of the object's data, formatted differently by each subclass
void Media::printSelf() {

}