#include <cstring>
#include <iostream>
#include "music.h"
using namespace std;

Music::Music() {
	strcpy(type, "music\0");
}
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
void Music::printSelf() {
	cout << title << ", " << year << ", made by " << artist << "published by " << publisher << ", duration is " << duration/60 << ":" << duration%60;
}
Music::~Music() {

}