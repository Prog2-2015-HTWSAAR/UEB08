/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb08 *.o
 * @file ListenDialog.cpp
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
const string ListenDialog::PARSE_COPY = "COPY";
const string ListenDialog::LANGUAGE_GERMAN = "de_DE.xml";
const string ListenDialog::LANGUAGE_ENGLISH = "en_US.xml";
const string ListenDialog::LANGUAGE_HODOR = "hodor_WESTEROS.xml";
const string ListenDialog::LANGUAGE_STD = "std.xml";
const string ListenDialog::STD_INP_PHRASE = "STD_INP_PHRASE";
// const strings
// Languagedialog
const string ListenDialog::STD_LANG_NOT_FOUND = "Language std NOT Found";
const string ListenDialog::DE_DE_LANG_NOT_FOUND = "DE_DE_LANG_NOT_FOUND";
const string ListenDialog::EN_US_LANG_NOT_FOUND = "EN_US_LANG_NOT_FOUND";
const string ListenDialog::HODOR_WESTEROS_LANG_NOT_FOUND =
		"HODOR_WESTEROS_LANG_NOT_FOUND";
const string ListenDialog::PARSE_LANGUAGEDIALOG = "LANGUAGE_DIALOGE";
// Maindialog
const string ListenDialog::PARSE_SEPERATOR_LINLIST_BLOCK =
		"SEPERATOR_LINLIST_BLOCK";
const string ListenDialog::PARSE_MAINDIALOG = "MAINDIALOG";
//ManuellDialog
const string ListenDialog::PARSE_MANUELLDIALOG = "MANUELLDIALOG";
const string ListenDialog::PARSE_SEPERATOR_MANUELL_BLOCK =
		"SEPERATOR_MANUELL_BLOCK";
const string ListenDialog::PARSE_SEPERATOR_INSERT = "SEPERATOR_INSERT";
const string ListenDialog::PARSE_SEPERATOR_ERASE = "SEPERATOR_ERASE";
const string ListenDialog::PARSE_SEPERATOR_CLEAR = "SEPERATOR_CLEAR";
const string ListenDialog::PARSE_SEPERATOR_PUSH = "SEPERATOR_PUSH";
const string ListenDialog::PARSE_SEPERATOR_POP = "SEPERATOR_POP";
const string ListenDialog::PARSE_SEPERATOR_BACKUP = "SEPERATOR_BACKUP";
const string ListenDialog::PARSE_SEPERATOR_DELETE_LISTE =
		"SEPERATOR_DELETE_LISTE";
const string ListenDialog::PARSE_PHRASE_NAME = "PHRASE_NAME";
const string ListenDialog::PARSE_PHRASE_POSITION = "PHRASE_POSITION";
const string ListenDialog::PARSE_PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION =
		"PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION";
const string ListenDialog::PARSE_PHRASE_ELEMENT_DELETE_CONFIRMATION =
		"PHRASE_ELEMENT_DELETE_CONFIRMATION";
const string ListenDialog::PARSE_PHRASE_CLEAR_CONFIRMATION =
		"PHRASE_CLEAR_CONFIRMATION";
const string ListenDialog::PARSE_PHRASE_LOAD_CONFIRMATION =
		"PHRASE_LOAD_CONFIRMATION";
const string ListenDialog::PARSE_PHRASE_SAVE_CONFIRMATION =
		"PHRASE_SAVE_CONFIRMATION";
