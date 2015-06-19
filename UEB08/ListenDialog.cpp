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

#include <fstream>

//Konstanten 
//Seperators
const char* ListenDialog::SEPERATOR = "-------------------------------";
const char* ListenDialog::SEPERATOR_LISTE = "------------linListe-----------";
const char* ListenDialog::SEPERATOR_DELETE_LISTE = "-L-------DELETE-LISTE----------";
const char* ListenDialog::SEPERATOR_AUTOMATIC_TEST = "---------AUTOMATIC-TEST--------";
const char* ListenDialog::SEPERATOR_MANUELL = "------------MANUELL------------";
const char* ListenDialog::SEPERATOR_INSERT = "------------INSERT-------------";
const char* ListenDialog::SEPERATOR_ERASE = "------------ERASE--------------";
const char* ListenDialog::SEPERATOR_CLEAR = "------------CLEAR--------------";
const char* ListenDialog::SEPERATOR_PUSH = "-------------PUSH--------------";
const char* ListenDialog::SEPERATOR_POP = "-------------POP---------------";
const char* ListenDialog::SEPERATOR_BACKUP = "-------------BACKUP------------";
const char* ListenDialog::SPACER = " ";
//ErrorphrassesMANUELLDIALOG_OPTION_ERASE
const char* ListenDialog::INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
const char* ListenDialog::ERRORPHRASE = "Fehler: ";
//STD Phrases
const char* ListenDialog::STANDARDCHOICEPHRASE = "-> ";
const char* ListenDialog::MANUELLDIALOG_ELEMENT_NEU_NAME = "NAME: ";
const char* ListenDialog::MANUELLDIALOG_ELEMENT_NEU_POSITION = "Position: ";
const char* ListenDialog::MANUELLDIALOG_STREAM_EINGABE = "Mehrere eingaben bis NIL getrennt mit Leerzeichen!!";
const char* ListenDialog::MANUELLDIALOG_EINGABESYMBOL = "->> ";
const char* ListenDialog::BACK_CONFIRMATION = "Daten gehen verloren! Weiter? (j)=Ja: ";
const char* ListenDialog::ELEMENT_DELETE_CONFIRMATION = "ELEMENT wirklich loeschen? (j)=Ja: ";
const char* ListenDialog::CLEAR_CONFIRMATION = "linListe wirklich leeren? (j)=Ja: ";
const char* ListenDialog::LOAD_CONFIRMATION = "aktuelle Liste verwerfen? (j)=Ja: ";
const char* ListenDialog::SAVE_CONFIRMATION = "Backup ueberschreiben? (j)=Ja: ";
const char* ListenDialog::STD_VALUE_WIRKLICH_LOESCHEN = "n";
const char* ListenDialog::STD_VALUE_WIRKLICH_LOESCHEN_YES = "j";
const char* ListenDialog::STD_VALUE_WIRKLICH_LOESCHEN_YES_EN = "y";
const char* ListenDialog::STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR = "HODOR";

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



const char* ListenDialog::LANGUAGE_OPTION_OVERVIEW = "Please chose Language";
const char* ListenDialog::LANGUAGE_OPTION_GERMAN = "(1) GERMAN";
const char* ListenDialog::LANGUAGE_OPTION_ENGLISH = "(2) ENGLISH";
const char* ListenDialog::LANGUAGE_OPTION_HODOR = "(3) HODOR";


