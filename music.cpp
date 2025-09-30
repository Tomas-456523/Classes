#include <cstring>
#include "music.h"
using namespace std;

Music::Music() {

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
void Music::setArtist(char _artist[256]) {
	strcpy(artist, _artist);
}
void Music::setPublisher(char _publisher[256]) {
	strcpy(publisher, _publisher);
}
void Music::setDuration(float _duration) {
	duration = _duration;
}
Music::~Music() {

}