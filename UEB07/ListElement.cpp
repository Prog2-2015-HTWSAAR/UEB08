/**
 * 
 * @file	ListElement.cpp
 * @author	folz
 * @date	20.05.2012
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

