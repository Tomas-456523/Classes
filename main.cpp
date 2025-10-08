/* Tomas Carranza Echaniz
*  10/8/25
*  This program is used to manage a media database.  Available media types are video
*  games, which have a publisher and a rating, music, which has a publisher, duration,
*  and artist, and movies, which have a director, duration, and rating. All media types
*  have a title and year in addition. Available commands to manage the database are
*  add, search, and delete. When adding a new media, the user is prompted to enter all
*  the data associated with the chosen media type. When searching, you can search by
*  title, year, or you can just see all media saved. When deleting a file, you go through
*  the same process as searching, but you then choose a file and are then asked to
*  confirm if you want to delete it. You can also quit or ask for help (help command can
*  be used throughout the whole program wherever clarification may be necessary).
*/

#include <iostream> //imports necessary modules and classes
#include <vector>
#include <cstring>
#include <limits>
#include <algorithm>
#include "media.h"
#include "videogame.h"
#include "music.h"
#include "movie.h"
using namespace std;

//takes a pointer to a char array as input, and capitalizes all the characters in it. Used for easier string comparison.
void AllCaps(char* text) {
	for (int i = 0; i < strlen(text); i++) {
		text[i] = toupper(text[i]);
	}
}

//clears error flags and extra input text; copied from my previous projects. I use this basically everywhere after cin to be completely sure buffer overflows don't happen
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
		}
		else { //exit loop if y or n given
			continuing = false;
		}
	} //returns true if y or false if n
	CinIgnoreAll();
	if (strcmp(response, "n")) {
		return true;
	} return false;
}

