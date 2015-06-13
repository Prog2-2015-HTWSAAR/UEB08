/*
 * ListenDialog.cpp
 *
 *  Created on: 11.06.2015
 *      Author: sbastian
 */
#include "ListenDialog.h"
//Konstanten 
//Seperators
const char* ListenDialog::SEPERATOR = "-------------------------------";
const char* ListenDialog::SEPERATOR_LISTE = "-------------LISTE-------------";
const char* ListenDialog::SEPERATOR_DELETE_LISTE = "-L-------DELETE-LAGER----------";
const char* ListenDialog::SEPERATOR_AUTOMATIC_TEST = "---------AUTOMATIC-TEST--------";
const char* ListenDialog::SEPERATOR_MANUELL = "-----------MAUNUELL------------";
const char* ListenDialog::SEPERATOR_INSERT = "------------INSERT-------------";
const char* ListenDialog::SEPERATOR_ERASE = "------------ERASE--------------";
const char* ListenDialog::SEPERATOR_CLEAR = "------------CLEAR--------------";
const char* ListenDialog::SEPERATOR_PUSH = "-------------PUSH--------------";
const char* ListenDialog::SEPERATOR_POP = "-------------POP---------------";
//Errorphrasses
const char* ListenDialog::INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
const char* ListenDialog::ERRORPHRASE = "Fehler: ";
//STD Phrases
const char* ListenDialog::STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
//Main Dialog
const char* ListenDialog::MAINDIALOG_OPTION_ZERO = "(0) EXIT";
const char* ListenDialog::MAINDIALOG_OPTION_ONE = "(1) Automatischer Test";
const char* ListenDialog::MAINDIALOG_OPTION_TWO = "(2) Manueller Test";
//Manuell Dialog
const char* ListenDialog::MANUELLDIALOG_ELEMENT_NEU_NAME = "NAME: ";
const char* ListenDialog::MANUELLDIALOG_ELEMENT_NEU_POSITION = "Position";
const char* ListenDialog::MANUELLDIALOG_OPTION_ZERO = "(0) BACK";
const char* ListenDialog::MANUELLDIALOG_OPTION_ONE = "(1) Push back";
const char* ListenDialog::MANUELLDIALOG_OPTION_TWO = "(2) Push front";
const char* ListenDialog::MANUELLDIALOG_OPTION_THREE = "(3) Pop back";
const char* ListenDialog::MANUELLDIALOG_OPTION_FOUR = "(4) Pop front";
const char* ListenDialog::MANUELLDIALOG_OPTION_FIVE = "(5) Insert before position";
const char* ListenDialog::MANUELLDIALOG_OPTION_SIX = "(6) Erase position";
const char* ListenDialog::MANUELLDIALOG_OPTION_SEVEN = "(7) CLEAR";
const char* ListenDialog::ELEMENT_DELETE_CONFIRMATION = "ELEMENT wirklich Loeschen (j)=Ja: ";
const char* ListenDialog::CLEAR_CONFIRMATION = "LISTE wirklich Leeren (j)=Ja: ";
const char* ListenDialog::STD_VALUE_WIRKLICH_LOESCHEN = "n";
const char* ListenDialog::STD_VALUE_WIRKLICH_LOESCHEN_YES = "j";
//AUTO_TEST
const char* ListenDialog::AUTOMATIC_TEST_INIT = "-PUSH BACK(INIT)-";
const char* ListenDialog::AUTOMATIC_TEST_PUSH_BACK = "-PUSH BACK-";
const char* ListenDialog::AUTOMATIC_TEST_PUSH_FRONT = "-PUSH FRONT-";
const char* ListenDialog::AUTOMATIC_TEST_POP_BACK = "-POP BACK-";
const char* ListenDialog::AUTOMATIC_TEST_POP_FRONT = "-POP FRONT-";
const char* ListenDialog::AUTOMATIC_TEST_INSERT = "-INSERT-";
const char* ListenDialog::AUTOMATIC_TEST_INSERT_HIGH = "-INSERT HIGH-";
const char* ListenDialog::AUTOMATIC_TEST_INSERT_ZERO = "-INSERT ZERO-";
const char* ListenDialog::AUTOMATIC_TEST_ERASE = "-ERASE-";
const char* ListenDialog::AUTOMATIC_TEST_ERASE_ZERO = "-ERASE ZERO-";
const char* ListenDialog::AUTOMATIC_TEST_INPUT_STREAM = "-READ INPUT STREAM-";
const char* ListenDialog::AUTOMATIC_TEST_ERASE_NON_EXISTENCE = "-ERASE NON EXISTENT ELEMENT-";
const char* ListenDialog::AUTOMATIC_TEST_CLEAR = "-CLEAR-";
const char* ListenDialog::AUTOMATIC_TEST_POP_EMPTY_LIST= "-POP EMPTY LIST-";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INIT = "INIT";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_BACK = "BACK";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_FRONT = "FRONT";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INSERT = "IMHERE";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INSERT_HIGH = "HIGH";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INSERT_LOW = "LOW";
const char* ListenDialog::AUTOMATIC_TEST_EINGABE_STREAM = "A B C D NIL";
//const Int
const int ListenDialog::STD_ANSWER_VALUE = -1;
const int ListenDialog::ZERO_VALUE = 0;
const int ListenDialog::INPUT_VALUE = 2;
const int ListenDialog::HIGH_VALUE = 1000;
const int ListenDialog::TEST_QUANTITY = 14;

