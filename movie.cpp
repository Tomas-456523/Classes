#include <cstring>
#include <iostream>
#include "movie.h"
using namespace std;

Movie::Movie() {
	strcpy(type, "movie\0");
}
char* Movie::getDirector() {
	return director;
}
char* Movie::getRating() {
	return rating;
}
int Movie::getDuration() {
	return duration;
}
void Movie::setDirector(char _director[255]) {
	strcpy(director, _director);
}
void Movie::setRating(char _rating[6]) {
	strcpy(rating, _rating);
}
void Movie::setDuration(int _duration) {
	duration = _duration;
}
void Movie::printSelf() {
	cout << title << ", " << year << ", directed by " << director << ", rated " << rating << ", duration is " << duration / 60 << ":" << duration % 60;
}
Movie::~Movie() {

}