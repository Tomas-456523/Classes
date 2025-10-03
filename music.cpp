#include <cstring>
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
float Music::getDuration() {
	return duration;
}
void Music::setArtist(char _artist[255]) {
	strcpy(artist, _artist);
}
void Music::setPublisher(char _publisher[255]) {
	strcpy(publisher, _publisher);
}
void Music::setDuration(float _duration) {
	duration = _duration;
}
Music::~Music() {

}