//function to create media and add it to the database
void AddMedia(vector<Media*>* mediaPointers) {
	//creates a null media pointer because we don't know what type of media the user will choose yet
	Media* newMedia = NULL;

	//creates a char array for the user to input into, and a pointer to it (just so I can put it into AllCaps())
	char action[10];
	char* actionPointer = &action[0];
	cout << "\n"; //prints new line for formatting

	//repeats the media selection loop until the user selects a valid media type
	while (newMedia == NULL) {
		cout << "Which kind of media would you like to add?\n> ";
		cin.getline(action, 10); //gets input from the user up until the next new line

		AllCaps(actionPointer); //capitalizes the input for simpler comparison

		//assigns a type of media to newMedia based on the input
		if (!strcmp(action, "VIDEOGAME")) {
			newMedia = new VideoGame();
		}
		else if (!strcmp(action, "MUSIC")) {
			newMedia = new Music();
		}
		else if (!strcmp(action, "MOVIE")) {
			newMedia = new Movie();
			//gives the list of valid media types and commands if the user asks for help
		}
		else if (!strcmp(action, "HELP")) {
			cout << "\nMedia types: \nVIDEOGAME\nMUSIC\nMOVIE\n\nAvailable actions:\nHELP for help.\nNEVERMIND if you decided to not add media.\n\n";
			//the user can change their mind if they actually didn't want to add new media
		}
		else if (!strcmp(action, "NEVERMIND")) {
			return;
		}
		else { //gives an error message for invalid inputs
			cout << "\nInvalid media type.\n";
		}

		CinIgnoreAll(); //clears error flags if the user gave too long input
	}

	//get the title of the media
	cout << "Enter the title.\n> ";
	char title[255];
	cin.getline(title, 255);
	newMedia->setTitle(title); //add the title to the media file

	CinIgnoreAll(); //clears error flags for if the user inputted more than 254 characters

	//get the year of the data
	int year;
	bool continuing = true;
	//continues until the user gives a valid year
	while (continuing) {
		cout << "Enter the year of publication.\n> ";
		cin >> year; //integers cannot use getline so I have to use the normal method
		//using cin >> var keeps the new line, skipping the next prompt, so I have to clear it here
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (!cin) { //gives error message if input was invalid
			cout << "\nInvalid input; must be an integer.\n";
			//there is actually no year 0 in the gregorian calendar, so it must be greater than that. I also can't recall any video games, digital music, or movies made before Christ either, so no negative years.
		}
		else if (year <= 0) {
			cout << "\nInvalid input, must be greater than 0.\n";
		}
		else { //leaves the loop if input was valid
			continuing = false;
		}
		CinIgnoreAll(); //clears any error flags that may have arisen
	}
	newMedia->setYear(year); //pushes the year to the media file

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
	}
	else if (!strcmp(type, "movie")) {
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
		continuing = true; //continues until a valid duration is entered
		int duration = 0;
		while (continuing) {
			cout << "Enter the duration of the " << type << " (seconds).\n> ";
			cin >> duration;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores the newline character
			if (!cin) { //gives error message if non-integer entered (including if it's an int over the 32-bit int limit)
				cout << "\nInvalid input; must be an integer.\n";
				CinIgnoreAll(); //clears error flag
			}
			else if (duration < 0) { //media cannot last for a negative amount of time as far as I can tell
				cout << "\nInvalid input; must be at least 0.\n";
			}
			else { //leaves the duration setting loop when a valid duration is given
				continuing = false;
			}
		}//pushes the duration to the media file
		newMedia->setDuration(duration);
	}

	//creates a char array to input rating into and a pointer so it can be passed into AllCaps()
	char rating[6];
	char* ratingPointer = &rating[0];
	continuing = true;

	//get rating for videogames
	if (!strcmp(type, "vgame")) {
		while (continuing) { //continues until the user gives a valid rating
			cout << "Enter the rating (ESRB).\n> ";
			cin.getline(rating, 6);
			AllCaps(ratingPointer); //capitalizes it because none of the ratings have lowercase characters anyway
			if (!strcmp(rating, "HELP")) { //when asked for help, gives a list of valid ratings and what they mean
				cout << "\nValid ratings: \nE - Everyone\nE10+ - Everyone 10 and up\nT - Teen\nM - Mature\nAO - Adults Only\nRP - Rating Pending\nRP17+ - Rating Pending; likely 17 and up\n\n";
				//gives error message for invalid input
			}
			else if (strcmp(rating, "E") && strcmp(rating, "E10+") && strcmp(rating, "T") && strcmp(rating, "M") && strcmp(rating, "AO") && strcmp(rating, "RP") && strcmp(rating, "RP17+")) {
				cout << "\nInvalid rating (type HELP for help).\n";
				CinIgnoreAll(); //clears error flag
			}
			else { //leaves the loop once a valid rating has been given
				continuing = false;
			}
		} //pushes the rating to the media file
		newMedia->setRating(rating);
		//get rating for movie (they use different rating systems unfortunately so that's why they use two different checks)
	}
	else if (!strcmp(type, "movie")) {
		while (continuing) { //continues until the user gives a valid rating
			cout << "Enter the rating (MPAA).\n> ";
			cin.getline(rating, 6);
			AllCaps(ratingPointer); //capitalizes it because none of the ratings have lowercase characters
			if (!strcmp(rating, "HELP")) { //when asked for help, gives a list of valid ratings and what they mean
				cout << "\nValid ratings:\nG - General Audiences\nPG - Parental Guidance Suggested\nPG-13 - Parents Strongly Cautioned\nR - Restricted\nNC-17 - No one 17 and under admitted\n\n";
				//gives error message for invalid input
			}
			else if (strcmp(rating, "G") && strcmp(rating, "PG") && strcmp(rating, "PG-13") && strcmp(rating, "R") && strcmp(rating, "NC-17")) {
				cout << "\nInvalid rating (type HELP for help).\n";
				CinIgnoreAll(); //clears error flag
			}
			else { //leaves the loop once a valid rating has been given
				continuing = false;
			}
		} //pushes the rating to the media file
		newMedia->setRating(rating);
	}

	CinIgnoreAll(); //clears any extra characters that may remain
	//adds the newly created media to the vector of media
	mediaPointers->push_back(newMedia);
	//success message
	cout << "\nMedia successfully added to database!\n";
}

