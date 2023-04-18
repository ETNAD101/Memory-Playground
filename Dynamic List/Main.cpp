#include <iostream>
#include <DynamicList.h>

DynamicList<std::string> l;

void populate(int p_size) {
	for (int i = 0; i < p_size; i++) {
		l.append("JKHGFDSFGJDFSLKGJDFGLSDFJGSDLGJNBSIDBJSDLBKJ");
	}
}


int main() {
	std::cin.get();
	for (int a = 0; a < 10; a++) {
		populate(10000);
		std::cin.get();
		l.clear();
		std::cin.get();
	}
}