/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb07 *.o
* @file	ListElement.h
* @author Andreas Schreiner & Simon Bastian
* @detail Basierend auf Folz Klasse
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
/**
 * Listenelement fuer eine doppelt-verkettete Lineare Liste
 * 
 * @author	folz
 * @version 
 * @date	20.05.2012
 */
class ListElement {
public:
	ListElement(InhaltTyp, ListElement* =0, ListElement* =0);
	~ListElement();
	friend class LinList;
	friend ostream& operator<< (ostream& o, const ListElement& listElement);
	friend istream& operator>> (istream& i, ListElement& listElement);
private:
	InhaltTyp inhalt;
	ListElement* previous;
	ListElement* next;
};

#endif /* LISTELEMENT_H_ */
