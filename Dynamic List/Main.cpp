#include <iostream>
#include <PyList.h>



int main() {
	PyList<int> l;
	for (int i = 0; i < 22; i += 2) {
		l.append(i);
	}
	std::cout << l[5] << std::endl;
	l[0] = 4;
	l.print();
}