const string ListenDialog::PARSE_PHRASE_READ_STREAM = "PHRASE_READ_STREAM";
const string ListenDialog::CONFIRM_DELETE = "CONFIRM_DELETE";
// Automatic TEST
const string ListenDialog::PARSE_A_INIT_PUSH = "A_INIT_PUSH";
const string ListenDialog::PARSE_A_PUSH_BACK = "A_PUSH_BACK";
const string ListenDialog::PARSE_A_PUSH_FRONT = "A_PUSH_FRONT";
const string ListenDialog::PARSE_A_POP_BACK = "A_POP_BACK";
const string ListenDialog::PARSE_A_POP_FRONT = "A_POP_FRONT";
const string ListenDialog::PARSE_A_INSERT = "A_INSERT";
const string ListenDialog::PARSE_A_ERASE = "A_ERASE";
const string ListenDialog::PARSE_A_READ = "A_READ_INPUT_STREAM";
const string ListenDialog::PARSE_A_CLEAR = "A_CLEAR";
const string ListenDialog::PARSE_A_POP_EMPTY = "A_POP_EMPTY";
const string ListenDialog::PARSE_A_INIT = "A_INIT";
const string ListenDialog::PARSE_A_BACK = "A_BACK";
const string ListenDialog::PARSE_A_FRONT = "A_FRONT";
const string ListenDialog::PARSE_A_IMHERE = "A_IMHERE";
const string ListenDialog::PARSE_A_HIGH = "A_HIGH";
const string ListenDialog::PARSE_A_LOW = "A_LOW";
const string ListenDialog::PARSE_A_INPUT_STREAM = "A_INPUT_STREAM";
const string ListenDialog::PARSE_A_INPUT_STREAM_VALUE = "A_INPUT_STREAM_VALUE";
const string ListenDialog::PARSE_AUTOMATICTEST =
		"SEPERATOR_AUTOMATIC_TEST_BLOCK";
//const string ListenDialog::PARSE_ = "";
//const string ListenDialog::PARSE_ = "";
//const string ListenDialog::PARSE_ = "";
// Allgemein
const string ListenDialog::PARSE_INPUT_ERROR = "INPUT_E";
const string ListenDialog::PARSE_STD_ERROR = "STD_E";
const string ListenDialog::PARSE_EQUAL = "EQUAL";
const string ListenDialog::PARSE_NON_EQUAL = "NON_EQUAL";
const string ListenDialog::PARSE_APPEND_LIST = "APPEND_LIST";
const string ListenDialog::PARSE_COMBINE_LIST = "COMBINE_LIST";
const string ListenDialog::PARSE_ELEMENT_AT_POSITION = "ELEMENT_AT_POSITION";
const string ListenDialog::CHECK_EQUAL = "CHECK_EQUAL";
const string ListenDialog::CHECK_NON_EQUAL = "CHECK_NON_EQUAL";
//const Int
const int ListenDialog::STD_ANSWER_VALUE = -1;
const int ListenDialog::ZERO_VALUE = 0;
const int ListenDialog::INPUT_ONE = 1;
const int ListenDialog::INPUT_VALUE = 2;
const int ListenDialog::ARRAY_OPERATOR_TEST_VALUE = 3;
const int ListenDialog::MAX_RUNS_FILE_READ = 4;
const int ListenDialog::HIGH_VALUE = 1000;
const int ListenDialog::TEST_QUANTITY = 21;
const int ListenDialog::A_REGULAR_OUTPUT_STOPER = 13;
/**
 * @brief Konstruktor
 */
ListenDialog::ListenDialog() {
}
/**
 * @brief Dekonstruktor
 */
ListenDialog::~ListenDialog() {
}
/**
 * @brief ListenDialog::mainDialog()
 * @details HauptDialog Auswahl Auto Manuell Exit
 */
