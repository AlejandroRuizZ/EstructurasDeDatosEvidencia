// =================================================================
//
// File: list.h
// Author:
// Date:
//
// =================================================================
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <string>
#include <sstream>
#include "exception.h"
#include "header.h"
#include <string.h>


template <class T> class DoubleLinkedList;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    	value;
	Node<T> *previous, *next;

	friend class DoubleLinkedList<T>;
};

// =================================================================
// Constructor. Initializes the value of the node. The variable next
// is initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val) : value(val), previous(NULL), next(NULL) {
}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored value in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {
}

// =================================================================
// Definition of the DoubleLinkedList class
// =================================================================
template <class T>
class DoubleLinkedList {
private:
	Node<T> *head;
	uint 		size;

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	uint  length() const;
	bool empty() const;
	bool contains(T) const;
	void clear();
	std::string toString() const;

	T front() const;
	T last() const;
	T before(T) const;
	T after(T) const;

	void push_front(T);
	void push_back(T);
	void insert_before(T, T);
	void insert_after(T, T);

	T    pop_front();
	T 	 pop_back();
	T    getFinalResult(string port);
};

// =================================================================
// Constructor. Initializes both instance variables to zero.
// =================================================================
template <class T>
DoubleLinkedList<T>::DoubleLinkedList() :head(NULL), size(0) {
}

// =================================================================
// Destructor. Remove all items from the DoubleLinkedList.
// =================================================================
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	clear();
}

// =================================================================
// Returns if the DoubleLinkedList is empty or not
//
// @returns true if the DoubleLinkedList is empty, false otherwise.
// =================================================================
template <class T>
bool DoubleLinkedList<T>::empty() const {
	return (head == NULL);
}

// =================================================================
// Returns the number of items in the DoubleLinkedList.
//
// @returns size, the number of items in the DoubleLinkedList.
// =================================================================
template <class T>
uint DoubleLinkedList<T>::length() const {
	return size;
}

// =================================================================
// Determines if an item is in the DoubleLinkedList.
//
// @returns true if val is in the DoubleLinkedList, false otherwise
// =================================================================
template <class T>
bool DoubleLinkedList<T>::contains(T val) const {
	Node<T> *p;

	p = head;
	while (p != NULL) {
		if(p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

// =================================================================
// Remove all items from the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != NULL){
		q = p->next;
		delete p;
		p = q;
	}

	head = NULL;
	size = 0;
}

// =================================================================
// String representation of the elements in the DoubleLinkedList.
//
// @returns a string containing all the elements of the DoubleLinkedList.
// =================================================================
template <class T>
std::string DoubleLinkedList<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "[";
	while (p != NULL) {
		aux << p->value;
		if (p->next != NULL) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Returns the first item in the DoubleLinkedList.
//
// @returns the object T at the beginning of the DoubleLinkedList.
// @throws NoSuchElement, if the DoubleLinkedList is empty.
// =================================================================
template <class T>
T DoubleLinkedList<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}

	return head->value;
}

// =================================================================
// Returns the last item in the DoubleLinkedList.
//
// @returns the object T at the end of the DoubleLinkedList.
// @throws NoSuchElement, if the DoubleLinkedList is empty.
// =================================================================
template <class T>
T DoubleLinkedList<T>::last() const {
	Node<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	return p->value;
}

// =================================================================
// Returns the value before the first occurrence if certain value.
//
// @throws NoSuchelement, if val is not on the list.
// =================================================================
template <class T>
T DoubleLinkedList<T>::before(T val) const {
	Node<T> *p;
	if (empty()) {
		throw NoSuchElement();
	}

	if(contains(val)){
		p = head;
		while (p != NULL) {
			if(p->value == val) {
				break;
			}
			p = p->next;
		}
		if(p->previous==NULL){
			throw NoSuchElement();
		}
		p= p->previous;
		return p->value;
	}
	else{
		throw NoSuchElement();
	}
}



