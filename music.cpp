//this file defines the music subclass

#include <cstring> //imports necessary modules
#include <iostream>
#include "music.h"
using namespace std;

//when music is created, clarifies that this media is of type "music"
Music::Music() {
	strcpy(type, "music\0");
}
//music objects have functions to get and set their artist, publisher, and duration
char* Music::getArtist() {
	return artist;
}
char* Music::getPublisher() {
	return publisher;
}
int Music::getDuration() {
	return duration;
}
void Music::setArtist(char _artist[255]) {
	strcpy(artist, _artist);
}
void Music::setPublisher(char _publisher[255]) {
	strcpy(publisher, _publisher);
}
void Music::setDuration(int _duration) {
	duration = _duration;
}
//prints its data (example: "The Best Song, 2005, made by Jimmy John, published by Big Music, duration is 3:22")
void Music::printSelf() {
	//prints everything up to the minute count
	cout << title << ", " << year << ", made by " << artist << ", published by " << publisher << ", duration is " << duration/60 << ":";
	//if the second counter when ignoring minutes is less than 10, it would print as MM:S instead of MM:SS, so it would look weird. Thus, we print an extra 0
	if (duration % 60 < 10) {
		cout << "0";
	}//prints the seconds
	cout << duration % 60;
}
//destructor function
Music::~Music() {

}