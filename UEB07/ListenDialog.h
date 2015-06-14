/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb07 *.o
* @file  ListenDialog.h
* @author Andreas Schreiner & Simon Bastian
*
* @date 14.06.2015
*/
#include "LinList.h"
#include <iostream>
#include <sstream>      

#ifndef LINLIST_LISTENDIALOG_H_
#define LINLIST_LISTENDIALOG_H_
//TODO Implement me Senpai
enum MainDialogOption{ EXIT, AUTOMATICTEST, MANUELLDIALOG};
enum ManuellDialogOption{ BACK, PUSH_BACK, PUSH_FRONT, POP_BACK, POP_FRONT, INSERT_ELEMENT, ERASE_ELEMENT, CLEAR, STREAM, ABORT };
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
	static const char* MAINDIALOG_OPTION_EXIT;
	static const char* MAINDIALOG_OPTION_AUTO_TEST;
	static const char* MAINDIALOG_OPTION_MANUELL;
	//Manuell Dialog
	static const char* MANUELLDIALOG_ELEMENT_NEU_NAME;
	static const char* MANUELLDIALOG_ELEMENT_NEU_POSITION;
	static const char* MANUELLDIALOG_OPTION_BACK;
	static const char* MANUELLDIALOG_OPTION_PUSH_BACK;
	static const char* MANUELLDIALOG_OPTION_PUSH_FRONT;
	static const char* MANUELLDIALOG_OPTION_POP_BACK;
	static const char* MANUELLDIALOG_OPTION_POP_FRONT;
	static const char* MANUELLDIALOG_OPTION_INSERT;
	static const char* MANUELLDIALOG_OPTION_ERASE;
	static const char* MANUELLDIALOG_OPTION_CLEAR;
	static const char* MANUELLDIALOG_OPTION_STREAM;
	static const char* MANUELLDIALOF_STEAM_EINGABE;
	static const char* MANUELLDIALOF_EINGABESYMBOL;
	static const char* ELEMENT_DELETE_CONFIRMATION;
	static const char* CLEAR_CONFIRMATION;
	static const char* STD_VALUE_WIRKLICH_LOESCHEN;
	static const char* STD_VALUE_WIRKLICH_LOESCHEN_YES;
	//AUTO_TEST
	static const char* AUTOMATIC_TEST_HYPHEN;
	static const char* AUTOMATIC_TEST_POSITION;
	static const char* AUTOMATIC_TEST_INIT;
	static const char* AUTOMATIC_TEST_PUSH_BACK;
	static const char* AUTOMATIC_TEST_PUSH_FRONT;
	static const char* AUTOMATIC_TEST_POP_BACK;
	static const char* AUTOMATIC_TEST_POP_FRONT;
	static const char* AUTOMATIC_TEST_INSERT;
	static const char* AUTOMATIC_TEST_ERASE;
	static const char* AUTOMATIC_TEST_INPUT_STREAM;
	static const char* AUTOMATIC_TEST_EINGABE_STREAM_VALUE;
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
	static const int INPUT_ONE;
	static const int INPUT_VALUE;
	static const int HIGH_VALUE;
	static const int TEST_QUANTITY;
	//FKT
	/**
	* @brief mainDialog()
	* @details HauptDialog Auswahl Auto Manuell Exit
	*/
	void mainDialog();
	/**
	* @brief automaticTest()
	* @details Automatischer Test
	*/
	void automaticTest();
	/**
	* @brief manuellDialog()
	* @details Manuelle Steuerung Des Programmes
	*/
	void manuellDialog();
	/**
	* @brief clearInput()
	* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	*/
	void clearInput();

	/**
	* @brief Konstruktor
	*/
	ListenDialog();
	/**
	* @brief Dekonstruktor
	*/
	virtual ~ListenDialog();
};

#endif /* LINLIST_LISTENDIALOG_H_ */
