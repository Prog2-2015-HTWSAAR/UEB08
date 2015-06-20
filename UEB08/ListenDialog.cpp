/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file  ListenDialog.cpp
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @date 14.06.2015
*/
#include "ListenDialog.h"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>

//Konstanten 
//Seperators
const char* ListenDialog::SPACER = " ";
//AUTO_TEST
const char* ListenDialog::AUTOMATIC_TEST_HYPHEN = "- ";
const char* ListenDialog::AUTOMATIC_TEST_POSITION = " POSITION: ";
const char* ListenDialog::AUTOMATIC_TEST_INIT = "-PUSH BACK(INIT)VALUE: ";
const char* ListenDialog::AUTOMATIC_TEST_PUSH_BACK = "-PUSH BACK VALUE: ";
const char* ListenDialog::AUTOMATIC_TEST_PUSH_FRONT = "-PUSH FRONT VALUE: ";
const char* ListenDialog::AUTOMATIC_TEST_POP_BACK = "-POP BACK-";
const char* ListenDialog::AUTOMATIC_TEST_POP_FRONT = "-POP FRONT-";
const char* ListenDialog::AUTOMATIC_TEST_INSERT = "-INSERT VALUE: ";
const char* ListenDialog::AUTOMATIC_TEST_ERASE = "-ERASE POSITION: ";
const char* ListenDialog::AUTOMATIC_TEST_INPUT_STREAM = "-READ INPUT STREAM-";
const char* ListenDialog::AUTOMATIC_TEST_CLEAR = "-CLEAR-";
const char* ListenDialog::AUTOMATIC_TEST_POP_EMPTY_LIST = "-POP EMPTY LIST-";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INIT = "INIT";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_BACK = "BACK";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_FRONT = "FRONT";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INSERT = "IMHERE";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INSERT_HIGH = "HIGH";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INSERT_LOW = "LOW";
const char* ListenDialog::AUTOMATIC_TEST_EINGABE_STREAM = "-INPUT STREAM VALUE: ";
const char* ListenDialog::AUTOMATIC_TEST_EINGABE_STREAM_VALUE = "A B C D NIL";


const string ListenDialog::LANGUAGE_GERMAN = "de_DE.lang";
const string ListenDialog::LANGUAGE_ENGLISH = "en_US.lang";
const string ListenDialog::LANGUAGE_HODOR = "hodor_WESTEROS.lang";
const string ListenDialog::LANGUAGE_STD = "std.lang";
const string ListenDialog::PARSER_READ_END = "<END>";
// const strings
// Languagedialog
const string ListenDialog::STD_LANG_NOT_FOUND = "Language std NOT Found";
const string ListenDialog::DE_DE_LANG_NOT_FOUND = "<DE_DE_LANG_NOT_FOUND>";
const string ListenDialog::EN_US_LANG_NOT_FOUND = "<EN_US_LANG_NOT_FOUND>";
const string ListenDialog::HODOR_WESTEROS_LANG_NOT_FOUND = "<HODOR_WESTEROS_LANG_NOT_FOUND>";
const string ListenDialog::PARSE_LANGUAGEDIALOG = "<LANGUAGE_DIALOGE>";

// Maindialog
const string ListenDialog::PARSE_SEPERATOR_LINLIST_BLOCK = "<SEPERATOR_LINLIST_BLOCK>";
const string ListenDialog::PARSE_MAINDIALOG = "<MAINDIALOG>";

