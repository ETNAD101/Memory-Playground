#include <iostream>
#include <PyList.h>

PyList<std::string> l;

int main() {
	l.append("apple");
	l.append("orange");
	l.append("apple");
	l.append("orange");
	l.append("pear");
	l.append("orange");
	std::cout << l.count("apple") << ", " << l.count("orange") << ", " << l.count("pear");
	l.remove("pear");
	l.print();
	std::cout << l.count("pear") << ", " << l.length();
}