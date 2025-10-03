#include <cstring>
#include "videogame.h"
using namespace std;

VideoGame::VideoGame() {
	strcpy(type, "vgame\0");
}
char* VideoGame::getPublisher() {
	return publisher;
}
char* VideoGame::getRating() {
	return rating;
}
void VideoGame::setPublisher(char _publisher[255]) {
	strcpy(publisher, _publisher);
}
void VideoGame::setRating(char _rating[6]) {
	strcpy(rating, _rating);
}
VideoGame::~VideoGame() {

}