//ManuellDialog
const string ListenDialog::PARSE_MANUELLDIALOG = "<MANUELLDIALOG>";
const string ListenDialog::PARSE_SEPERATOR_MANUELL_BLOCK = "<SEPERATOR_MANUELL_BLOCK>";
const string ListenDialog::PARSE_SEPERATOR_INSERT = "<SEPERATOR_INSERT>";
const string ListenDialog::PARSE_SEPERATOR_ERASE = "<SEPERATOR_ERASE>";
const string ListenDialog::PARSE_SEPERATOR_CLEAR = "<SEPERATOR_CLEAR>";
const string ListenDialog::PARSE_SEPERATOR_PUSH = "<SEPERATOR_PUSH>";
const string ListenDialog::PARSE_SEPERATOR_POP = "<SEPERATOR_POP>";
const string ListenDialog::PARSE_SEPERATOR_BACKUP = "<SEPERATOR_BACKUP>";
const string ListenDialog::PARSE_SEPERATOR_DELETE_LISTE = "<SEPERATOR_DELETE_LISTE>";
const string ListenDialog::PARSE_PHRASE_NAME = "<PHRASE_NAME>";
const string ListenDialog::PARSE_PHRASE_POSITION = "<PHRASE_POSITION>";
const string ListenDialog::PARSE_PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION = "<PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION>";
const string ListenDialog::PARSE_PHRASE_ELEMENT_DELETE_CONFIRMATION = "<PHRASE_ELEMENT_DELETE_CONFIRMATION>";
const string ListenDialog::PARSE_PHRASE_CLEAR_CONFIRMATION = "<PHRASE_CLEAR_CONFIRMATION>";
const string ListenDialog::PARSE_PHRASE_LOAD_CONFIRMATION = "<PHRASE_LOAD_CONFIRMATION>";
const string ListenDialog::PARSE_PHRASE_SAVE_CONFIRMATION = "<PHRASE_SAVE_CONFIRMATION>";
const string ListenDialog::PARSE_PHRASE_READ_STREAM = "<PHRASE_READ_STREAM>";
const string ListenDialog::CONFIRM_DELETE = "<CONFIRM_DELETE>";
// Automatic TEST
const string ListenDialog::PARSE_AUTOMATICTEST = "<SEPERATOR_AUTOMATIC_TEST_BLOCK>";

//const string ListenDialog::PARSE_ = "";
//const string ListenDialog::PARSE_ = "";
//const string ListenDialog::PARSE_ = "";

// Allgemein
const string ListenDialog::PARSE_INPUT_ERROR = "<INPUT_ERROR>";
const string ListenDialog::PARSE_STD_ERROR = "<STD_ERROR>";
const string ListenDialog::PARSE_SEPERATOR = "<SEPERATOR_STD>";


//const Int
const int ListenDialog::STD_ANSWER_VALUE = -1;
const int ListenDialog::ZERO_VALUE = 0;
const int ListenDialog::INPUT_ONE = 1;
const int ListenDialog::INPUT_VALUE = 2;
const int ListenDialog::MAX_RUNS_FILE_READ = 4;
const int ListenDialog::HIGH_VALUE = 1000;
const int ListenDialog::TEST_QUANTITY = 14;
//VON BEIDEN VERWENDET
const char* ListenDialog::COPY_RESULT = "ERSTER WERT linListe ZWEITER WERT linListeCopy";

//TODO Implement me Senpai

/**
* @brief Konstruktor
*/
ListenDialog::ListenDialog() {}

