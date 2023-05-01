#include <iostream>
#include <PyList.h>



int main() {
	PyList<int> l;
	for (int i = 0; i < 11; i++) {
		l.append(i);
	}
	l.print();
	l.reverse();
	l.print();
	int* arr = l.toArray();
	for (int i = 0; i < 11; i++) {
		std::cout << arr[i] << ", ";
	}
	delete[] arr;
}