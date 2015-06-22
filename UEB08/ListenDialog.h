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
						AUTO_INSERT_LOW_VALUE, AUTO_ERASE, AUTO_ERASE_ZERO, AUTO_ERASE_NON_EXISTENT_ELEMENT, AUTO_INPUT_STREAM, AUTO_COPY_TEST, 
						AUTO_TEST_EQUAL_ONE, AUTO_TEST_NON_EQUAL_ONE, AUTO_APPEND, AUTO_TEST_EQUAL_TWO, AUTO_TEST_NON_EQUAL_TWO, AUTO_COMBINE, 
						ELEMENT_AT_POSITION, AUTO_CLEAR, POP_EMPTY };
//enum FileDialogOption{ CLOSE_FILE_DIALOG, SAVE, LOAD };

class ListenDialog {
public:
	//Konstanten 
	//Seperators
	static const char* SPACER;
	static const string PARSE_COPY;

	//Errorphrasses
	// LanguageDialog
	static const string STD_LANG_NOT_FOUND;
	static const string DE_DE_LANG_NOT_FOUND;
	static const string EN_US_LANG_NOT_FOUND;
	static const string HODOR_WESTEROS_LANG_NOT_FOUND;
	static const string PARSE_LANGUAGEDIALOG;
	static const string LANGUAGE_GERMAN;
	static const string LANGUAGE_ENGLISH;
	static const string LANGUAGE_HODOR;
	static const string LANGUAGE_STD;
	static const string STD_INP_PHRASE;
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
	// Automatic Test
	static const string PARSE_AUTOMATICTEST;
	static const string PARSE_A_INIT_PUSH;
	static const string PARSE_A_PUSH_BACK;
	static const string PARSE_A_PUSH_FRONT;
	static const string PARSE_A_POP_BACK;
	static const string PARSE_A_POP_FRONT;
	static const string PARSE_A_INSERT;
	static const string PARSE_A_ERASE;
	static const string PARSE_A_READ;
	static const string PARSE_A_CLEAR;
	static const string PARSE_A_POP_EMPTY;
	static const string PARSE_A_INIT;
	static const string PARSE_A_BACK;
	static const string PARSE_A_FRONT;
	static const string PARSE_A_IMHERE;
	static const string PARSE_A_HIGH;
	static const string PARSE_A_LOW;
	static const string PARSE_A_INPUT_STREAM;
	static const string PARSE_A_INPUT_STREAM_VALUE;
	// Allgemein
	static const string PARSE_INPUT_ERROR;
	static const string PARSE_STD_ERROR;	
	static const string PARSE_EQUAL;
	static const string PARSE_NON_EQUAL;
	static const string PARSE_APPEND_LIST;
	static const string PARSE_COMBINE_LIST;
	static const string PARSE_ELEMENT_AT_POSITION;
	static const string CHECK_EQUAL;
	static const string CHECK_NON_EQUAL;
	//const Int
	static const int STD_ANSWER_VALUE;
	static const int ZERO_VALUE;
	static const int INPUT_ONE;
	static const int INPUT_VALUE;
	static const int HIGH_VALUE;
	static const int TEST_QUANTITY;
	static const int MAX_RUNS_FILE_READ;
	static const int A_REGULAR_OUTPUT_STOPER;
	static const int ARRAY_OPERATOR_TEST_VALUE;

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
	/**
	* @brief initLanguage()
	* @details Language Dialog
	*/
	void initLanguage();
	/**
	* @brief fileExists prüft existenz
	* @param fileName Xml Datei die genutzt werden soll
	*/
	bool fileExists(string fileName);
	/**
	* @brief readIntegerInput read in int
	*/
	int readIntegerInput();
	/**
	* @brief readIntegerInput read in double
	*/
	double readDoubleInput();
	/**
	* @brief readIntegerInput read in string
	*/
	string readStringInput();
	/**
	* @brief parsePhrases Xml Parser
	* @param fileName Xml Datei die genutzt werden soll
	* @param begin String in Xml Datei der als start und endpunkt gennommen werden soll
	*/
	string parsePhrases(string fileName, string begin);
	/**
	* @brief trim string trimmer
	* @param str String Referenz
	*/
	void trim(std::string& str);
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