//TODO Implement me Senpai
ListenDialog::ListenDialog() {
	// TODO Auto-generated constructor stub

}

ListenDialog::~ListenDialog() {
	// TODO Auto-generated destructor stub
}

void ListenDialog::mainDialog(){
	int answer = STD_ANSWER_VALUE;
	do{
		cout << SEPERATOR << endl << SEPERATOR_LISTE << endl << SEPERATOR << endl << endl; 
		cout << MAINDIALOG_OPTION_ONE << endl << MAINDIALOG_OPTION_TWO << endl << MAINDIALOG_OPTION_ZERO << endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		clearInput();
		switch (answer) {
		case EXIT:
			break;
		case AUTOMATICTEST:
			automaticTest();
			break;
		case MANUELLDIALOG:
			manuellDialog();
			break;
		default:
			cout << INPUTERRORPHRASE << endl;
			break;
		}
	} while (answer != EXIT);
}

void ListenDialog::automaticTest(){
	LinList* liste = NULL;
	liste = new LinList();
	int runCounter = ZERO_VALUE;
	cout << SEPERATOR << endl << SEPERATOR_AUTOMATIC_TEST << endl << SEPERATOR << endl << endl;
	do{
		try{
			cout << *liste << endl;
			switch (runCounter) {
			case AUTO_INIT:
				cout << AUTOMATIC_TEST_INIT << endl;
				liste->push_back(AUTOMATIC_TEST_ELEMENT_INIT);
				break;
			case AUTO_PUSH_BACK:
				cout << AUTOMATIC_TEST_PUSH_BACK << endl;
				liste->push_back(AUTOMATIC_TEST_ELEMENT_BACK);
				break;
			case AUTO_PUSH_FRONT:
				cout << AUTOMATIC_TEST_PUSH_FRONT << endl;
				liste->push_front(AUTOMATIC_TEST_ELEMENT_FRONT);
				break;
			case AUTO_POP_BACK:
				cout << AUTOMATIC_TEST_POP_BACK << endl;
				liste->pop_back();
				break;
			case AUTO_POP_FRONT:
				cout << AUTOMATIC_TEST_POP_FRONT << endl;
				liste->pop_front();
				break;
			case AUTO_INSERT:
				cout << AUTOMATIC_TEST_INSERT << endl;
				liste->insert(INPUT_VALUE, AUTOMATIC_TEST_ELEMENT_INSERT);
				break;
			case AUTO_INSERT_HIGH_VALUE:
				cout << AUTOMATIC_TEST_INSERT_HIGH << endl;
				liste->insert(HIGH_VALUE, AUTOMATIC_TEST_ELEMENT_INSERT_HIGH);
				break;
			case AUTO_INSERT_LOW_VALUE:
				cout << AUTOMATIC_TEST_INSERT_ZERO << endl;
				liste->insert(ZERO_VALUE, AUTOMATIC_TEST_ELEMENT_INSERT_LOW);
				break;
			case AUTO_ERASE:
				cout << AUTOMATIC_TEST_ERASE << endl;
				liste->erase(INPUT_VALUE);
				break;
			case AUTO_ERASE_ZERO:
				cout << AUTOMATIC_TEST_ERASE_ZERO << endl;
				liste->erase(ZERO_VALUE);
				break;
			case AUTO_ERASE_NON_EXISTENT_ELEMENT:
				cout << AUTOMATIC_TEST_ERASE_NON_EXISTENCE << endl;
				liste->erase(HIGH_VALUE);
				break;
			case AUTO_INPUT_STREAM:
				cout << AUTOMATIC_TEST_EINGABE_STREAM << endl;
			//	AUTOMATIC_TEST_EINGABE_STREAM >> liste;
				break;
			case AUTO_CLEAR:
				cout << AUTOMATIC_TEST_CLEAR << endl;
				liste->clear();
				break;
			case POP_EMPTY:
				cout << AUTOMATIC_TEST_POP_EMPTY_LIST << endl;
				liste->pop_back();
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

void ListenDialog::manuellDialog(){
	LinList* liste = NULL;
	liste = new LinList();
	string wirklichLoeschen = STD_VALUE_WIRKLICH_LOESCHEN;
	string name;
	int position = STD_ANSWER_VALUE;
	int answer = STD_ANSWER_VALUE;
	do{
		try{
			cout << SEPERATOR << endl << SEPERATOR_MANUELL << endl << SEPERATOR << endl;
			cout << *liste << endl << endl;
			cout << MANUELLDIALOG_OPTION_ONE << endl << MANUELLDIALOG_OPTION_TWO << endl << MANUELLDIALOG_OPTION_THREE
				<< endl << MANUELLDIALOG_OPTION_FOUR << endl << MANUELLDIALOG_OPTION_FIVE << endl << MANUELLDIALOG_OPTION_SIX
				<< endl << MANUELLDIALOG_OPTION_SEVEN << endl << MANUELLDIALOG_OPTION_ZERO << endl << STANDARDCHOICEPHRASE;
			cin >> answer;
			clearInput();
			switch (answer)
			{
			case BACK:
				cout << SEPERATOR_DELETE_LISTE << endl << CLEAR_CONFIRMATION;
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
				liste->push_back(name);
				break;
			case PUSH_FRONT:
				cout << SEPERATOR_PUSH << endl;
				cout << MANUELLDIALOG_ELEMENT_NEU_NAME;
				cin >> name;
				clearInput();
				liste->push_front(name);
				break;
			case POP_BACK:
				liste->pop_back();
				break;
			case POP_FRONT:
				liste->pop_front();
				break;
			case INSERT_ELEMENT:
				cout << SEPERATOR_PUSH << endl;
				cout << MANUELLDIALOG_ELEMENT_NEU_NAME;
				cin >> name;
				clearInput();
				cout << MANUELLDIALOG_ELEMENT_NEU_POSITION;
				cin >> position;
				clearInput();
				liste->insert(position, name);
				break;
			case ERASE_ELEMENT:
				cout << MANUELLDIALOG_ELEMENT_NEU_POSITION;
				cin >> position;
				clearInput();
				cout << SEPERATOR_ERASE << endl << CLEAR_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				} else {
					liste->erase(position);
				}
				cout << endl;
				break;
			case CLEAR:
				cout << SEPERATOR_DELETE_LISTE << endl << CLEAR_CONFIRMATION;
				cin >> wirklichLoeschen;
				clearInput();
				if (wirklichLoeschen != STD_VALUE_WIRKLICH_LOESCHEN_YES){
					answer = ABORT;
				} else {
					liste->clear();
				}
				cout << endl;
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
				break;
			}
		}
		catch (ElementException& e){

		}
	} while (answer != BACK);
	delete liste;
}

void ListenDialog::clearInput(){
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}
