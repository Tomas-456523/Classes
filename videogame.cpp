#include <cstring>
#include "videogame.h"
using namespace std;

VideoGame::VideoGame() {
	
}
char* VideoGame::getPublisher() {
	return publisher;
}
char* VideoGame::getRating() {
	return rating;
}
void VideoGame::setPublisher(char _publisher[256]) {
	strcpy(publisher, _publisher);
}
void VideoGame::setRating(char _rating[5]) {
	strcpy(rating, _rating);
}
VideoGame::~VideoGame() {

}