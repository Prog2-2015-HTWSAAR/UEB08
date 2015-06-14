/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb07 *.o
* @file	LinList.cpp
* @author Andreas Schreiner & Simon Bastian
* @detail Basierend auf Folz Klasse
* @date 14.06.2015
*/

#include "LinList.h"
#include <sstream>
#include <iostream>
const char* LinList::MELDUNG_LISTE_LEER = "Liste ist leer!";
const char* LinList::MELDUNG_FALSCHE_POS  = "Ungueltige Position!";
const char* LinList::ADD_SPACE = " ";
const char* LinList::CHAINED_LIST = "Verkettete Liste: ";
const char* LinList::ELEMENTS = " Elemente\n";
const char* NIL_PHRASE = "NIL";
const char* EMPTY_CHAR_ARRAY = "";

LinList::LinList() {
	this->first = 0;
	this->last = 0;
	this->size = 0;
}

LinList::LinList(const LinList& linlist){
	copyElements(linlist);
}
LinList::~LinList() {
	clear();
}

LinList& LinList::operator=(const LinList& linlist){
	//Zuweisung auf mich selbst?
	if(this == &linlist){
		return *this;
	}

	// bisherige ListElement-Objekte destruieren
	clear();
	//Listenelemente kopieren
	copyElements(linlist);
	return *this;
}
void LinList::push_back(InhaltTyp t) {
	ListElement* tmp = new ListElement(t);
	if(isEmpty()){
		first = tmp;
	}else{
		last->next = tmp;
		tmp->previous = last;
	}
	last = tmp;
	size++;
}

void LinList::push_front(InhaltTyp t) {
	ListElement* tmp = new ListElement(t);
	if(isEmpty()){
		last = tmp;
	}else{
		first->previous = tmp;
		tmp->next = first;
	}
	first = tmp;
	size++;
}

void LinList::pop_back() {
	if(isEmpty()){
		throw LinListException(MELDUNG_LISTE_LEER);
	}
	ListElement* tmp = last->previous;
	delete last;
	size--;
	last = tmp;
	if (last != NULL){
		last->next = NULL;
	}
	if(isEmpty()){
		first = NULL;
	}
}

void LinList::pop_front() {
	if(isEmpty()){
		throw LinListException(MELDUNG_LISTE_LEER);
	}
	ListElement* tmp = first->next;
	delete first;
	size--;
	first = tmp;
	if(first){
		first->previous = NULL;
	}
	if(isEmpty()){
		last = NULL;
	}
}

void LinList::insert(int pos, InhaltTyp t){
	int suchIndex = 2; //Start bei zwei wegen Vorgaengersuche
	ListElement* tmp1 = first;
	ListElement* tmp2 = NULL;
	ListElement* tmp3 = NULL;
	//TODO Trotzdem Anfang/Ende anhaengen?
	if ((unsigned int)pos < 1 || (unsigned int)pos > size){
		throw LinListException(MELDUNG_FALSCHE_POS);
	}

	//Anfang
	if(pos == 1){
		push_front(t);
	}else{
		//Mitte
		//Finde Vorgaenger falls noetig
		while(suchIndex < pos){
			suchIndex++;
			tmp1 = tmp1->next;
		}
		tmp2 = tmp1->next; //Nachfolger merken
		tmp3 = new ListElement(t); // neues Element
		// links zu neuem Element
		tmp1->next = tmp3;
		tmp2->previous = tmp3;
		// links ausgehend von neuem Element
		tmp3->previous = tmp1;
		tmp3->next = tmp2;

	}

}

void LinList::erase(int pos){
	int suchIndex = 1;
	ListElement* tmp = first;
	if ((unsigned int)pos < 1 || (unsigned int)pos > size){
		throw LinListException(MELDUNG_FALSCHE_POS);
	}
	//Anfang
	if(pos == 1){
		pop_front();
	}else{
		//Ende
		if(pos == size){
			pop_back();
		}else{
			//Mitte
			//Finde Element
			while(suchIndex < pos){
				suchIndex++;
				tmp = tmp->next;
			}
			//Vorgaenger und Nachfolger verbinden
			tmp->previous->next = tmp->next;
			tmp->next->previous = tmp->previous;
			//Element loeschen
			delete tmp;
		}
	}

}
void LinList::clear(){
	while(!isEmpty()){
		pop_back();
	}
}

bool LinList::isEmpty(){
	return (size == 0);
}

string LinList::toString() const {
	ostringstream o;
	o << CHAINED_LIST << size << ELEMENTS;
	ListElement* tmp = first;

	while (tmp){
		o << *tmp << ADD_SPACE;
		tmp = tmp->next;
	}
	o << endl;
	return o.str();
}

ostream& operator<<(ostream& o, const LinList& linList){
	return o << linList.toString();
}

istream& operator>> (istream& i, LinList& linList){
	//ListElement tmp = new ListElement("tmp");
	InhaltTyp t = EMPTY_CHAR_ARRAY;
	while (i >> t && t != NIL_PHRASE){
		linList.push_back(t);
	}
	return i;
}

void LinList::copyElements(const LinList& linlist){
	ListElement* tmp = linlist.first;
	while(tmp != NULL){
		push_back(tmp->inhalt);
		tmp = tmp->next;
	}
}