void ListenDialog::mainDialog(string &fileName) {
	string error_input = parsePhrases(fileName, PARSE_INPUT_ERROR);
	string seperator_LinListe = parsePhrases(fileName,
			PARSE_SEPERATOR_LINLIST_BLOCK);
	string main_dialog = parsePhrases(fileName, PARSE_MAINDIALOG) + SPACER;
	int answer;
	do {
		cout << seperator_LinListe << endl << main_dialog;
		answer = readIntegerInput();
		switch (answer) {
		case EXIT:
			break;
		case AUTOMATICTEST:
			automaticTest(fileName);
			break;
		case MANUELLDIALOG:
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
void ListenDialog::automaticTest(string &fileName) {
	string phrase_position = parsePhrases(fileName, PARSE_PHRASE_POSITION)
			+ SPACER;
	string phrase_Init_Push = parsePhrases(fileName, PARSE_A_INIT_PUSH)
			+ SPACER;
	string phrase_Push_Back = parsePhrases(fileName, PARSE_A_PUSH_BACK)
			+ SPACER;
	string phrase_Push_Front = parsePhrases(fileName, PARSE_A_PUSH_FRONT)
			+ SPACER;
	string phrase_Pop_Back = parsePhrases(fileName, PARSE_A_POP_BACK);
	string phrase_Pop_Front = parsePhrases(fileName, PARSE_A_POP_FRONT);
	string phrase_Insert = parsePhrases(fileName, PARSE_A_INSERT) + SPACER;
	string phrase_IMHERE = parsePhrases(fileName, PARSE_A_IMHERE);
	string phrase_High = parsePhrases(fileName, PARSE_A_HIGH);
	string phrase_Init = parsePhrases(fileName, PARSE_A_INIT);
	string phrase_Front = parsePhrases(fileName, PARSE_A_FRONT);
	string phrase_Back = parsePhrases(fileName, PARSE_A_BACK);
	string phrase_Low = parsePhrases(fileName, PARSE_A_LOW);
	string phrase_Erase = parsePhrases(fileName, PARSE_A_ERASE) + SPACER;
	string phrase_Input_Stream = parsePhrases(fileName, PARSE_A_INPUT_STREAM)
			+ SPACER;
	string phrase_Clear = parsePhrases(fileName, PARSE_A_CLEAR);
	string phrase_Pop_Empty = parsePhrases(fileName, PARSE_A_POP_EMPTY);
	string phrase_Input_Stream_Value = parsePhrases(fileName,
			PARSE_A_INPUT_STREAM_VALUE);
	string phrase_Copy = parsePhrases(fileName, PARSE_COPY);
	istringstream is(phrase_Input_Stream_Value);
	string seperator_Automatic_Test = parsePhrases(fileName,
			PARSE_AUTOMATICTEST);
	string error_input = parsePhrases(fileName, PARSE_INPUT_ERROR);
	string error_std = parsePhrases(fileName, PARSE_STD_ERROR);
	string phrase_Equal = parsePhrases(fileName, PARSE_EQUAL);
	string phrase_NON_Equal = parsePhrases(fileName, PARSE_NON_EQUAL);
	string phrase_Append = parsePhrases(fileName, PARSE_APPEND_LIST);
	string phrase_Combine = parsePhrases(fileName, PARSE_COMBINE_LIST);
	string phrase_Element_At_Position = parsePhrases(fileName,
			PARSE_ELEMENT_AT_POSITION) + SPACER;
	string phrase_Check_Equal = parsePhrases(fileName, CHECK_EQUAL);
	string phrase_Check_Non_Equal = parsePhrases(fileName, CHECK_NON_EQUAL);
	string phrase_Std_Input = parsePhrases(LANGUAGE_STD, STD_INP_PHRASE)
			+ SPACER;
	LinList* linListe = NULL;
	LinList* linListeCopy = NULL;
	linListe = new LinList();
	linListeCopy = new LinList();
	int runCounter = ZERO_VALUE;
	cout << seperator_Automatic_Test << endl << endl;
	do {
		try {
			if (runCounter < A_REGULAR_OUTPUT_STOPER) {
				cout << *linListe << endl;
			}
			switch (runCounter) {
			case AUTO_INIT:
				cout << phrase_Init_Push << phrase_Init << endl;
				linListe->push_back(phrase_Init);
				break;
			case AUTO_PUSH_BACK:
				cout << phrase_Push_Back << phrase_Back << endl;
				linListe->push_back(phrase_Back);
				break;
			case AUTO_PUSH_FRONT:
				cout << phrase_Push_Front << phrase_Front << endl;
				linListe->push_front(phrase_Front);
				break;
			case AUTO_POP_BACK:
				cout << phrase_Pop_Back << endl;
				linListe->pop_back();
				break;
			case AUTO_POP_FRONT:
				cout << phrase_Pop_Front << endl;
				linListe->pop_front();
				break;
			case AUTO_INSERT:
				cout << phrase_Insert << phrase_IMHERE << SPACER
						<< phrase_position << INPUT_ONE << endl;
				linListe->insert(INPUT_ONE, phrase_IMHERE);
				break;
			case AUTO_INSERT_HIGH_VALUE:
				cout << phrase_Insert << phrase_High << SPACER
						<< phrase_position << HIGH_VALUE << endl;
				linListe->insert(HIGH_VALUE, phrase_High);
				break;
			case AUTO_INSERT_LOW_VALUE:
				cout << phrase_Insert << phrase_Low << SPACER << phrase_position
						<< ZERO_VALUE << endl;
				linListe->insert(ZERO_VALUE, phrase_Low);
				break;
			case AUTO_ERASE:
				cout << phrase_Erase << INPUT_VALUE << endl;
				linListe->erase(INPUT_VALUE);
				break;
			case AUTO_ERASE_ZERO:
				cout << phrase_Erase << ZERO_VALUE << endl;
				linListe->erase(ZERO_VALUE);
				break;
			case AUTO_ERASE_NON_EXISTENT_ELEMENT:
				cout << phrase_Erase << HIGH_VALUE << endl;
				linListe->erase(HIGH_VALUE);
				break;
			case AUTO_INPUT_STREAM:
				cout << phrase_Input_Stream << phrase_Input_Stream_Value
						<< endl;
				is >> *linListe;
				break;
			case AUTO_COPY_TEST:
				*linListeCopy = *linListe;
				cout << phrase_Copy << endl << endl << linListe << SPACER
						<< *linListe << endl << linListeCopy << SPACER
						<< *linListeCopy << endl;
				break;
			case AUTO_TEST_EQUAL_ONE:
				cout << phrase_Check_Equal << endl << endl << *linListe << endl
						<< *linListeCopy << endl;
				if (*linListe == *linListeCopy) {
					cout << phrase_Equal << endl << endl;
				} else {
					cout << phrase_NON_Equal << endl << endl;
				}
				break;
			case AUTO_TEST_NON_EQUAL_ONE:
				cout << phrase_Check_Non_Equal << endl << endl << *linListe
						<< endl << *linListeCopy << endl;
				if (!(*linListe != *linListeCopy)) {
					cout << phrase_Equal << endl << endl;
				} else {
					cout << phrase_NON_Equal << endl << endl;
				}
				break;
			case AUTO_APPEND:
				cout << phrase_Append << endl;
				*linListe += *linListeCopy;
				cout << *linListe << endl;
				break;
			case AUTO_TEST_EQUAL_TWO:
				cout << phrase_Check_Equal << endl << endl << *linListe << endl
						<< *linListeCopy << endl;
				if (*linListe == *linListeCopy) {
					cout << phrase_Equal << endl << endl;
				} else {
					cout << phrase_NON_Equal << endl << endl;
				}
				break;
			case AUTO_TEST_NON_EQUAL_TWO:
				cout << phrase_Check_Non_Equal << endl << endl << *linListe
						<< endl << *linListeCopy << endl;
				if (!(*linListe != *linListeCopy)) {
					cout << phrase_Equal << endl << endl;
				} else {
					cout << phrase_NON_Equal << endl << endl;
				}
				break;
			case AUTO_COMBINE:
				cout << phrase_Append << endl;
				*linListe = *linListe + *linListeCopy;
				cout << *linListe << endl;
				break;
			case ELEMENT_AT_POSITION:
				cout << phrase_Element_At_Position << ARRAY_OPERATOR_TEST_VALUE
						<< endl;
				cout << phrase_Std_Input
						<< (*linListe)[ARRAY_OPERATOR_TEST_VALUE] << endl
						<< endl;
				break;
			case AUTO_CLEAR:
				cout << phrase_Clear << endl;
				linListe->clear();
				break;
			case POP_EMPTY:
				cout << phrase_Pop_Empty << endl;
				linListe->pop_back();
				break;
			}
		} catch (LinListException& e) {
			cout << error_std << e.what() << endl;
		} catch (ElementException& e) {
			cout << error_std << e.what() << endl;
		}
		runCounter++;
	} while (runCounter < TEST_QUANTITY);
}
/**
 * @brief ListenDialog::manuellDialog()
 * @details Manuelle Steuerung Des Programmes
 */
void ListenDialog::manuellDialog(string &fileName) {
	LinList* linListe = NULL;
	LinList* linListeCopy = NULL;
	linListe = new LinList();
	linListeCopy = new LinList();
	string wirklichLoeschen;
	string name;
	string error_input = parsePhrases(fileName, PARSE_INPUT_ERROR);
	string error_std = parsePhrases(fileName, PARSE_STD_ERROR);
	string manuell_dialog = parsePhrases(fileName, PARSE_MANUELLDIALOG)
			+ SPACER;
	string seperator_delete_liste = parsePhrases(fileName,
			PARSE_SEPERATOR_DELETE_LISTE);
	string seperator_maunuell = parsePhrases(fileName,
			PARSE_SEPERATOR_MANUELL_BLOCK);
	string seperator_insert = parsePhrases(fileName, PARSE_SEPERATOR_INSERT);
	string seperator_erase = parsePhrases(fileName, PARSE_SEPERATOR_ERASE);
	string seperator_clear = parsePhrases(fileName, PARSE_SEPERATOR_CLEAR);
	string seperator_push = parsePhrases(fileName, PARSE_SEPERATOR_PUSH);
	string seperator_pop = parsePhrases(fileName, PARSE_SEPERATOR_POP);
	string seperator_backup = parsePhrases(fileName, PARSE_SEPERATOR_BACKUP);
	string seperator_delete = parsePhrases(fileName,
			PARSE_SEPERATOR_DELETE_LISTE);
	string phrase_name = parsePhrases(fileName, PARSE_PHRASE_NAME) + SPACER;
	string phrase_position = parsePhrases(fileName, PARSE_PHRASE_POSITION)
			+ SPACER;
	string phrase_element_delete_back_confirmation = parsePhrases(fileName,
			PARSE_PHRASE_ELEMENT_DELETE_BACK_CONFIRMATION) + SPACER;
	string phrase_element_delete_confirmation = parsePhrases(fileName,
			PARSE_PHRASE_ELEMENT_DELETE_CONFIRMATION) + SPACER;
	string phrase_clear_confirmation = parsePhrases(fileName,
			PARSE_PHRASE_CLEAR_CONFIRMATION) + SPACER;
	string phrase_load_confirmation = parsePhrases(fileName,
			PARSE_PHRASE_LOAD_CONFIRMATION) + SPACER;
	string phrase_save_confirmation = parsePhrases(fileName,
			PARSE_PHRASE_SAVE_CONFIRMATION) + SPACER;
	string phrase_read_stream = parsePhrases(fileName, PARSE_PHRASE_READ_STREAM)
			+ SPACER;
	string confirm_Delete = parsePhrases(fileName, CONFIRM_DELETE);
	string phrase_Copy = parsePhrases(fileName, PARSE_COPY);
	int position;
	int answer;
	do {
		try {
			cout << seperator_maunuell << endl << *linListe << endl
					<< manuell_dialog;
			cout.clear();
			answer = readIntegerInput();
			switch (answer) {
			case BACK:
				cout << seperator_delete_liste << endl
						<< phrase_element_delete_back_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete) {
					answer = ABORT;
				}
				cout << endl;
				break;
			case PUSH_BACK:
				cout << seperator_push << endl;
				cout << phrase_name;
				name = readStringInput();
				;
				linListe->push_back(name);
				break;
			case PUSH_FRONT:
				cout << seperator_push << endl;
				cout << phrase_name;
				name = readStringInput();
				;
				linListe->push_front(name);
				break;
			case POP_BACK:
				cout << seperator_pop << endl
						<< phrase_element_delete_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete) {
					answer = ABORT;
				} else {
					linListe->pop_back();
				}
				break;
			case POP_FRONT:
				cout << seperator_pop << endl
						<< phrase_element_delete_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete) {
					answer = ABORT;
				} else {
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
				cout << seperator_erase << endl
						<< phrase_element_delete_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete) {
					answer = ABORT;
				} else {
					linListe->erase(position);
				}
				cout << endl;
				break;
			case CLEAR:
				cout << seperator_delete << endl << phrase_clear_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete) {
					answer = ABORT;
				} else {
					linListe->clear();
				}
				cout << endl;
				break;
			case STREAM:
				cout << seperator_delete << endl << phrase_load_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete) {
					answer = ABORT;
				} else {
					cout << phrase_read_stream;
					cin >> *linListe;
				}
				break;
			case SAVE_BACKUP:
				cout << seperator_backup << endl;
				cout << *linListeCopy << endl;
				cout << seperator_delete_liste << endl
						<< phrase_save_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete) {
					answer = ABORT;
				} else {
					*linListeCopy = *linListe;
					cout << phrase_Copy << endl << linListe << SPACER
							<< *linListe << endl << linListeCopy << SPACER
							<< *linListeCopy << endl;
				}
				break;
			case LOAD_BACKUP:
				cout << seperator_backup << endl;
				cout << *linListeCopy << endl;
				cout << seperator_delete_liste << endl
						<< phrase_load_confirmation;
				wirklichLoeschen = readStringInput();
				if (wirklichLoeschen != confirm_Delete) {
					answer = ABORT;
				} else {
					*linListe = *linListeCopy;
					cout << phrase_Copy << endl << linListeCopy << SPACER
							<< *linListeCopy << endl << linListe << SPACER
							<< *linListe << endl;
				}
				break;
			case ABORT:
				break;
			default:
				cout << error_input << endl;
				cout.clear();
				break;
			}
			if (answer != 0) {
				answer = STD_ANSWER_VALUE;
			}
		} catch (LinListException& e) {
			cout << error_std << e.what() << endl;
		} catch (ElementException& e) {
			cout << error_std << e.what() << endl;
		}
	} while (answer != BACK);
	delete linListe;
}
/**
 * @brief initLanguage()
 * @details Language Dialog
 */
