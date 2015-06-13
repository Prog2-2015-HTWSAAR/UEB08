/*
 * ListenDialog.h
 *
 *  Created on: 11.06.2015
 *      Author: sbastian
 */
#include "LinList.h"
#include <iostream>
#ifndef LINLIST_LISTENDIALOG_H_
#define LINLIST_LISTENDIALOG_H_
//TODO Implement me Senpai
enum MainDialogOption{ EXIT, AUTOMATICTEST, MANUELLDIALOG};
enum ManuellDialogOption{ BACK, PUSH_BACK, PUSH_FRONT, POP_BACK, POP_FRONT, INSERT_ELEMENT, ERASE_ELEMENT, CLEAR, ABORT };
enum AutomaticTestOption{ AUTO_INIT ,AUTO_PUSH_BACK, AUTO_PUSH_FRONT, AUTO_POP_BACK, AUTO_POP_FRONT, AUTO_INSERT, AUTO_INSERT_HIGH_VALUE, 
						AUTO_INSERT_LOW_VALUE, AUTO_ERASE, AUTO_ERASE_ZERO, AUTO_ERASE_NON_EXISTENT_ELEMENT, AUTO_INPUT_STREAM, AUTO_CLEAR, POP_EMPTY };

class ListenDialog {
public:
	//Konstanten 
	//Seperators
	static const char* SEPERATOR;
	static const char* SEPERATOR_LISTE;
	static const char* SEPERATOR_DELETE_LISTE;
	static const char* SEPERATOR_AUTOMATIC_TEST;
	static const char* SEPERATOR_MANUELL;
	static const char* SEPERATOR_INSERT;
	static const char* SEPERATOR_ERASE;
	static const char* SEPERATOR_CLEAR;
	static const char* SEPERATOR_PUSH;
	static const char* SEPERATOR_POP;
	//Errorphrasses
	static const char* INPUTERRORPHRASE;
	static const char* ERRORPHRASE;
	//STD Phrases
	static const char* STANDARDCHOICEPHRASE;
	//Main Dialog
	static const char* MAINDIALOG_OPTION_ZERO;
	static const char* MAINDIALOG_OPTION_ONE;
	static const char* MAINDIALOG_OPTION_TWO;
	//Manuell Dialog
	static const char* MANUELLDIALOG_ELEMENT_NEU_NAME;
	static const char* MANUELLDIALOG_ELEMENT_NEU_POSITION;
	static const char* MANUELLDIALOG_OPTION_ZERO;
	static const char* MANUELLDIALOG_OPTION_ONE;
	static const char* MANUELLDIALOG_OPTION_TWO;
	static const char* MANUELLDIALOG_OPTION_THREE;
	static const char* MANUELLDIALOG_OPTION_FOUR;
	static const char* MANUELLDIALOG_OPTION_FIVE;
	static const char* MANUELLDIALOG_OPTION_SIX;
	static const char* MANUELLDIALOG_OPTION_SEVEN;
	static const char* ELEMENT_DELETE_CONFIRMATION;
	static const char* CLEAR_CONFIRMATION;
	static const char* STD_VALUE_WIRKLICH_LOESCHEN;
	static const char* STD_VALUE_WIRKLICH_LOESCHEN_YES;
	//AUTO_TEST
	static const char* AUTOMATIC_TEST_INIT;
	static const char* AUTOMATIC_TEST_PUSH_BACK;
	static const char* AUTOMATIC_TEST_PUSH_FRONT;
	static const char* AUTOMATIC_TEST_POP_BACK;
	static const char* AUTOMATIC_TEST_POP_FRONT;
	static const char* AUTOMATIC_TEST_INSERT;
	static const char* AUTOMATIC_TEST_INSERT_HIGH;
	static const char* AUTOMATIC_TEST_INSERT_ZERO;
	static const char* AUTOMATIC_TEST_ERASE;
	static const char* AUTOMATIC_TEST_ERASE_ZERO;
	static const char* AUTOMATIC_TEST_ERASE_NON_EXISTENCE;
	static const char* AUTOMATIC_TEST_INPUT_STREAM;
	static const char* AUTOMATIC_TEST_CLEAR;
	static const char* AUTOMATIC_TEST_POP_EMPTY_LIST;
	static const char* AUTOMATIC_TEST_ELEMENT_INIT;
	static const char* AUTOMATIC_TEST_ELEMENT_BACK;
	static const char* AUTOMATIC_TEST_ELEMENT_FRONT;
	static const char* AUTOMATIC_TEST_ELEMENT_INSERT;
	static const char* AUTOMATIC_TEST_ELEMENT_INSERT_HIGH;
	static const char* AUTOMATIC_TEST_ELEMENT_INSERT_LOW;
	static const char* AUTOMATIC_TEST_EINGABE_STREAM;
	//const Int
	static const int STD_ANSWER_VALUE;
	static const int ZERO_VALUE;
	static const int INPUT_VALUE;
	static const int HIGH_VALUE;
	static const int TEST_QUANTITY;

	//FKT
	void mainDialog();
	void automaticTest();

	void manuellDialog();
	void clearInput();
	ListenDialog();
	virtual ~ListenDialog();
};

#endif /* LINLIST_LISTENDIALOG_H_ */
