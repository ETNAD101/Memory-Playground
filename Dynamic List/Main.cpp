#include <iostream>
#include <DynamicList.h>

DynamicList<int> l;

void populate(int p_size) {
	for (int i = 0; i < p_size; i++) {
		l.append(i);
	}
}


int main() {
	l.append(0);
	l.append(1);
	l.append(2);
	l.append(3);
	l.insert(500, 2);
	l.print();
}