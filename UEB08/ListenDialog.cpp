/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file  ListenDialog.cpp
* @author Andreas Schreiner & Simon Bastian
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

//const char* ListenDialog::SEPERATOR_LOAD = "-------------LOAD--------------";
//const char* ListenDialog::SEPERATOR_SAVE = "-------------SAVE--------------";
//const char* ListenDialog::SEPERATOR_FILE_EDIT = "-----------FILE_EDIT-----------";

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
const char* ListenDialog::OVERRRIDE_CONFIRMATION = "Werte ueberschreiben? (j)=Ja: ";

const char* ListenDialog::STD_VALUE_WIRKLICH_LOESCHEN = "n";
const char* ListenDialog::STD_VALUE_WIRKLICH_LOESCHEN_YES = "j";
const char* ListenDialog::MANUELLDIALOF_FILE_NAME = "Dateinamen bitte eingeben: ";

//FILE_DIALOG
//const char* ListenDialog::FILEDIALOG_OPTION_SAVE = "(1) Save";
//const char* ListenDialog::FILEDIALOG_OPTION_LOAD = "(2) Load";
//const char* ListenDialog::FILEDIALOG_OPTION_BACK = "(0) Back ";


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
const int ListenDialog::MAINDIALOG_POSITION = 51;
const int ListenDialog::MANUELLDIALOG_POSITION = 59;
const int ListenDialog::ERROR_INVAILD_INPUT_POSITION = 43;

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
	stringstream error_input = readVariables(fileName, ERROR_INVAILD_INPUT_POSITION);
	stringstream seperator_LinListe = readVariables(fileName, SEPERATOR_LINLISTE_POSITION);
	stringstream main_dialog = readVariables(fileName, MAINDIALOG_POSITION);
	int answer = STD_ANSWER_VALUE;
	do{
		cout << seperator_LinListe.str() << endl << main_dialog.str();
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
			cout << error_input.str() << endl;
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
	stringstream is;
	//	is = readVariables("de_DE.lang", 1, 2);
	stringstream is2;
	is2 = readVariables(fileName, 33);
	stringstream seperator = readVariables(fileName, SEPERATOR_POSITION);
	stringstream seperator_delete_liste = readVariables(fileName, 3);
	stringstream seperator_maunuell = readVariables(fileName, SEPERATOR_MANUELL_POSITION);
	stringstream seperator_insert = readVariables(fileName, 7);
	stringstream seperator_erase = readVariables(fileName, 7);
	stringstream seperator_clear = readVariables(fileName, 7);
	stringstream seperator_push = readVariables(fileName, SEPERATOR_PUSH_POSITION);
	stringstream seperator_pop = readVariables(fileName, SEPERATOR_PUSH_POSITION);
	stringstream seperator_backup = readVariables(fileName, 7);
	stringstream error_input = readVariables(fileName, ERROR_INVAILD_INPUT_POSITION);
	stringstream error_std = readVariables(fileName, 7);
	stringstream manuell_dialog = readVariables(fileName, MANUELLDIALOG_POSITION);
	int position = STD_ANSWER_VALUE;
	int answer = STD_ANSWER_VALUE;
	do{
		try{
			cout << seperator_maunuell.str() << endl << *linListe << endl << manuell_dialog.str();
			cout.clear();
			cin >> answer;
			clearInput();
			switch (answer) {
			case BACK:
				cout << seperator_push.str() << endl << BACK_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				}
				cout << endl;
				break;
			case PUSH_BACK:
				cout << SEPERATOR_PUSH << endl;
				cout << MANUELLDIALOG_ELEMENT_NEU_NAME;
				cin >> name;
				clearInput();
				linListe->push_back(name);
				break;
			case PUSH_FRONT:
				cout << SEPERATOR_PUSH << endl;
				cout << MANUELLDIALOG_ELEMENT_NEU_NAME;
				cin >> name;
				clearInput();
				linListe->push_front(name);
				break;
			case POP_BACK:
				cout << SEPERATOR_POP << endl << ELEMENT_DELETE_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				}
				else {
					linListe->pop_back();
				}
				break;
			case POP_FRONT:
				cout << SEPERATOR_POP << endl << ELEMENT_DELETE_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				}
				else {
					linListe->pop_front();
				}
				break;
			case INSERT_ELEMENT:
				cout << SEPERATOR_INSERT << endl;
				cout << MANUELLDIALOG_ELEMENT_NEU_NAME;
				cin >> name;
				clearInput();
				cout << MANUELLDIALOG_ELEMENT_NEU_POSITION;
				cin >> position;
				clearInput();
				linListe->insert(position, name);
				break;
			case ERASE_ELEMENT:
				cout << MANUELLDIALOG_ELEMENT_NEU_POSITION;
				cin >> position;
				clearInput();
				cout << SEPERATOR_ERASE << endl << ELEMENT_DELETE_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				}
				else {
					linListe->erase(position);
				}
				cout << endl;
				break;
			case CLEAR:
				cout << SEPERATOR_DELETE_LISTE << endl << CLEAR_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				}
				else {
					linListe->clear();
				}
				cout << endl;
				break;
			case STREAM:
				cout << SEPERATOR_DELETE_LISTE << endl << LOAD_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				}
				else {
					cout << MANUELLDIALOG_STREAM_EINGABE << endl << MANUELLDIALOG_EINGABESYMBOL;
					cin >> *linListe;
				}
				break;
			case SAVE_BACKUP:
				cout << SEPERATOR_BACKUP << endl;
				cout << *linListeCopy << endl;
				cout << SEPERATOR_DELETE_LISTE << endl << SAVE_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				}
				else {
					*linListeCopy = *linListe;
					cout << COPY_RESULT << endl << linListe << SPACER << *linListe << endl
						<< linListeCopy << SPACER << *linListeCopy << endl;
				}

				break;
			case LOAD_BACKUP:
				cout << SEPERATOR_BACKUP << endl;
				cout << *linListeCopy << endl;
				cout << SEPERATOR_DELETE_LISTE << endl << LOAD_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
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
				cout << error_input.str() << endl;
				cout.clear();
				break;
			}
			if (answer != 0){
				answer = STD_ANSWER_VALUE;
			}
		}
		catch (LinListException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}
		catch (ElementException& e){
			cout << ERRORPHRASE << e.what() << endl;
		}
	} while (answer != BACK);
	delete linListe;
}
/*
* @brief fileDialog(LinList* linListe, string fileName)
* @details SAVE AND LOAD
* @param *linListe Listenreferenz
* @param fileName Dateiname
*/
//void ListenDialog::fileDialog(LinList* liste, string fileName) {
//	fstream file;
//	istringstream is;
//	const char* constName = fileName.c_str();
//	int run = INPUT_ONE;
//	string line;
//	int answer = STD_ANSWER_VALUE;
//	do {
//		cout << SEPERATOR << endl << SEPERATOR_FILE_EDIT << endl << SEPERATOR << endl
//			<< FILEDIALOG_OPTION_SAVE << endl << FILEDIALOG_OPTION_LOAD << endl
//			<< FILEDIALOG_OPTION_BACK << endl << STANDARDCHOICEPHRASE;
//		cin >> answer;
//		switch (answer)	{
//		case SAVE:
//			file.open(constName);
//			file << *liste;
//			file.close();
//			break;
//		case LOAD:
//			run = INPUT_ONE;
//			file.open(constName);
//			while (run < MAX_RUNS_FILE_READ){
//				getline(file, line);
//				if (run == INPUT_ONE){
//					getline(file, line);
//					is.str(line);
//					is >> *liste;
//				}
//				run++;
//			}
//			file.close();
//			break;
//		case CLOSE_FILE_DIALOG:
//			break;
//		default:
//			break;
//		}
//	} while (answer != CLOSE_FILE_DIALOG);
//}
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

stringstream ListenDialog::readVariables(string fileName, int lowerBorder){
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
			if (line == "##END"){
				stop = INPUT_ONE;
			}
			else{
				cache = line;
			}
		}
		lines++;
	}
	file.close();
	return is;
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