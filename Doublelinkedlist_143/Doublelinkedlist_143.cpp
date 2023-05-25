#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class DoubleLinkedList {
private:
	node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, node** previous, node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void vertraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}
void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter thr roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	node* newNode = new node(); // step 1
	newNode->noMhs = nim; //step 2
	newNode->name = nm;   //step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode;  //step 4
		newNode->prev = NULL; //step 5
		START = newNode;   //step 6
		return;
	}

	/*Inserting a node Between Two Nodes in the list*/
	node* current = START;  //step 1.a
	node* previous = NULL;  //step 1.b
	while (current->next != NULL && current->next->noMhs < nim)  //step 1.c
	{
		previous = current;   //step 1.d
		current = current->next;   //step 1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;  //step 4
	newNode->prev = current;   //step 5
	if (current->next != NULL)
		current->next->prev = newNode;   //step 6
	current->next = newNode;   //step 7
}

bool DoubleLinkedList::search(int rollNo, node** previous, node** current) {
	*previous = START;  //step 1.a
	*current = START;   //step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {  //step 1.c
		*previous = *current;  //step 1.d
		*current = (*current)->next;  //step 1.e
	}
	return (*current != NULL);
}
bool DoubleLinkedList::deleteNode(int rollNo) {
	node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;   //step 2
	if (previous != NULL)
		previous->next = current->next;  //step 3
	else
		START = current->next;

	delete current;   //step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is empty " << endl;
	else {
		cout << "\nRecords in asceding order of roll number are:" << endl;
		node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

