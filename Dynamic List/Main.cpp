#include <iostream>
#include <PyList.h>



int main() {
	PyList<int> l;
	for (int i = 0; i < 10; i++) {
		l.append(i);
	}
	l.print();
	l.reverse();
	l.print();
}