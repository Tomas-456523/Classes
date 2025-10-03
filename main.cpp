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

void AllCaps(char* text) {
	for (int i = 0; i < strlen(text); i++) {
		text[i] = toupper(text[i]);
	}
}

void CinIgnoreAll() {
	if (!cin) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

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

		CinIgnoreAll();
	}

	//get the title of the media
	cout << "Enter the title.\n> ";
	char title[255];
	cin.getline(title, 255);
	(*newMedia).setTitle(title);
	
	CinIgnoreAll();

	//get the year of the data
	//IMPLEMENT THIS 
	
	//gets the type of the media because the rest of the data is type-specific
	char* type = newMedia->getType();
	
	//get artist for music
	if (!strcmp(type, "music")) {
		char artist[255];
		cout << "Enter the name of the artist.\n> ";
		cin.getline(artist, 255);
		(*newMedia).setArtist(artist);
	//get director for movie
	} else if (!strcmp(type, "movie")) {
		char director[255];
		cout << "Enter the name of the director.\n> ";
		cin.getline(director, 255);
		(*newMedia).setDirector(director);
	}
	CinIgnoreAll();

	//get publisher for videogames and music
	if (!strcmp(type, "vgame") || !strcmp(type, "music")) {
		char publisher[255];
		cout << "Enter the name of the publisher.\n> ";
		cin.getline(publisher, 255);
		(*newMedia).setPublisher(publisher);
	}
	CinIgnoreAll();

	//get duration for music and movies
	if (!strcmp(type, "music") || !strcmp(type, "movie")) {
		float duration = 0;
		while (duration == 0) {
			cout << "Enter the duration of the " << type << ".\n> ";
			cin >> duration;
			if (!cin) {
				cout << "\nInvalid input; must be a float.\n";
				CinIgnoreAll();
			} else if (duration <= 0) {
				cout << "\nInvalid input, must be greater than 0.\n";
			}
		}
		newMedia->setDuration(duration);
	}

	char rating[6];
	char* ratingPointer = &rating[0];
	bool continuing = true;

	//get rating for videogames
	if (!strcmp(type, "vgame")) {
		while (continuing) {
			cout << "Enter the rating (ESRB).\n> ";
			cin.getline(rating, 6);
			AllCaps(ratingPointer);
			if (strcmp(rating, "HELP")) {
				cout << "\nValid ratings: \nE - Everyone\nE10+ - Everyone 10 and up\nT - Teen\nM - Mature\nAO - Adults Only\nRP - Rating Pending\nRP17+ - Rating Pending; likely 17 and up\n\n";
			} else if (strcmp(rating, "E") && strcmp(rating, "E10+") && strcmp(rating, "T") && strcmp(rating, "M") && strcmp(rating, "AO") && strcmp(rating, "RP") && strcmp(rating, "RP17+")) {
				cout << "\nInvalid rating (type HELP for help).\n";
			} else {
				continuing = false;
			}
		}
		newMedia->setRating(rating);
	//get rating for movie (they use different rating systems unfortunately so that's why they use two different checks)
	} else if (!strcmp(type, "movie")) {
		while (continuing) {
			cout << "Enter the rating (MPAA).\n> ";
			cin.getline(rating, 6);
			AllCaps(ratingPointer);
			if (strcmp(rating, "HELP")) {
				cout << "\nValid ratings: \nG - General Audiences\nPG - Parental Guidance Suggested\nPG-13 - Parents Strongly Cautioned\nR - Restricted\nNC-17 - No one 17 and under admitted\n\n";
			}
			else if (strcmp(rating, "G") && strcmp(rating, "PG") && strcmp(rating, "PG-13") && strcmp(rating, "R") && strcmp(rating, "NC-17")) {
				cout << "\nInvalid rating (type HELP for help).\n";
			}
			else {
				continuing = false;
			}
		}
		newMedia->setRating(rating);
	}
}

void SearchMedia(vector<Media*>* mediaPointers) {
	//funny idea: if (no media is found) {cout << "*cricket noises*";}
}

void DeleteMedia(vector<Media*>* mediaPointers) {

}

int main() {
	vector<Media*>* mediaPointers = new vector<Media*>();

	char action[7];
	char* actionPointer = &action[0];

	bool continuing = true;
	while (continuing) {
		cout << "What would you like to do?\n> ";
		cin.getline(action, 7);

		AllCaps(actionPointer);
		
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

		CinIgnoreAll();
	}
	cout << "\nEnjoy your next 24 hours.";
}