void ListenDialog::initLanguage() {
	string error_input = parsePhrases(LANGUAGE_STD, PARSE_INPUT_ERROR);
	string error_de_DE_Not_Found = parsePhrases(LANGUAGE_STD,
			DE_DE_LANG_NOT_FOUND);
	string error_en_US_Not_Found = parsePhrases(LANGUAGE_STD,
			PARSE_INPUT_ERROR);
	string error_hodor_WESTEROS_Not_Found = parsePhrases(LANGUAGE_STD,
			PARSE_INPUT_ERROR);
	string language_dialog = parsePhrases(LANGUAGE_STD, PARSE_LANGUAGEDIALOG)
			+ SPACER;
	string chosenLanguage = LANGUAGE_GERMAN;
	if (fileExists(LANGUAGE_STD)) {
		int answer = STD_ANSWER_VALUE;
		do {
			if (answer != START_MAINDIALOG) {
				cout << language_dialog;
				answer = readIntegerInput();
				if (answer == START_MAINDIALOG || answer == runAgain) {
					answer = STD_ANSWER_VALUE;
				}
			}
			switch (answer) {
			case CLOSEPROGRAM:
				break;
			case GERMAN:
				if (fileExists(LANGUAGE_GERMAN)) {
					chosenLanguage = LANGUAGE_GERMAN;
					answer = START_MAINDIALOG;
				} else {
					cout << error_de_DE_Not_Found << endl;
					clearInput();
				}
				break;
			case ENGLISH:
				if (fileExists(LANGUAGE_ENGLISH)) {
					chosenLanguage = LANGUAGE_ENGLISH;
					answer = START_MAINDIALOG;
				} else {
					cout << error_en_US_Not_Found << endl;
					clearInput();
				}
				break;
			case HODOR:
				if (fileExists(LANGUAGE_HODOR)) {
					chosenLanguage = LANGUAGE_HODOR;
					answer = START_MAINDIALOG;
				} else {
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
	} else {
		cout << STD_LANG_NOT_FOUND << endl;
		clearInput();
	}
}
/**
 * @brief parsePhrases Xml Parser
 * @param fileName Xml Datei die genutzt werden soll
 * @param begin String in Xml Datei der als start und endpunkt gennommen werden soll
 */
string ListenDialog::parsePhrases(string fileName, string begin) {
	fstream file;
	string anfang = "<" + begin + ">";
	string ende = "</" + begin + ">";
	string cache;
	string line;
	string ausgabe;
	bool found = false;
	bool firstRun = true;
	bool stop = false;
	bool streamWritten = false;
	const char* constName = fileName.c_str();
	file.open(constName);
	while (getline(file, line)) {
		trim(line);
		if (!stop && found) {
			if (!firstRun) {
				ausgabe = ausgabe + cache;
				streamWritten = true;
			}
			if (firstRun) {
				firstRun = false;
			}
		}
		if (found && !stop) {
			if (strcmp(ende.c_str(), line.c_str()) == 0) {
				stop = true;
			} else {
				cache = line;
				if (streamWritten) {
					ausgabe = ausgabe + '\n';
				}
			}
		}
		if (strcmp(anfang.c_str(), line.c_str()) == 0 && !found) {
			found = true;
		}
	}
	file.close();
	return ausgabe;
}
/**
 * @brief clearInput Clear Cin
 */
void ListenDialog::clearInput() {
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}
/**
 * @brief readIntegerInput read in int
 */
int ListenDialog::readIntegerInput() {
	double number = readDoubleInput();
	if (!(fmod(number, INPUT_ONE) == ZERO_VALUE)) {
		number = STD_ANSWER_VALUE;
	}
	return (int) number;
}
/**
 * @brief readIntegerInput read in double
 */
double ListenDialog::readDoubleInput() {
	double number;
	if (cin >> number) {
	} else {
		number = STD_ANSWER_VALUE;
	}
	clearInput();
	return number;
}
/**
 * @brief readIntegerInput read in string
 */
string ListenDialog::readStringInput() {
	string input;
	cin >> input;
	clearInput();
	return input;
}
/**
 * @brief fileExists prüft existenz
 * @param fileName Xml Datei die genutzt werden soll
 */
bool ListenDialog::fileExists(string fileName) {
	const char* constName = fileName.c_str();
	ifstream infile(constName);
	return infile.good();
}
/**
 * @brief trim string trimmer
 * @param str String Referenz
 */
void ListenDialog::trim(string& str) {
	string trim_chars = " \t";
	string::size_type pos = str.find_last_not_of(trim_chars);
	if (pos != std::string::npos) {
		str.erase(pos + 1);
		pos = str.find_first_not_of(trim_chars);
		if (pos != std::string::npos)
			str.erase(0, pos);
	} else
		str.erase(str.begin(), str.end());
}