/**
* @brief Dekonstruktor
*/
ListenDialog::~ListenDialog() {}
/**
* @brief ListenDialog::mainDialog()
* @details HauptDialog Auswahl Auto Manuell Exit
*/
void ListenDialog::mainDialog(string &fileName){
	string error_input = parsePhrases(fileName, PARSE_INPUT_ERROR);
	string seperator_LinListe = parsePhrases(fileName, PARSE_SEPERATOR_LINLIST_BLOCK);
	string main_dialog = parsePhrases(fileName, PARSE_MAINDIALOG);
	int answer;
	do{
		cout << seperator_LinListe << endl << main_dialog;
		answer = readIntegerInput();
		switch (answer) {
		case EXIT:
			break;
		case AUTOMATICTEST:
			automaticTest(fileName);
			break;
		case MANUELLDIALOG:
			//manuellDialog("de_DE.lang");
			manuellDialog(fileName);
			break;
		default:
			cout << error_input << endl;
			break;
		}
	} while (answer != EXIT);
}
/**
* @brief ListenDialog::automaticTest()
* @details Automatischer Test
*/
void ListenDialog::automaticTest(string &fileName){
	istringstream is(AUTOMATIC_TEST_EINGABE_STREAM_VALUE);
	string seperator_Automatic_Test = parsePhrases(fileName, PARSE_AUTOMATICTEST);
	string error_input = parsePhrases(fileName, PARSE_INPUT_ERROR);
	string error_std = parsePhrases(fileName, PARSE_STD_ERROR);
	LinList* linListe = NULL;
	LinList* linListeCopy = NULL;
	linListe = new LinList();
	linListeCopy = new LinList();
	int runCounter = ZERO_VALUE;
	cout << seperator_Automatic_Test << endl << endl;
	do{
		try{
			cout << *linListe << endl;
			switch (runCounter) {
			case AUTO_INIT:
				cout << AUTOMATIC_TEST_INIT << AUTOMATIC_TEST_ELEMENT_INIT << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->push_back(AUTOMATIC_TEST_ELEMENT_INIT);
				break;
			case AUTO_PUSH_BACK:
				cout << AUTOMATIC_TEST_PUSH_BACK << AUTOMATIC_TEST_ELEMENT_BACK << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->push_back(AUTOMATIC_TEST_ELEMENT_BACK);
				break;
			case AUTO_PUSH_FRONT:
				cout << AUTOMATIC_TEST_PUSH_FRONT << AUTOMATIC_TEST_ELEMENT_FRONT << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->push_front(AUTOMATIC_TEST_ELEMENT_FRONT);
				break;
			case AUTO_POP_BACK:
				cout << AUTOMATIC_TEST_POP_BACK << endl;
				linListe->pop_back();
				break;
			case AUTO_POP_FRONT:
				cout << AUTOMATIC_TEST_POP_FRONT << endl;
				linListe->pop_front();
				break;
			case AUTO_INSERT:
				cout << AUTOMATIC_TEST_INSERT << INPUT_ONE << AUTOMATIC_TEST_POSITION << AUTOMATIC_TEST_ELEMENT_INSERT << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->insert(INPUT_ONE, AUTOMATIC_TEST_ELEMENT_INSERT);
				break;
			case AUTO_INSERT_HIGH_VALUE:
				cout << AUTOMATIC_TEST_INSERT << HIGH_VALUE << AUTOMATIC_TEST_POSITION << AUTOMATIC_TEST_ELEMENT_INSERT_HIGH << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->insert(HIGH_VALUE, AUTOMATIC_TEST_ELEMENT_INSERT_HIGH);
				break;
			case AUTO_INSERT_LOW_VALUE:
				cout << AUTOMATIC_TEST_INSERT << ZERO_VALUE << AUTOMATIC_TEST_POSITION << AUTOMATIC_TEST_ELEMENT_INSERT_LOW << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->insert(ZERO_VALUE, AUTOMATIC_TEST_ELEMENT_INSERT_LOW);
				break;
			case AUTO_ERASE:
				cout << AUTOMATIC_TEST_ERASE << INPUT_VALUE << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->erase(INPUT_VALUE);
				break;
			case AUTO_ERASE_ZERO:
				cout << AUTOMATIC_TEST_ERASE << ZERO_VALUE << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->erase(ZERO_VALUE);
				break;
			case AUTO_ERASE_NON_EXISTENT_ELEMENT:
				cout << AUTOMATIC_TEST_ERASE << HIGH_VALUE << AUTOMATIC_TEST_HYPHEN << endl;
				linListe->erase(HIGH_VALUE);
				break;
			case AUTO_INPUT_STREAM:
				cout << AUTOMATIC_TEST_EINGABE_STREAM << AUTOMATIC_TEST_EINGABE_STREAM_VALUE << AUTOMATIC_TEST_HYPHEN << endl;
				is >> *linListe;
				break;
			case AUTO_COPY_TEST:
				*linListeCopy = *linListe;
				cout << COPY_RESULT << endl << *linListe << SPACER << *linListe << endl
					<< *linListeCopy << SPACER << *linListeCopy << endl;
				break;
			case AUTO_CLEAR:
				cout << AUTOMATIC_TEST_CLEAR << endl;
				linListe->clear();
				break;
			case POP_EMPTY:
				cout << AUTOMATIC_TEST_POP_EMPTY_LIST << endl;
				linListe->pop_back();
				break;
			}
		}
		catch (LinListException& e) {
			cout << error_std << e.what() << endl;
		}
		catch (ElementException& e){
			cout << error_std << e.what() << endl;
		}
		runCounter++;
	} while (runCounter < TEST_QUANTITY);
}
/**
* @brief ListenDialog::manuellDialog()
* @details Manuelle Steuerung Des Programmes
*/
void ListenDialog::manuellDialog(string &fileName){
	LinList* linListe = NULL;
	LinList* linListeCopy = NULL;
	linListe = new LinList();
	linListeCopy = new LinList();
	string wirklichLoeschen;
	string name;
	string error_input = parsePhrases(fileName, PARSE_INPUT_ERROR);
	string error_std = parsePhrases(fileName, PARSE_STD_ERROR);
	string seperator = parsePhrases(fileName, PARSE_SEPERATOR);
	string manuell_dialog = parsePhrases(fileName, PARSE_MANUELLDIALOG);
	string seperator_delete_liste = parsePhrases(fileName, PARSE_SEPERATOR_DELETE_LISTE);
	string seperator_maunuell = parsePhrases(fileName, PARSE_SEPERATOR_MANUELL_BLOCK);
	string seperator_insert = parsePhrases(fileName, PARSE_SEPERATOR_INSERT);
	string seperator_erase = parsePhrases(fileName, PARSE_SEPERATOR_ERASE);
	string seperator_clear = parsePhrases(fileName, PARSE_SEPERATOR_CLEAR);
	string seperator_push = parsePhrases(fileName, PARSE_SEPERATOR_PUSH);
	string seperator_pop = parsePhrases(fileName, PARSE_SEPERATOR_POP);
	string seperator_backup = parsePhrases(fileName, PARSE_SEPERATOR_BACKUP);
	string seperator_delete = parsePhrases(fileName, PARSE_SEPERATOR_DELETE_LISTE);
	string phrase_name = parsePhrases(fileName, PARSE_PHRASE_NAME);
	string phrase_position = parsePhrases(fileName, PARSE_PHRASE_POSITION);
	string phrase_element_delete_back_confirmation = parsePhrases(fileName, PARSE_PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION);
	string phrase_element_delete_confirmation = parsePhrases(fileName, PARSE_PHRASE_ELEMENT_DELETE_CONFIRMATION);
	string phrase_clear_confirmation = parsePhrases(fileName, PARSE_PHRASE_CLEAR_CONFIRMATION);
	string phrase_load_confirmation = parsePhrases(fileName, PARSE_PHRASE_LOAD_CONFIRMATION);
	string phrase_save_confirmation = parsePhrases(fileName, PARSE_PHRASE_SAVE_CONFIRMATION);
	string phrase_read_stream = parsePhrases(fileName, PARSE_PHRASE_READ_STREAM);
	string confirm_Delete = parsePhrases(fileName, CONFIRM_DELETE);

	int position;
	int answer;
	do{
		try{
			cout << seperator_maunuell << endl << *linListe << endl << manuell_dialog;
			cout.clear();
			answer = readIntegerInput();
			switch (answer) {
			case BACK:
				cout << seperator_push << endl << phrase_element_delete_back_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete){
					answer = ABORT;
				}
				cout << endl;
				break;
			case PUSH_BACK:
				cout << seperator_push << endl;
				cout << phrase_name;
				name = readStringInput();;
				linListe->push_back(name);
				break;
			case PUSH_FRONT:
				cout << seperator_push << endl;
				cout << phrase_name;
				name = readStringInput();;
				linListe->push_front(name);
				break;
			case POP_BACK:
				cout << seperator_pop << endl << phrase_element_delete_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete){
					answer = ABORT;
				}
				else {
					linListe->pop_back();
				}
				break;
			case POP_FRONT:
				cout << seperator_pop << endl << phrase_element_delete_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete){
					answer = ABORT;
				}
				else {
					linListe->pop_front();
				}
				break;
			case INSERT_ELEMENT:
				cout << seperator_insert << endl;
				cout << phrase_name;
				name = readStringInput();
				cout << phrase_position;
				position = readIntegerInput();
				linListe->insert(position, name);
				break;
			case ERASE_ELEMENT:
				cout << phrase_position;
				position = readIntegerInput();
				cout << seperator_erase << endl << phrase_element_delete_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete){
					answer = ABORT;
				}
				else {
					linListe->erase(position);
				}
				cout << endl;
				break;
			case CLEAR:
				cout << seperator_delete << endl << phrase_clear_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete){
					answer = ABORT;
				}
				else {
					linListe->clear();
				}
				cout << endl;
				break;
			case STREAM:
				cout << seperator_delete << endl << phrase_load_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete){
					answer = ABORT;
				}
				else {
					cout << phrase_read_stream;
					cin >> *linListe;
				}
				break;
			case SAVE_BACKUP:
				cout << seperator_backup << endl;
				cout << *linListeCopy << endl;
				cout << seperator_delete_liste << endl << phrase_save_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete){
					answer = ABORT;
				}
				else {
					*linListeCopy = *linListe;
					cout << COPY_RESULT << endl << linListe << SPACER << *linListe << endl
						<< linListeCopy << SPACER << *linListeCopy << endl;
				}

				break;
			case LOAD_BACKUP:
				cout << seperator_backup << endl;
				cout << *linListeCopy << endl;
				cout << seperator_delete_liste << endl << phrase_load_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete){
					answer = ABORT;
				}
				else {
					*linListe = *linListeCopy;
					cout << COPY_RESULT << endl << linListeCopy << SPACER << *linListeCopy << endl
						<< linListe << SPACER << *linListe << endl;
				}
				break;
			case ABORT:
				break;
			default:
				cout << error_input << endl;
				cout.clear();
				break;
			}
			if (answer != 0){
				answer = STD_ANSWER_VALUE;
			}
		}
		catch (LinListException& e) {
			cout << error_std << e.what() << endl;
		}
		catch (ElementException& e){
			cout << error_std << e.what() << endl;
		}
	} while (answer != BACK);
	delete linListe;
}

