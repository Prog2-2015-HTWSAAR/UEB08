/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb07 *.o
* @file	ListElement.cpp
* @author Andreas Schreiner & Simon Bastian
* @detail Basierend auf Folz Klasse
* @date 14.06.2015
*/

#include "ListElement.h"


ListElement::ListElement(InhaltTyp inhalt, ListElement* previous,
		                                   ListElement* next) {
	this->inhalt = inhalt;
	this->previous = previous;
	this->next = next;
}

ListElement::~ListElement() {
	// TODO Auto-generated destructor stub
}

ostream& operator<<(ostream& o, const ListElement& ListElement){
	o << ListElement.inhalt;
	return o;
}
istream& operator>> (istream& i, ListElement& listElement){
	i >> listElement.inhalt;
	return i;
}

