#include <iostream>
#include <DynamicList.h>


int main() {
	DynamicList<std::string> l;
	l.append("Hello");
	l.append("World");
	l.print();
	l.pop();
	l.append("Dante");
	l.print();
	l.clear();
	l.print();
	return 0;
}