const string ListenDialog::READ_END = "##END"; 
const string ListenDialog::PARSER_READ_END = "<END>";
// const strings
// Maindialog
const string ListenDialog::PARSE_SEPERATOR_LINLIST_BLOCK = "<SEPERATOR_LINLIST_BLOCK>";
const string ListenDialog::PARSE_MAINDIALOG = "<MAINDIALOG>";
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
const int ListenDialog::SEPERATOR_POSITION = 2;
const int ListenDialog::SEPERATOR_LINLISTE_POSITION = 5;
const int ListenDialog::SEPERATOR_MANUELL_POSITION = 15;
const int ListenDialog::SEPERATOR_PUSH_POSITION = 32;
const int ListenDialog::SEPERATOR_POP_POSITION = 35;
const int ListenDialog::SEPERATOR_CLEAR_POSITION = 29;
const int ListenDialog::MAINDIALOG_POSITION = 51;
const int ListenDialog::MANUELLDIALOG_POSITION = 59;
const int ListenDialog::SEPERATOR_DELETE_LISTE_POSITION = 20;
const int ListenDialog::ERROR_INVAILD_INPUT_POSITION = 43;
const int ListenDialog::ERROR_STD_POSITION = 45;
const int ListenDialog::SEPERATOR_BACKUP_POSITION = 38;
const int ListenDialog::SEPERATOR_INSERT_POSITION = 24;
const int ListenDialog::SEPERATOR_ERASE_POSITION = 26;
const int ListenDialog::HIGH_VALUE = 1000;
const int ListenDialog::TEST_QUANTITY = 14;
const int ListenDialog::PHRASE_NAME_POSITION = 76;
const int ListenDialog::PHRASE_POSITION_POSITION = 79;
const int ListenDialog::PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION_POITION = 86;
const int ListenDialog::PHRASE_ELEMENT_DELETE_CONFIRMATION_POSITION = 89;
const int ListenDialog::PHRASE_CLEAR_CONFIRMATION_POSITION = 92;
const int ListenDialog::PHRASE_LOAD_CONFIRMATION_POITION = 95;
const int ListenDialog::PHRASE_SAVE_CONFIRMATION_POITION = 98;
const int ListenDialog::PHRASE_READ_STREAM = 82;


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
	string testFile = "de_DE.lang_newSyntax" ;
	string testMe;
	string error_input = parsePhrases(testFile, PARSE_INPUT_ERROR);
	string seperator_LinListe = parsePhrases(testFile, PARSE_SEPERATOR_LINLIST_BLOCK);
	string main_dialog = parsePhrases(testFile, PARSE_MAINDIALOG);
	int answer = STD_ANSWER_VALUE;
	do{
		cout << seperator_LinListe << endl << main_dialog;
		cin >> answer;
		clearInput();
		switch (answer) {
		case EXIT:
			break;
		case AUTOMATICTEST:
			automaticTest();
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
void ListenDialog::automaticTest(){
	istringstream is(AUTOMATIC_TEST_EINGABE_STREAM_VALUE);
	LinList* linListe = NULL;
	LinList* linListeCopy = NULL;
	linListe = new LinList();
	linListeCopy = new LinList();
	int runCounter = ZERO_VALUE;
	cout << SEPERATOR << endl << SEPERATOR_AUTOMATIC_TEST << endl << SEPERATOR << endl << endl;
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
			cout << ERRORPHRASE << e.what() << endl;
		}
		catch (ElementException& e){
			cout << ERRORPHRASE << e.what() << endl;
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
	string wirklichLoeschen = STD_VALUE_WIRKLICH_LOESCHEN;
	string name;
	string seperator = readVariables(fileName, SEPERATOR_POSITION);
	string seperator_delete_liste = readVariables(fileName, SEPERATOR_DELETE_LISTE_POSITION);
	string seperator_maunuell = readVariables(fileName, SEPERATOR_MANUELL_POSITION);
	string seperator_insert = readVariables(fileName, SEPERATOR_INSERT_POSITION);
	string seperator_erase = readVariables(fileName, SEPERATOR_ERASE_POSITION);
	string seperator_clear = readVariables(fileName, SEPERATOR_CLEAR_POSITION);
	string seperator_push = readVariables(fileName, SEPERATOR_PUSH_POSITION);
	string seperator_pop = readVariables(fileName, SEPERATOR_PUSH_POSITION);
	string seperator_backup = readVariables(fileName, SEPERATOR_BACKUP_POSITION);
	string error_input = readVariables(fileName, ERROR_INVAILD_INPUT_POSITION);
	string error_std = readVariables(fileName, ERROR_STD_POSITION);
	string manuell_dialog = readVariables(fileName, MANUELLDIALOG_POSITION);
	string seperator_delete = readVariables(fileName, SEPERATOR_DELETE_LISTE_POSITION);
	string phrase_name = readVariables(fileName, PHRASE_NAME_POSITION);
	string phrase_position = readVariables(fileName, PHRASE_POSITION_POSITION);
	string phrase_element_delete_back_confirmation = readVariables(fileName, PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION_POITION);
	string phrase_element_delete_confirmation = readVariables(fileName, PHRASE_ELEMENT_DELETE_CONFIRMATION_POSITION);
	string phrase_clear_confirmation = readVariables(fileName, PHRASE_CLEAR_CONFIRMATION_POSITION);
	string phrase_load_confirmation = readVariables(fileName, PHRASE_LOAD_CONFIRMATION_POITION);
	string phrase_save_confirmation = readVariables(fileName, PHRASE_SAVE_CONFIRMATION_POITION);
	string phrase_read_stream = readVariables(fileName, PHRASE_READ_STREAM);

	
	int position = STD_ANSWER_VALUE;
	int answer = STD_ANSWER_VALUE;
	do{
		try{
			cout << seperator_maunuell << endl << *linListe << endl << manuell_dialog;
			cout.clear();
			cin >> answer;
			clearInput();
			switch (answer) {
			case BACK:
				cout << seperator_push << endl << phrase_element_delete_back_confirmation;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_EN && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR){
					answer = ABORT;
				}
				cout << endl;
				break;
			case PUSH_BACK:
				cout << seperator_push << endl;
				cout << phrase_name;
				cin >> name;
				clearInput();
				linListe->push_back(name);
				break;
			case PUSH_FRONT:
				cout << seperator_push << endl;
				cout << phrase_name;
				cin >> name;
				clearInput();
				linListe->push_front(name);
				break;
			case POP_BACK:
				cout << seperator_pop << endl << phrase_element_delete_confirmation;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_EN && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR){
					answer = ABORT;
				}
				else {
					linListe->pop_back();
				}
				break;
			case POP_FRONT:
				cout << seperator_pop << endl << phrase_element_delete_confirmation;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_EN && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR){
					answer = ABORT;
				}
				else {
					linListe->pop_front();
				}
				break;
			case INSERT_ELEMENT:
				cout << seperator_insert << endl;
				cout << phrase_name;
				cin >> name;
				clearInput();
				cout << phrase_position;
				cin >> position;
				clearInput();
				linListe->insert(position, name);
				break;
			case ERASE_ELEMENT:
				cout << phrase_position;
				cin >> position;
				clearInput();
				cout << seperator_erase << endl << phrase_element_delete_confirmation;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_EN && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR){
					answer = ABORT;
				}
				else {
					linListe->erase(position);
				}
				cout << endl;
				break;
			case CLEAR:
				cout << seperator_delete << endl << phrase_clear_confirmation;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_EN && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR){
					answer = ABORT;
				}
				else {
					linListe->clear();
				}
				cout << endl;
				break;
			case STREAM:
				cout << seperator_delete << endl << phrase_load_confirmation;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_EN && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR){
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
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_EN && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR){
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
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_EN && wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES_HODOR){
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
	string LANGUAGE_GERMAN = "de_DE.lang";
	string LANGUAGE_ENGLISH = "en_US.lang";
	string LANGUAGE_HODOR = "hodor_WESTEROS.lang";
	if (fileExists(LANGUAGE_GERMAN) && fileExists(LANGUAGE_ENGLISH) && fileExists(LANGUAGE_HODOR)){
		int answer = STD_ANSWER_VALUE;
		do{
			cout << LANGUAGE_OPTION_OVERVIEW << endl << LANGUAGE_OPTION_GERMAN << endl << LANGUAGE_OPTION_ENGLISH << endl << LANGUAGE_OPTION_HODOR << endl << STANDARDCHOICEPHRASE;
			cin >> answer;
			clearInput();
			switch (answer) {
			case CLOSEPROGRAM:
				break;
			case GERMAN:
				mainDialog(LANGUAGE_GERMAN);
				break;
			case ENGLISH:
				mainDialog(LANGUAGE_ENGLISH);
				break;
			case HODOR:
				mainDialog(LANGUAGE_HODOR);
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
				break;
			}
		} while (answer != EXIT);
	}
	else{
		cout << "NO LANGUAGE FILES DETECTED" << endl << "Press Enter to Exit";
		clearInput();
	}
}

string ListenDialog::readVariables(string fileName, int lowerBorder){
	fstream file;
	stringstream is;
	string cache;
	string line;
	const char* constName = fileName.c_str();
	file.open(constName);
	int lines = ZERO_VALUE;
	int stop = ZERO_VALUE;
	while (getline(file, line)){
		if (stop != INPUT_ONE && lowerBorder<lines){
			if (lowerBorder + 1 < lines){
				is << endl;
			}
			is << cache;
		}
		if (lines >= lowerBorder && stop != INPUT_ONE){
			if (line == READ_END){
				stop = INPUT_ONE;
			}
			else{
				cache = line;
			}
		}
		lines++;
	}
	file.close();
	return is.str();
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
			if (line == PARSER_READ_END){
				stop = true;
			}
			else{
				cache = line;
				if (streamWritten){
					is << endl;
				}
			}
		}
		if (begin == line){
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

bool ListenDialog::fileExists(string fileName) {
	const char* constName = fileName.c_str();
	ifstream infile(constName);
	return infile.good();
}