//function to search for media files, and returns a vector of all found files
vector<Media*> SearchMedia(vector<Media*>* mediaPointers) {
	//the vector of found media to be returned
	vector<Media*> matches;
	//what type of search the user tries to use (title, year, or all)
	char searchType[6];

	//continues until a valid search type is given
	bool continuing = true;
	while (continuing) {
		cout << "\nEnter search type.\n> ";
		cin.getline(searchType, 6);
		AllCaps(searchType); //capitalizes the search type for easier comparison

		CinIgnoreAll(); //clears any potential extra characters
		if (!strcmp(searchType, "HELP")) { //gives a list of valid search types when prompted for help
			cout << "\nValid search types:\nTITLE\nYEAR\nALL\n";
			//gives error message when something invalid is given
		}
		else if (strcmp(searchType, "TITLE") && strcmp(searchType, "YEAR") && strcmp(searchType, "ALL")) {
			cout << "\nInvalid search type (type HELP for help).";
		}
		else { //leaves the loop when a valid search type is given
			continuing = false;
		}
	}

	//creates input for both title and year, since I can't create them in an if statement because then they'd only be valid until the end of the if block
	char title[255];
	int year;

	//creates a pointer to the searched title for capitalization
	char* titlePointer = &title[0];
	//the titles of the media are copied into this char*; this way, I can capitalize it for easier comparison without affecting the actual file, since AllCaps() uses pointers
	char _title[255];
	char* _titlePointer = &_title[0];

	//asks the user for either a title or year to search for based on which one the user may have chosen
	if (!strcmp(searchType, "TITLE")) {
		cout << "\nSearch for title.\n> ";
		cin.getline(title, 255);
		AllCaps(titlePointer);
		CinIgnoreAll();
	}
	else if (!strcmp(searchType, "YEAR")) {
		bool continuing = true; //loops until a valid year is given
		while (continuing) {
			cout << "Search for year.\n> ";
			cin >> year;
			//clears the extra character after the int
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (!cin) { //gives error message for non-int input
				cout << "\nInvalid input; must be an integer.\n";
				CinIgnoreAll(); //clears error flag
			}
			else if (year <= 0) { //years <= 0 are not allowed, so it's not allowed to search for that either because it wouldn't return anything
				cout << "\nInvalid input; must be greater than 0.\n";
			}
			else { //leaves the loop when valid year given
				continuing = false;
			}
		}
	}

	//loops through all the media in the database and adds them to the found media vector if they match whatever the user used to search
	for (Media* mediaPointer : (*mediaPointers)) {
		//search by title
		if (!strcmp(searchType, "TITLE")) {
			//gets the title of the current media and capitalizes it
			strcpy(_title, mediaPointer->getTitle());
			AllCaps(_titlePointer);
			//if the title matches (case-insensitive), the media is pushed to the matches vector
			if (!strcmp(_title, title)) {
				matches.push_back(mediaPointer);
			}
			//if we're searching by year and the years match, we add it to the matches vector
		}
		else if (!strcmp(searchType, "YEAR") && mediaPointer->getYear() == year) {
			matches.push_back(mediaPointer);
			//if the user is searching for all media, we just add the media no matter what
		}
		else if (!strcmp(searchType, "ALL")) {
			matches.push_back(mediaPointer);
		}
	}

	//returns the vector of matching media
	return matches;
}

