/**
 * 
 * @file	LinList.h
 * @author	folz
 * @date	20.05.2012
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
	LinList();
	/**
	 * Kopierkonstruktor
	 * @param linlist Referenz auf zu kopierendes Objekt
	 */
	LinList(const LinList&);
	~LinList();
	LinList& operator=(const LinList&);
	void push_back (InhaltTyp t);
	void push_front(InhaltTyp t);
	void pop_back();
	void pop_front();
	void insert(int pos, InhaltTyp t);
	void erase(int pos);
	void clear();
	bool isEmpty();
	string toString() const;
	friend ostream& operator<< (ostream& o, const LinList& linList);
	friend istream& operator>> (istream& i, LinList& linList);
	static const char* meldungListeLeer;
	static const char* meldungFalschePos;
private:
	void copyElements(const LinList& linlist);
	size_t size;
	ListElement* first;
	ListElement* last;
};

#endif /* LINLIST_H_ */
