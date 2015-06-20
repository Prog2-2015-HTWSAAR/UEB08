/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file  ListenDialog.h
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @date 14.06.2015
*/
#include "LinList.h"
#include <iostream>
#include <sstream>      

#ifndef LINLIST_LISTENDIALOG_H_
#define LINLIST_LISTENDIALOG_H_
enum LanguageDialogOption{ CLOSEPROGRAM, GERMAN, ENGLISH, HODOR, START_MAINDIALOG, runAgain};
enum MainDialogOption{ EXIT, AUTOMATICTEST, MANUELLDIALOG};
enum ManuellDialogOption{ BACK, PUSH_BACK, PUSH_FRONT, POP_BACK, POP_FRONT, INSERT_ELEMENT, ERASE_ELEMENT, CLEAR, STREAM, SAVE_BACKUP, LOAD_BACKUP, FILE_DIALOG, ABORT };
enum AutomaticTestOption{ AUTO_INIT ,AUTO_PUSH_BACK, AUTO_PUSH_FRONT, AUTO_POP_BACK, AUTO_POP_FRONT, AUTO_INSERT, AUTO_INSERT_HIGH_VALUE, 
						AUTO_INSERT_LOW_VALUE, AUTO_ERASE, AUTO_ERASE_ZERO, AUTO_ERASE_NON_EXISTENT_ELEMENT, AUTO_INPUT_STREAM, AUTO_COPY_TEST, AUTO_CLEAR, POP_EMPTY };
//enum FileDialogOption{ CLOSE_FILE_DIALOG, SAVE, LOAD };

class ListenDialog {
public:
	//Konstanten 
	//Seperators
	static const char* SPACER;
	//Errorphrasses
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

	static const string READ_END;
	static const string PARSER_READ_END;
	// const strings
	// LanguageDialog
	static const string STD_LANG_NOT_FOUND;
	static const string DE_DE_LANG_NOT_FOUND;
	static const string EN_US_LANG_NOT_FOUND;
	static const string HODOR_WESTEROS_LANG_NOT_FOUND;
	static const string PARSE_LANGUAGEDIALOG;

	// Maindialog
	static const string PARSE_SEPERATOR_LINLIST_BLOCK;
	static const string PARSE_MAINDIALOG;
	//ManuellDialog
	static const string PARSE_MANUELLDIALOG;
	static const string PARSE_SEPERATOR_DELETE_LISTE;
	static const string PARSE_SEPERATOR_MANUELL_BLOCK;
	static const string PARSE_SEPERATOR_INSERT;
	static const string PARSE_SEPERATOR_ERASE;
	static const string PARSE_SEPERATOR_CLEAR;
	static const string PARSE_SEPERATOR_PUSH ;
	static const string PARSE_SEPERATOR_POP;
	static const string PARSE_SEPERATOR_BACKUP;
	static const string PARSE_PHRASE_NAME;
	static const string PARSE_PHRASE_POSITION;
	static const string PARSE_PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION;
	static const string PARSE_PHRASE_ELEMENT_DELETE_CONFIRMATION;
	static const string PARSE_PHRASE_CLEAR_CONFIRMATION;
	static const string PARSE_PHRASE_LOAD_CONFIRMATION;
	static const string PARSE_PHRASE_SAVE_CONFIRMATION;
	static const string PARSE_PHRASE_READ_STREAM;
	static const string CONFIRM_DELETE;

	static const string LANGUAGE_GERMAN;
	static const string LANGUAGE_ENGLISH;
	static const string LANGUAGE_HODOR;
	static const string LANGUAGE_STD;
	// Automatic Dialog
	static const string PARSE_AUTOMATICTEST;

	// Allgemein
	static const string PARSE_INPUT_ERROR;
	static const string PARSE_STD_ERROR;
	static const string PARSE_SEPERATOR;


	//const Int

	static const int STD_ANSWER_VALUE;
	static const int ZERO_VALUE;
	static const int INPUT_ONE;
	static const int INPUT_VALUE;
	static const int HIGH_VALUE;
	static const int TEST_QUANTITY;
	static const int MAX_RUNS_FILE_READ;

	//VON BEIDEN VERWENDET
	static const char* COPY_RESULT;
	//FKT
	/**
	* @brief mainDialog()
	* @details HauptDialog Auswahl Auto Manuell Exit
	*/
	void mainDialog(string &fileName);
	/**
	* @brief automaticTest()
	* @details Automatischer Test
	*/
	void automaticTest(string &fileName);
	/**
	* @brief manuellDialog()
	* @details Manuelle Steuerung Des Programmes
	*/
	void manuellDialog(string &fileName);
	/*
	* @brief fileDialog(LinList* linListe, string fileName)
	* @details SAVE AND LOAD
	* @param *linListe Listenreferenz
	* @param fileName Dateiname
	*/
//	void fileDialog(LinList* linListe, string fileName);
	/**
	* @brief clearInput()
	* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	*/
	void clearInput();
	void initLanguage();
	bool fileExists(string fileName);
	int readNumericInput();
	string readVariables(string fileName, int lowerBorder);
	string parsePhrases(string fileName, string begin);

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
