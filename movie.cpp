#include <cstring>
#include "movie.h"
using namespace std;

Movie::Movie() {

}
char* Movie::getDirector() {
	return director;
}
char* Movie::getRating() {
	return rating;
}
float Movie::getDuration() {
	return duration;
}
void Movie::setDirector(char _director[256]) {
	strcpy(director, _director);
}
void Movie::setRating(char _rating[6]) {
	strcpy(rating, _rating);
}
void Movie::setDuration(float _duration) {
	duration = _duration;
}
Movie::~Movie() {

}