//finds a media to delete using the search functionality, with the difference that the user can then choose to delete a found file
void DeleteMedia(vector<Media*>* mediaPointers) {
	//uses SearchMedia() to find the files the user may want to delete
	vector<Media*> foundMedia = SearchMedia(mediaPointers);

	//we can't delete anything if nothing was found, so we give an error message and leave
	if (foundMedia.size() == 0) {
		cout << "\nNo matching media found.\n";
		return;
	}

	//prints out a list of all found media, along with an associated number using i
	int i = 0;
	cout << "\nMatching media found:";
	for (Media* media : foundMedia) {
		i++; //increments i and uses it to label the current media
		cout << "\n" << i << " - ";
		media->printSelf();
	}
	cout << "\n"; //formatting

	//the id of the media to be deleted
	int toDelID;
	//continues until a valid media id is given
	bool continuing = true;
	while (continuing) {
		cout << "Choose media # to delete (0 to cancel).\n> ";
		cin >> toDelID;
		//ignores the newline character after the int
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (!cin) { //gives error message if non-int was given
			cout << "\nInvalid input; must be an integer.\n";
			CinIgnoreAll(); //clears error flag
		}
		else if (toDelID == 0) { //the user can input 0 if they decide not to delete anything
			cout << "\nMedia deletion canceled.\n";
			return; //leaves the function since we're no longer deleting anything
		}
		else if (toDelID < 0) { //there are no negative ids, so we give error message if one is given
			cout << "\nInvalid input; must be at least 0.\n";
		}
		else if (toDelID > i) { //we give error message if the id given is higher than any of the valid ids
			cout << "\nInvalid input; does not match any found media.\n";
		}
		else { //we leave the loop when input was valid
			continuing = false;
		}
	}

	//uses the id to find the media file to delete (subtracts 1 since vectors start at 0, but the id list started at 1)
	Media* toDelMedia = foundMedia[toDelID - 1];

	//user must give final confirmation they want to delete the file
	char message[255] = "\nAre you sure you would like to delete this media?";
	//I wasn't sure what to name this variable but this works I think
	bool yesDelete = AskYN(message); //user must input y or n to decide to delete the file or not

	if (yesDelete) { //if the user confirmed their decision to delete the file
		delete toDelMedia; //deletes the file associated with the media pointer
		//removes the pointer from both vectors that had the media in it
		mediaPointers->erase(remove(mediaPointers->begin(), mediaPointers->end(), toDelMedia), mediaPointers->end());
		foundMedia.erase(remove(foundMedia.begin(), foundMedia.end(), toDelMedia), foundMedia.end());
		//success message!
		cout << "\nMedia successfully deleted!\n";
	}
	else {
		//gives confirmation message for if the user decided to not delete the media
		cout << "\nMedia deletion canceled.\n";
	}
}

//the main loop
int main() {
	//greets the user and notifies them of the help feature
	cout << "Marvelous morning. I am Media Manager Man.\nEnter HELP for help.\n\n";
	//creates the vector that the media pointers are to be stored in
	vector<Media*>* mediaPointers = new vector<Media*>();

	//the char array that the user inputs into
	char action[7];
	//creates a pointer to the action so that it can be capitalized using AllCaps()
	char* actionPointer = &action[0];

	//main loop continues until the user enters quit
	bool continuing = true;
	while (continuing) {
		//asks the user what they would like to do
		cout << "What would you like to do?\n> ";
		cin.getline(action, 7); //gets the input up until the newline character
		//capitalies the action string for easier comparison
		AllCaps(actionPointer);

		//prints a list of available commands when the user asks for
		if (!strcmp(action, "HELP")) {
			cout << "\nAvailable commands:\nHELP\nADD\nSEARCH\nDELETE\nQUIT\n";
			//starts the media adding process when the user eneters add
		}
		else if (!strcmp(action, "ADD")) {
			AddMedia(mediaPointers);
			//searches for media when the user enters search
		}
		else if (!strcmp(action, "SEARCH")) {
			//creates a vector for found media to be put into, and calls the search function
			vector<Media*> foundMedia = SearchMedia(mediaPointers);

			//gives a list of found media and adds a number id to each media (for better readability)
			int i = 0;
			cout << "\nMatching media found:";
			for (Media* media : foundMedia) {
				i++; //increments i and uses that to give each media a unique id
				cout << "\n" << i << " - ";
				media->printSelf();
			} //prints "error" message when nothing was found
			if (foundMedia.size() == 0) {
				cout << "\n*cricket noises*";
			}
			cout << "\n\n"; //formatting!
			//starts the media deletion process when delete is entered
		}
		else if (!strcmp(action, "DELETE")) {
			DeleteMedia(mediaPointers);
			//ends the loop when quit is entered
		}
		else if (!strcmp(action, "QUIT")) {
			continuing = false;
		}
		else { //gives error message when invalid command is entered
			cout << "\nInvalid command (type HELP for help).\n";
		}

		CinIgnoreAll(); //ignores any extra characters that may have been entered to avoid buffer overflows
	}
	//deallocates media pointers
	delete mediaPointers;
	//says bye to the user
	cout << "\nCheerio.";
}