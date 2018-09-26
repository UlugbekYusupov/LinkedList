#pragma once
#include<iostream>
#include<conio.h>
#include<exception>

using namespace std;

typedef struct node {
	int data;
	struct node* link;
}NODE;

typedef struct {
	int count;
	NODE* head;
	NODE* rear;
	NODE* prev;
}LIST;

class LINKED_LIST
{
private:
	LIST* list;
	bool _insert(NODE*);
	bool _delete(int);
	bool emptyList()const;
	NODE* createNode(int);
	bool _insertHead(NODE*);
	bool _deleteHead(int);
public:

	LINKED_LIST();
	//~LINKED_LIST();
	void insertNode(int);
	void deleteNode(int);
	void printList()const;
};