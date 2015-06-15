/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb07 *.o
* @file	ListElement.cpp
* @author Andreas Schreiner & Simon Bastian
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
	// TODO Auto-generated destructor stub
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

