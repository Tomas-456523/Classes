/* Tomas Carranza Echaniz
*  //
*  Yo check it out VS automatically adds these asterisks how amazing and incredible
* 
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <algorithm>
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

//returns true or false based on if the user responds y or n to the given question; copied and edited from my StudentList project
bool AskYN(char message[255]) {
	//repeats the question until the user gives a valid response
	bool continuing = true;
	char response[2]; 
	while (continuing) {
		cout << message << " (y/n)\n> "; //asks the question plus instructions on what to input
		cin.getline(response, 2);
		//error message if neither y or n entered
		if (strcmp(response, "y") && strcmp(response, "n")) {
			cout << "\nPlease answer either y or n.";
			CinIgnoreAll(); //clears error flag
		} else { //exit loop if y or n given
			continuing = false;
		}
	} //returns true if y or false if n
	CinIgnoreAll();
	if (strcmp(response, "n")) {
		return true;
	} return false;
}

void AddMedia(vector<Media*>* mediaPointers) {
	Media* newMedia = NULL;

	char action[10];
	char* actionPointer = &action[0];
	cout << "\n";
	
	while (newMedia == NULL) {
		cout << "Which kind of media would you like to add?\n> ";
		cin.getline(action, 10);

		AllCaps(actionPointer);

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
	newMedia->setTitle(title);
	
	CinIgnoreAll();

	//get the year of the data
	int year;
	bool continuing = true;
	while (continuing) {
		cout << "Enter the year of publication.\n> ";
		cin >> year;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (!cin) {
			cout << "\nInvalid input; must be an integer.\n";
			CinIgnoreAll();
		} else if (year <= 0) {
			cout << "\nInvalid input, must be greater than 0.\n";
		} else {
			continuing = false;
		}
	}
	newMedia->setYear(year);
	
	CinIgnoreAll();
	
	//gets the type of the media because the rest of the data is type-specific
	char* type = newMedia->getType();
	
	//get artist for music
	if (!strcmp(type, "music")) {
		char artist[255];
		cout << "Enter the name of the artist.\n> ";
		cin.getline(artist, 255);
		newMedia->setArtist(artist);
		CinIgnoreAll();
	//get director for movie
	} else if (!strcmp(type, "movie")) {
		char director[255];
		cout << "Enter the name of the director.\n> ";
		cin.getline(director, 255);
		newMedia->setDirector(director);
		CinIgnoreAll();
	}

	//get publisher for videogames and music
	if (!strcmp(type, "vgame") || !strcmp(type, "music")) {
		char publisher[255];
		cout << "Enter the name of the publisher.\n> ";
		cin.getline(publisher, 255);
		newMedia->setPublisher(publisher);
	}
	CinIgnoreAll();

	//get duration for music and movies
	if (!strcmp(type, "music") || !strcmp(type, "movie")) {
		continuing = true;
		int duration = 0;
		while (continuing) {
			cout << "Enter the duration of the " << type << " (seconds).\n> ";
			cin >> duration;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!cin) {
				cout << "\nInvalid input; must be an integer.\n";
				CinIgnoreAll();
			} else if (duration < 0) {
				cout << "\nInvalid input; must be at least 0.\n";
			} else {
				continuing = false;
			}
		}
		newMedia->setDuration(duration);
	}

	char rating[6];
	char* ratingPointer = &rating[0];
	continuing = true;

	//get rating for videogames
	if (!strcmp(type, "vgame")) {
		while (continuing) {
			cout << "Enter the rating (ESRB).\n> ";
			cin.getline(rating, 6);
			AllCaps(ratingPointer);
			if (!strcmp(rating, "HELP")) {
				cout << "\nValid ratings: \nE - Everyone\nE10+ - Everyone 10 and up\nT - Teen\nM - Mature\nAO - Adults Only\nRP - Rating Pending\nRP17+ - Rating Pending; likely 17 and up\n\n";
			} else if (strcmp(rating, "E") && strcmp(rating, "E10+") && strcmp(rating, "T") && strcmp(rating, "M") && strcmp(rating, "AO") && strcmp(rating, "RP") && strcmp(rating, "RP17+")) {
				cout << "\nInvalid rating (type HELP for help).\n";
				CinIgnoreAll();
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
			if (!strcmp(rating, "HELP")) {
				cout << "\nValid ratings:\nG - General Audiences\nPG - Parental Guidance Suggested\nPG-13 - Parents Strongly Cautioned\nR - Restricted\nNC-17 - No one 17 and under admitted\n\n";
			} else if (strcmp(rating, "G") && strcmp(rating, "PG") && strcmp(rating, "PG-13") && strcmp(rating, "R") && strcmp(rating, "NC-17")) {
				cout << "\nInvalid rating (type HELP for help).\n";
				CinIgnoreAll();
			} else {
				continuing = false;
			}
		}
		newMedia->setRating(rating);
	}

	CinIgnoreAll();
	mediaPointers->push_back(newMedia);
	cout << "\nMedia successfully added to database!\n";
}

vector<Media*> SearchMedia(vector<Media*>* mediaPointers) {
	vector<Media*> matches;
	char searchType[6];

	bool continuing = true;
	while (continuing) {
		cout << "\nEnter search type.\n> ";
		cin.getline(searchType, 6);
		AllCaps(searchType);

		CinIgnoreAll();
		if (!strcmp(searchType, "HELP")) {
			cout << "\nValid search types:\nTITLE\nYEAR\nALL\n";
		} else if (strcmp(searchType, "TITLE") && strcmp(searchType, "YEAR") && strcmp(searchType, "ALL")) {
			cout << "\nInvalid search type (type HELP for help).";
		} else {
			continuing = false;
		}
	}

	char title[255];
	int year;

	char* titlePointer = &title[0];
	char _title[255];
	char* _titlePointer = &_title[0];

	if (!strcmp(searchType, "TITLE")) {
		cout << "\nSearch for title.\n> ";
		cin.getline(title, 255);
		AllCaps(titlePointer);
		CinIgnoreAll();
	} else if (!strcmp(searchType, "YEAR")) {
		bool continuing = true;
		while (continuing) {
			cout << "Search for year.\n> ";
			cin >> year;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!cin) {
				cout << "\nInvalid input; must be an integer.\n";
				CinIgnoreAll();
			} else if (year <= 0) {
				cout << "\nInvalid input; must be greater than 0.\n";
			} else {
				continuing = false;
			}
		}
	}

	for (Media* mediaPointer : (*mediaPointers)) {
		strcpy(_title, mediaPointer->getTitle());
		AllCaps(_titlePointer);

		if (!strcmp(searchType, "TITLE") && !strcmp(_title, title)) {
			matches.push_back(mediaPointer);
		} else if (!strcmp(searchType, "YEAR") && mediaPointer->getYear() == year) {
			matches.push_back(mediaPointer);
		} else if (!strcmp(searchType, "ALL")) {
			matches.push_back(mediaPointer);
		}
	}

	return matches;
}

void DeleteMedia(vector<Media*>* mediaPointers) {
	vector<Media*> foundMedia = SearchMedia(mediaPointers);

	if (foundMedia.size() == 0) {
		cout << "\nNo matching media found.\n";
		return;
	}

	int i = 0;
	cout << "\nMatching media found:";
	for (Media* media : foundMedia) {
		i++;
		cout << "\n" << i << " - ";
		media->printSelf();
	}
	cout << "\n";

	int toDelID;
	bool continuing = true;
	while (continuing) {
		cout << "Choose media # to delete (0 to cancel).\n> ";
		cin >> toDelID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (!cin) {
			cout << "\nInvalid input; must be an integer.\n";
			CinIgnoreAll();
		} else if (toDelID == 0) {
			cout << "\nMedia deletion canceled.\n";
			return;
		} else if (toDelID < 0) {
			cout << "\nInvalid input; must be at least 0.\n";
		} else if (toDelID > i) {
			cout << "\nInvalid input; does not match any found media.\n";
		} else {
			continuing = false;
		}
	}

	Media* toDelMedia = foundMedia[toDelID-1];

	char message[255] = "\nAre you sure you would like to delete this media?";
	bool yesDelete = AskYN(message);

	if (yesDelete) {
		delete toDelMedia;
		mediaPointers->erase(remove(mediaPointers->begin(), mediaPointers->end(), toDelMedia), mediaPointers->end());
		foundMedia.erase(remove(foundMedia.begin(), foundMedia.end(), toDelMedia), foundMedia.end());
		cout << "\nMedia successfully deleted!\n";
	} else {
		cout << "\nMedia deletion canceled.\n";
	}
}

int main() {
	cout << "Marvelous morning. I am Media Manager Man.\nEnter HELP for help.\n\n";
	vector<Media*>* mediaPointers = new vector<Media*>();

	char action[7];
	char* actionPointer = &action[0];

	bool continuing = true;

	while (continuing) {
		cout << "What would you like to do?\n> ";
		cin.getline(action, 7);

		AllCaps(actionPointer);
		
		if (!strcmp(action, "HELP")) {
			cout << "\nAvailable commands:\nHELP\nADD\nSEARCH\nDELETE\nQUIT\n";
		} else if (!strcmp(action, "ADD")) {
			AddMedia(mediaPointers);
		} else if (!strcmp(action, "SEARCH")) {
			vector<Media*> foundMedia = SearchMedia(mediaPointers);

			int i = 0;
			cout << "\nMatching media found:";
			for (Media* media : foundMedia) {
				i++;
				cout << "\n" << i << " - ";
				media->printSelf();
			}
			if (foundMedia.size() == 0) {
				cout << "\n*cricket noises*";
			}
			cout << "\n\n";
		} else if (!strcmp(action, "DELETE")) {
			DeleteMedia(mediaPointers);
		} else if (!strcmp(action, "QUIT")) {
			continuing = false;
		} else {
			cout << "\nInvalid command\n";
		}

		CinIgnoreAll();
	}
	cout << "\nCheerio.";
}