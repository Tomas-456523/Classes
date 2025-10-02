/* Tomas Carranza Echaniz
*  //
*  Yo check it out VS automatically adds these asterisks how amazing and incredible
* 
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include "media.h"
#include "videogame.h"
#include "music.h"
#include "movie.h"
using namespace std;

void AddMedia(vector<Media*>* mediaPointers) {
	Media* newMedia;

	char action[10];
	cout << "\n";
	
	while (newMedia == NULL) {
		cout << "Which kind of media would you like to add?\n> ";
		cin.getline(action, 10);

		for (int i = 0; i < strlen(action); i++) {
			action[i] = toupper(action[i]);
		}

		if (!strcmp(action, "VIDEOGAME")) {
			newMedia = new VideoGame();
		} else if (!strcmp(action, "MUSIC")) {
			newMedia = new Music();
		} else if (!strcmp(action, "MOVIE")) {
			newMedia = new Movie();
		} else if (!strcmp(action, "HELP")) {
			cout << "\nMedia types: \nVIDEOGAME\nMUSIC\nMOVIE\n\nAvailable actions:\nHELP for help.\nNEVERMIND if you decided to not add media.\n\n";
		} else if (!strcmp(action, "NEVERMIND")) {
			return;
		} else {
			cout << "\nInvalid media type.\n";
		}

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	char title[255];
	cin.getline(title, 255);
	(*newMedia).setTitle(title);

	cout << (*newMedia).getTitle();
}

void SearchMedia(vector<Media*>* mediaPointers) {
	//funny idea: if (no media is found) {cout << "*cricket noises*";}
}

void DeleteMedia(vector<Media*>* mediaPointers) {

}

int main() {
	vector<Media*>* mediaPointers = new vector<Media*>();

	char action[7];
	bool continuing = true;
	while (continuing) {
		cout << "What would you like to do?\n> ";
		cin.getline(action, 7);

		for (int i = 0; i < strlen(action); i++) {
			action[i] = toupper(action[i]);
		}
		
		if (!strcmp(action, "ADD")) {
			AddMedia(mediaPointers);
		} else if (!strcmp(action, "SEARCH")) {
			SearchMedia(mediaPointers);
		} else if (!strcmp(action, "DELETE")) {
			DeleteMedia(mediaPointers);
		} else if (!strcmp(action, "QUIT")) {
			continuing = false;
		} else {
			cout << "\nInvalid command\n";
		}

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << "\nEnjoy your next 24 hours.";
}