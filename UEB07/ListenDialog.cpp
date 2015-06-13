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
const char* ListenDialog::MANUELLDIALOG_OPTION_ZERO = "(0) BACK";
const char* ListenDialog::MANUELLDIALOG_OPTION_ONE = "(1) push back";
const char* ListenDialog::MANUELLDIALOG_OPTION_TWO = "(2) push front";
const char* ListenDialog::MANUELLDIALOG_OPTION_THREE = "(3) pop back";
const char* ListenDialog::MANUELLDIALOG_OPTION_FOUR = "(4) pop front";
const char* ListenDialog::MANUELLDIALOG_OPTION_FIVE = "(5) insert before position";
const char* ListenDialog::MANUELLDIALOG_OPTION_SIX = "(6) erase position";
const char* ListenDialog::MANUELLDIALOG_OPTION_SEVEN = "(0) CLEAR";
const char* ListenDialog::ELEMENT_DELETE_CONFIRMATION = "ELEMENT wirklich Loeschen (j)=Ja: ";
const char* ListenDialog::CLEAR_CONFIRMATION = "LISTE wirklich Leeren (j)=Ja: ";
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
const char* ListenDialog::AUTOMATIC_TEST_ERASE_NON_EXISTENCE = "-ERASE NON EXISTENT ELEMENT-";
const char* ListenDialog::AUTOMATIC_TEST_CLEAR = "-CLEAR-";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_INIT = "INIT";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_BACK = "BACK";
const char* ListenDialog::AUTOMATIC_TEST_ELEMENT_FRONT = "FRONT";


//const Int
const int ListenDialog::STD_ANSWER_VALUE = -1;
const int ListenDialog::ZERO_VALUE = 0;
const int ListenDialog::HIGH_VALUE = 1000;
const int ListenDialog::TEST_QUANTITY = 12;

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
				break;
			case AUTO_INSERT_HIGH_VALUE:
				cout << AUTOMATIC_TEST_INSERT_HIGH << endl;
				break;
			case AUTO_INSERT_LOW_VALUE:
				cout << AUTOMATIC_TEST_INSERT_ZERO << endl;
				break;
			case AUTO_ERASE:
				cout << AUTOMATIC_TEST_ERASE << endl;
				break;
			case AUTO_ERASE_ZERO:
				cout << AUTOMATIC_TEST_ERASE_ZERO << endl;
				break;
			case AUTO_ERASE_NON_EXISTENT_ELEMENT:
				cout << AUTOMATIC_TEST_ERASE_NON_EXISTENCE << endl;
				break;
			case AUTO_CLEAR:
				cout << AUTOMATIC_TEST_CLEAR << endl;
				break;
			}
		}
		catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
		catch (ElementException& e){

		}
		runCounter++;
	} while (runCounter < TEST_QUANTITY);
}

void ListenDialog::manuellDialog(){
	LinList* liste = NULL;
	liste = new LinList();
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
				break;
			case PUSH_BACK:
				break;
			case PUSH_FRONT:
				break;
			case POP_BACK:
				break;
			case POP_FRONT:
				break;
			case INSERT_ELEMENT:
				break;
			case ERASE_ELEMENT:
				break;
			case CLEAR:
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
				break;
			}
		}
		catch (ElementException& e){

		}
	} while (answer != BACK);
}

void ListenDialog::clearInput(){
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}