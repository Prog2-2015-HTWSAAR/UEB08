/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb07 *.o
* @file	LinList.h
* @author Andreas Schreiner & Simon Bastian
* @detail Basierend auf Folz Klasse
* @date 14.06.2015
*/
#ifndef LINLIST_H_
#define LINLIST_H_
#include "ListElement.h"

class LinListException : public ElementException {
public:
    LinListException(const string& msg = "") : ElementException(msg) {}
};
/**
 * Doppelt-verkettete Lineare Liste
 * 
 * @author	folz
 * @version 
 * @date	20.05.2012
 */
class LinList {
public:
	/**
	* @brief Konstruktor
	*/
	LinList();
	/**
	 * Kopierkonstruktor
	 * @param linlist Referenz auf zu kopierendes Objekt
	 */
	LinList(const LinList&);
	/**
	* @brief Dekonstruktor
	*/
	~LinList();
	LinList& operator=(const LinList& linList);
	/**
	* @brief push_back Haengt Element hinten an die Liste an
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	void push_back (InhaltTyp t);
	/**
	* @brief push_front Haengt Element vorne an die Liste an
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	void push_front(InhaltTyp t);
	/**
	* @brief pop_back Entfernt letztes Element in der Liste
	*/
	void pop_back();
	/**
	* @brief pop_front Entfernt erstes Element in der Liste
	*/
	void pop_front();
	/**
	* @brief insert F�gt Element vor pos ein
	* @param pos Position des Obj, welches der neue Nachfolger werden soll
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	void insert(int pos, InhaltTyp t);
	/**
	* @brief erase Entfernt Element auf pos
	* @param pos Position des zu loeschenden Obj
	*/
	void erase(int pos);
	/**
	* @brief clear Entfernt alle Elemente der Liste
	*/
	void clear();
	/**
	* @brief isEmpty Pr�fung auf leer
	* @returns true == empty false == non empty
	*/
	bool isEmpty();
	string toString() const;
	friend ostream& operator<< (ostream& o, const LinList& linList);
	friend istream& operator>> (istream& i, LinList& linList);
	static const char* MELDUNG_LISTE_LEER;
	static const char* MELDUNG_FALSCHE_POS;
	static const char* ADD_SPACE;
	static const char* CHAINED_LIST;
	static const char* ELEMENTS;
	static const char* NIL_PHRASE;
	static const char* EMPTY_CHAR_ARRAY;

private:
	/**
	* @brief copyElements Kopierfunktion
	* @params linlist Referenz auf LinListen Obj
	*/
	void copyElements(const LinList& linlist);
	size_t size;
	ListElement* first;
	ListElement* last;
};

#endif /* LINLIST_H_ */
