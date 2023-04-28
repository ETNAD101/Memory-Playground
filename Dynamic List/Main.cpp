#include <iostream>
#include <PyList.h>



int main() {
	PyList<int> l;
	l.append(10);
	l.append(20);
	l.append(30);
	l.append(40);
	std::cout << l[2];
}