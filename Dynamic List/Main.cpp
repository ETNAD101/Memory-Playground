#include <iostream>
#include <PyList.h>



int main() {
	PyList<char> l;
	l.append('a');
	l.append('y');
	l.append('z');
	l.append('b');
	l.append('f');
	l.append('j');
	l.print();
	l.sort();
	l.print();
}