/**
* @brief ListenDialog::clearInput()
* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
*/
void ListenDialog::initLanguage(){
	string error_input = parsePhrases(LANGUAGE_STD, PARSE_INPUT_ERROR);
	string error_de_DE_Not_Found = parsePhrases(LANGUAGE_STD, DE_DE_LANG_NOT_FOUND);
	string error_en_US_Not_Found = parsePhrases(LANGUAGE_STD, PARSE_INPUT_ERROR);
	string error_hodor_WESTEROS_Not_Found = parsePhrases(LANGUAGE_STD, PARSE_INPUT_ERROR);
	string language_dialog = parsePhrases(LANGUAGE_STD, PARSE_LANGUAGEDIALOG);
	string chosenLanguage = LANGUAGE_GERMAN;
	if (fileExists(LANGUAGE_STD)){
		int answer = STD_ANSWER_VALUE;
		do{

			if (answer != START_MAINDIALOG){
				cout << language_dialog;
				answer = readIntegerInput();
				if (answer == START_MAINDIALOG || answer == runAgain){
					answer = STD_ANSWER_VALUE;
				}
			}
			switch (answer) {
			case CLOSEPROGRAM:
				break;
			case GERMAN:
				if (fileExists(LANGUAGE_GERMAN)){
					chosenLanguage = LANGUAGE_GERMAN;
					answer = START_MAINDIALOG;

				}
				else{
					cout << error_de_DE_Not_Found << endl;
					clearInput();
				}
				break;
			case ENGLISH:
				if (fileExists(LANGUAGE_ENGLISH)){
					chosenLanguage = LANGUAGE_ENGLISH;
					answer = START_MAINDIALOG;
				}
				else{
					cout << error_en_US_Not_Found << endl;
					clearInput();
				}
				break;
			case HODOR:
				if (fileExists(LANGUAGE_HODOR)){
					chosenLanguage = LANGUAGE_HODOR;
					answer = START_MAINDIALOG;
				}
				else{
					cout << error_hodor_WESTEROS_Not_Found << endl;
					clearInput();
				}
				break;
			case START_MAINDIALOG:
				mainDialog(chosenLanguage);
				answer = runAgain;
				break;
			case runAgain:
				break;
			default:
				cout << error_input << endl;
				break;
			}
		} while (answer != EXIT);
	}
	else{
		cout << STD_LANG_NOT_FOUND << endl;
		clearInput();
	}
}

