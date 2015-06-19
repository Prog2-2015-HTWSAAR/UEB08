/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file	ListElement.h
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @details Basierend auf Folz Klasse
* @date 14.06.2015
*/
#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_
#include <string>
#include <stdexcept>
using namespace std;
typedef string InhaltTyp;

class ElementException : public logic_error {
public:
    ElementException(const string& msg = "") : logic_error(msg) {}
};

class ListElement {
public:
	/**
	* @brief Konstruktor
	* @param inhalt Der Inhalt des Listenelements
	* @param previous Das Vorangegangene Element
	* @param next Das Nachfolgende Element
	*/
	ListElement(InhaltTyp, ListElement* =0, ListElement* =0);
	~ListElement();
	friend class LinList;
	/**
	* @brief <<Operator zur ausgabe in einen stream
	* @param o Streamreferenz
	* @param listElement Listenreferenz
	* @returns referenz auf stream mit angehaengtem ListenString
	*/
	friend ostream& operator<< (ostream& o, const ListElement& listElement);
	/**
	* @brief <<Operator zum auswerten eines isteams
	* @param i Streamreferenz
	* @param listElement Listenreferenz
	* @returns referenz auf stream mit angehaengtem istream Element
	*/
	friend istream& operator>> (istream& i, ListElement& listElement);
private:
	InhaltTyp inhalt;
	ListElement* previous;
	ListElement* next;
};

#endif /* LISTELEMENT_H_ */
