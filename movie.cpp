//this file defines the movie subclass

#include <cstring> //imports necessary modules
#include <iostream>
#include "movie.h"
using namespace std;

//on creation, clarifies that this media is of type "movie"
Movie::Movie() {
	strcpy(type, "movie\0");
}
//movie objects have functions to get and set their director, rating, and duration
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
//prints its data (example: "Cool Moovy, 1985, directed by John Moovy, rated PG-13, duration is 180:04")
void Movie::printSelf() {
	//prints everything up to the minute count
	cout << title << ", " << year << ", directed by " << director << ", rated " << rating << ", duration is " << duration / 60 << ":";
	//if the second counter when ignoring minutes is less than 10, it would print as MM:S instead of MM:SS, so it would look weird. Thus, we print an extra 0
	if (duration % 60 < 10) {
		cout << "0";
	}//prints the seconds
	cout << duration % 60;
}
//destructor function
Movie::~Movie() {

}