// =================================================================
// Returns the value after the first occurrence of certain value.
//
// @throws NoSuchelement, if val is not on the list.
// =================================================================
template <class T>
T DoubleLinkedList<T>::after(T val) const {
	Node<T> *p;
	if (empty()) {
		throw NoSuchElement();
	}

	if(contains(val)){
		p = head;
		while (p != NULL) {
			if(p->value == val) {
				break;
			}
			p = p->next;
		}
		if(p->next==NULL){
			throw NoSuchElement();
		}
		p= p->next;
		return p->value;
	}
	else{
		throw NoSuchElement();
	}
}


// =================================================================
// Add an item to the beginning of the DoubleLinkedList. Increase the size of
// the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::push_front(T val) {
	Node<T> *q, *p;

	q = new Node<T>(val);
	if (head == NULL) {
		q->next = NULL;
		q->previous = NULL;
	} else {
		p = head;

		q->next = p; // q->next = head;
		q->previous = NULL;

		p->previous = q; //head->previous = q;
	}
	head = q;
	size++;
}

// =================================================================
// Add an item to the end of the DoubleLinkedList. Increase the size of
// the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::push_back(T val) {
	Node<T> *p, *q;

	if (empty()) {
		push_front(val);
		return;
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}

	q = new Node<T>(val);
	q->next = p->next;
	q->previous = p;

	p->next = q;
	size++;
}

// =================================================================
// Insert an element before the first occurrence of a certain value.
//
// @throws NoSuchelement, if lookingFor is not on the list.
// =================================================================
template <class T>
void DoubleLinkedList<T>::insert_before(T lookingFor, T newVal) {
		Node<T> *p, *q, *nuevo;
	if (empty()) {
		push_front(newVal);
	}
	if(contains(lookingFor)){
		p = head;

		while (p != NULL) {
			if(p->value == lookingFor) {
				break;
			}
			q = p;
			p = p->next;
		}
		if(p->previous == NULL){
			push_front(newVal);
			size --;
		}
		nuevo = new Node<T>(newVal);
		q -> next = nuevo;
		nuevo -> next = p;
		nuevo ->previous = q;
		p -> previous = nuevo;
		size++;
	}
	else{
		throw NoSuchElement();
	}
}


// =================================================================
// Insert an element after the first occurrence of a certain value.
//
// @throws NoSuchelement, if lookingFor is not on the list.
// =================================================================
template <class T>
void DoubleLinkedList<T>::insert_after(T lookingFor, T newVal) {
	Node<T> *p, *q,*nuevo;
if (empty()) {
	push_front(newVal);
}
if(contains(lookingFor)){
	p = head;

	while (p != NULL) {
		if(p->value == lookingFor) {
			break;
		}
		p = p->next;
	}

	nuevo = new Node<T>(newVal);
	nuevo ->next = p -> next;
	nuevo -> previous = p;
	p ->next =nuevo;



	size++;
}
else{
	throw NoSuchElement();
}
}


// =================================================================
// Delete the item at the beginning of the DoubleLinkedList.
//
// @returns the element that was at the beginning of the DoubleLinkedList.
// @throws NoSuchElement if the DoubleLinkedList is empty
// =================================================================
template <class T>
T DoubleLinkedList<T>::pop_front() {
	T val;
	Node<T> *p, *q;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;

	if (size == 1) {
		head = p->next;
	} else {
		q = p->next;

		q->previous = NULL;
		head = q;
	}

	val = p->value;

	delete p;
	size--;

	return val;
}

// =================================================================
// Delete the item at the end of the DoubleLinkedList.
//
// @returns the element that was at the end of the DoubleLinkedList.
// @throws NoSuchElement if the DoubleLinkedList is empty
// =================================================================
template <class T>
T DoubleLinkedList<T>::pop_back() {
	Node<T> *p, *q;
	T val;

	if (empty()) {
		throw NoSuchElement();
	}

	if (size == 1) {
		return pop_front();
	}

	p = head;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	q = p->previous;

	q->next = p->next;

	val = p->value;
	delete p;
	size--;

	return val;
}

