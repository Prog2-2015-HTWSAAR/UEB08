/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file	ListElement.cpp
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @details Basierend auf Folz Klasse
* @date 14.06.2015
*/

#include "ListElement.h"

/**
* @brief Konstruktor
* @param inhalt Der Inhalt des Listenelements
* @param previous Das Vorangegangene Element
* @param next Das Nachfolgende Element
*/
ListElement::ListElement(InhaltTyp inhalt, ListElement* previous,
		                                   ListElement* next) {
	this->inhalt = inhalt;
	this->previous = previous;
	this->next = next;
}
/**
* @brief Dekonstruktor
*/
ListElement::~ListElement() {
	// Nothins to do here!
}
/**
* @brief <<Operator zur ausgabe in einen stream
* @param o Streamreferenz
* @param listElement Listenreferenz
* @returns referenz auf stream mit angehaengtem ListenString
*/
ostream& operator<<(ostream& o, const ListElement& listElement){
	o << listElement.inhalt;
	return o;
}
/**
* @brief <<Operator zum auswerten eines isteams
* @param i Streamreferenz
* @param listElement Listenreferenz
* @returns referenz auf stream mit angehaengtem istream Element
*/
istream& operator>> (istream& i, ListElement& listElement){
	i >> listElement.inhalt;
	return i;
}
bool ListElement::operator==(ListElement& listElement){
	bool ergebnis = false;
	if(inhalt.compare(listElement.inhalt) == 0){
		ergebnis = true;
	}
	return ergebnis;
}
bool ListElement::operator!=(ListElement& listElement){
	bool ergebnis = false;
	if(inhalt.compare(listElement.inhalt) != 0){
		ergebnis = true;
	}
	return ergebnis;
}

