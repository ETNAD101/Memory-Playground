#include <iostream>
#include <PyList.h>

PyList<int> l;

void populate(int p_size) {
	for (int i = 0; i < p_size; i++) {
		l.append(i);
	}
}


int main() {
	for (int i = 0; i < 15; i++) {
		l.append(i + 5);
	}
	for (int i = 0; i < l.length(); i++) {
		std::cout << "l[" << i << "] = " << l[i] << std::endl;
	}
}