template <class T>
T DoubleLinkedList<T>::getFinalResult(string port) {
	Node<T> *p, *q;
	p = head;
	int month;
	int monthArray[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	string UBIStringArray[12] = {" "," "," "," "," "," "," "," "," "," "," "," "};
	string myUBIS = "";
	string myUBIS2 = "";
	while (p != NULL) {
		q = p;
		month = p->value.getMonth();
		switch (month) {
			case 1 : //january
					monthArray[0] += 1;
					myUBIS = UBIStringArray[0];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[0] = "";
					UBIStringArray[0] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 2 : //feb
					monthArray[1] += 1;
					myUBIS = UBIStringArray[1];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[1] = "";
					UBIStringArray[1] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 3 : //mar
					monthArray[2] += 1;
					myUBIS = UBIStringArray[2];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[2] = "";
					UBIStringArray[2] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 4 : //abr
					monthArray[3] += 1;
					myUBIS = UBIStringArray[3];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[3] = "";
					UBIStringArray[3] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 5 : //may
					monthArray[4] += 1;
					myUBIS = UBIStringArray[4];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[4] = "";
					UBIStringArray[4] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 6 : //jun
					monthArray[5] += 1;
					myUBIS = UBIStringArray[5];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[5] = "";
					UBIStringArray[5] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 7 : //jul
					monthArray[6] += 1;
					myUBIS = UBIStringArray[6];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[6] = "";
					UBIStringArray[6] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 8 : //aug
					monthArray[7] += 1;
					myUBIS = UBIStringArray[7];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[7] = "";
					UBIStringArray[7] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 9 : //sept
					monthArray[8] += 1;
					myUBIS = UBIStringArray[8];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[8] = "";
					UBIStringArray[8] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 10: //oct
					monthArray[9] += 1;
					myUBIS = UBIStringArray[9];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[9] = "";
					UBIStringArray[9] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 11 : //nov
					monthArray[10] += 1;
					myUBIS = UBIStringArray[10];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[10] = "";
					UBIStringArray[10] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
			case 12 : //dec
					monthArray[11] += 1;
					myUBIS = UBIStringArray[11];
					myUBIS2 = p->value.getUbi() + " ";
					UBIStringArray[11] = "";
					UBIStringArray[11] = myUBIS + myUBIS2;
					myUBIS = "";
					myUBIS2 = "";
					break;
		}
		p = p->next;
	}
	for(int i =0; i < 12; i++){
		if(monthArray[i] != 0){
			string cadena = "";
			char cadena2[5];
			switch(i){
				case 0:
					cout << "jan" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[0];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[0]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 1:
					cout << "feb" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[1];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[1]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 2:
					cout << "mar" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[2];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[2]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 3:
					cout << "apr" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[3];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[3]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 4:
					cout << "may" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[4];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[4]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 5:
					cout << "jun" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[5];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[5]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 6:
					cout << "jul" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[6];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[6]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 7:
					cout << "aug" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[7];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[7]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 8:
					cout << "sep" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[8];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[8]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 9:
					cout << "oct" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[9];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[9]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 10:
					cout << "nov" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[10];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[10]) + ": " + cadena2 << endl;
					cadena = "";
					break;
				case 11:
					cout << "dec" << endl;
					//port = p->value.getPort();
					cadena = UBIStringArray[11];
					cadena2[0] = cadena[1];
					cadena2[1] = cadena[2];
					cadena2[2] = cadena[3];
					cadena2[3] = cadena[4];
					cadena2[4] = cadena[5];
					cout << port + " " + to_string(monthArray[11]) + ": " + cadena2 << endl;
					cadena = "";
					break;
			}
		}
	}
}

#endif /* DoubleLinkedList_H */
