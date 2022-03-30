//
//
//
//

#include <iostream>
#include "NumberList.h"
using namespace std;


int main() {

	NumberList list;
	int ordinalPostion = 0;

	list.appendNode(3.1);
	list.appendNode(7.2);
	list.appendNode(4.0);
	list.appendNode(2.3);
	list.appendNode(3.5);

	list.search(2.3);
	list.search(1.0);
	list.search(8.0);
	list.search(2.3, ordinalPostion);
	list.search(1.0, ordinalPostion);
	list.search(8.0, ordinalPostion);



	list.deleteNode(3.2);
	

	system("pause");
	return 0;
}