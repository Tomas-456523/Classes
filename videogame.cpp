//this file defines the videogame subclass

#include <cstring> //imports necessary modules
#include <iostream>
#include "videogame.h"
using namespace std;

//on creation, clarifies that this is of type "vgame" which is shortened from videogame to make the length of the type consistent
VideoGame::VideoGame() {
	strcpy(type, "vgame\0");
}
//videogames have functions to get and set their publisher and rating
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
//prints all of its data (example: "Minecraft, 2009, published by Mojang, rated E10+")
void VideoGame::printSelf() {
	cout << title << ", " << year << ", published by " << publisher << ", rated " << rating;
}
//destructor function
VideoGame::~VideoGame() {

}