#include <iostream>
#include <PyList.h>



int main() {
	PyList<int> l;
	for (int i = 0; i < 11; i++) {
		l.append(i);
	}
	PyList<int> other;
	for (int i = 0; i < 5; i++) {
		other.append(i);
	}
	l = other;
	l.print();
	l.reverse();
	l.print();
}