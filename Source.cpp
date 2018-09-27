#include"Header.h"

LINKED_LIST::LINKED_LIST() {
	try {
		list = new LIST;
		if (!list)
			throw "Bad Allocation";
		list->count = 0;
		list->head = nullptr;
		list->prev = nullptr;
		list->rear = nullptr;
	}
	catch (const char* msg) {
		cout << msg;
	}
}
bool LINKED_LIST::emptyList()const {
	return(list->head == nullptr);
}
NODE* LINKED_LIST::LINKED_LIST::createNode(int data) {
	try {
		NODE* newNode = new node;
		if (!newNode) {
			throw "Bad Allocation";
		}
		else {
			newNode->data = data;
			newNode->link = nullptr;
		}
		return newNode;
	}
	catch (const char* msg) {
		cout << msg;
	}
}

void LINKED_LIST::insertNode(int data) {
	NODE* newNode = createNode(data);
	if (emptyList())
		_insertHead(newNode);
	else {
		_insert(newNode);
	}
	list->count++;
}

bool LINKED_LIST::_insertHead(NODE* newHead) {
	list->head = newHead;
	list->rear = newHead;
	return true;
}
bool LINKED_LIST::_insert(NODE* newNode) {

	if (newNode->data <= list->head->data) {
		newNode->link = list->head;
		list->head = newNode;
	}
	else {
		NODE* ptr = list->head;
		while (ptr->link != nullptr && ptr->data <= newNode->data) {
			list->prev = ptr;
			ptr = ptr->link;
		}
		if (ptr->link == nullptr || ptr->data >= newNode->data) {
			if (ptr->data >= newNode->data) {
				list->prev->link = newNode;
				list->prev = newNode;
				newNode->link = ptr;
				list->rear = ptr;
			}
			else {
				ptr->link = newNode;
				list->rear = newNode;
			}
		}
	}
	return true;
}
void LINKED_LIST::printList()const {
	NODE* ptr = list->head;
	while (ptr) {
		cout << ptr->data << " ";
		ptr = ptr->link;
	}
}
void LINKED_LIST::deleteNode(int dataOut) {
	bool flag = false;
	if (!emptyList()) {
		if (_deleteHead(dataOut) == false) {
			_delete(dataOut);
		}
	}
}
bool LINKED_LIST::_deleteHead(int dataOut) {
	bool flag = false;
	if (list->head->data == dataOut) {
		NODE* temp = list->head;
		list->head = list->head->link;
		delete(temp);
		flag = true;
	}
	list->count--;
	return flag;
}
bool LINKED_LIST::_delete(int dataOut) {
	NODE* ptr = list->head,*temp;
	while (ptr->data != dataOut && ptr->link != nullptr) {
		list->prev = ptr;
		ptr = ptr->link;
	}
	if(ptr == nullptr || ptr->data != dataOut){
		temp = ptr;
		list->prev->link = ptr->link;
		delete(temp);
	}
	return true;
}
