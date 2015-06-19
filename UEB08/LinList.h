/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file	LinList.h
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @details Basierend auf Folz Klasse
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
	* @brief insert Fuegt Element vor pos ein
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
	* @brief isEmpty Pruefung auf leer
	* @returns true == empty false == non empty
	*/
	bool isEmpty();
	/**
	 * @brief gibt den Inhalt der Liste als String zurueck
	 * @returns Stringrepresentation des LinList-Objekts
	 */
	string toString() const;
	/**
	 * @brief <<Operator zur Ausgabe in einen Stream
	 * @param o Streamreferenz
	 * @param linList Listenreferenz
	 * @returns Referenz auf Stream mit angehaengtem LinListString
	 */
	friend ostream& operator<< (ostream& o, const LinList& linList);
	/**
	 * @brief >>Operator zur Eingabe durch einen Stream
	 * @param i Streamreferenz
	 * @param linList Listenreferenz
	 * @returns Referenz auf Stream mit entnommenem LinListString
	 */
	friend istream& operator>> (istream& i, LinList& linList);
	/**
	 * @brief indexOperator zum Zugriff auf ein Element
	 *
	 */
	ListElement& operator[](int pos);
	/**
	 *
	 */
	LinList& operator+=(LinList& linList);
	/**
	 *
	 */
	bool operator==(LinList& linList);
	/**
	 *
	 */
	bool operator!=(LinList& linList);
	/**
	 *
	 */
	friend LinList& operator+(LinList& linList1, LinList& linList2);
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
	* @param linList Referenz auf LinListen Obj
	*/
	void copyElements(const LinList& linList);
	size_t size;
	ListElement* first;
	ListElement* last;
};

#endif /* LINLIST_H_ */
