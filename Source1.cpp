#include"Header.h"

int main() {

	LINKED_LIST list;
	bool flag = true;
	while (flag) {
		char a;
		cin >> a;
		switch (a)
		{
		case 'i':
			int value;
			cin >> value;
			list.insertNode(value);
			break;
		case 'p':
			list.printList();
			break;
		case 'd':
			int dataOut;
			cin >> dataOut;
			list.deleteNode(dataOut);
			break;
		case 'e':
			flag = false;
			exit(0);
			break;
		}
	}
	_getch();
	return 0;
}