string ListenDialog::parsePhrases(string fileName, string begin){
	fstream file;
	stringstream is;
	string cache;
	string line;
	string ausgabe;
	bool found = false;
	bool firstRun = true;
	bool stop = false;
	bool streamWritten = false;
	const char* constName = fileName.c_str();
	file.open(constName);
	while (getline(file, line)){

		if (!stop && found){
			if (!firstRun){
				is << cache;
				streamWritten = true;
			}
			if (firstRun){
				firstRun = false;
			}
		}
		if (found && !stop){
			if (strcmp(PARSER_READ_END.c_str(), line.c_str()) == 0){
				stop = true;
			}
			else{
				cache = line;
				if (streamWritten){
					is << endl;
				}
			}
		}
		if (strcmp(begin.c_str(), line.c_str()) == 0 && !found){
			found = true;
		}
	}
	file.close();
	ausgabe = is.str();
	return is.str();
}
void ListenDialog::clearInput(){
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}

int ListenDialog::readIntegerInput(){
	double number = readDoubleInput();
	if (!(fmod(number, INPUT_ONE) == ZERO_VALUE)){
		number = STD_ANSWER_VALUE;
	}
	return (int)number;
}
double ListenDialog::readDoubleInput(){
	double number;
	if (cin >> number){
	}
	else {
		number = STD_ANSWER_VALUE;
	}
	clearInput();
	return number;
}
string ListenDialog::readStringInput(){
	string input;
	cin >> input;
	clearInput();
	return input;
}

bool ListenDialog::fileExists(string fileName) {
	const char* constName = fileName.c_str();
	ifstream infile(constName);
	return infile.good();
}
