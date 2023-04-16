#include <iostream>

template <class T>
class List {

	struct Node {
		int pos;
		Node* prev;
		Node* next;
		T data;
	};

private:
	int nodes;
	Node* firstNode;
	Node* currentNode;

public:
	List() {
		nodes = 0;
		firstNode = nullptr;
		currentNode = nullptr;
	}

	void add(T p_data) {
		Node* node = new Node{ nodes, nullptr, nullptr, p_data };

		if (nodes == 0) {
			firstNode = node;
		}
		else {
			node->prev = currentNode;
			currentNode->next = node;
		}

		currentNode = node;
		nodes++;
	}

	void remove() {

	}

	void print() {
		Node* n = firstNode;
		if (n == nullptr) {
			std::cout << "empty" << std::endl;
			return;
		}
		while (n->next != nullptr) {
			std::cout << '{' << n->data << '}, ';
			n = n->next;
		}
	}
};

int main() {
	List<std::string> list = List<std::string>();
	list.add("Hello World");
	list.add("Goodbye World");
	list.print();
	return 0;
}