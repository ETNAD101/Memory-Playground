#pragma once

// Trying to make the same lists that python has

#define LOG(x) std::cout << x << std::endl;

template <class T>
class PyList {
private:
	struct Node {
		int index;
		Node* prev;
		Node* next;
		T value;
	};

private:
	int nodes;
	Node* head;
	Node* tail;

private:
	Node* getNodeFromIndex(int p_index) {
		Node* node = head;
		while (node->index != p_index) {
			node = node->next;
			if (node == nullptr) {
				return nullptr;
			}
		}
		return node;
	}

	Node* getNodeFromValue(int p_value) {
		Node* node = head;
		while (node->value != p_value) {
			node = node->next;
			if (node == nullptr) {
				return nullptr;
			}
		}
		return node;
	}

public:
	PyList() {
		nodes = 0;
		head = nullptr;
		tail = nullptr;
	}

	~PyList() {
		clear();
	}

	// Adds an element to the end of the list
	void append(T p_value) {
		Node* node = new Node{ nodes, tail, nullptr, p_value };

		if (nodes == 0) {
			head = node;
		}
		else {
			tail->next = node;
		}

		tail = node;
		nodes++;
	}

	// Inserts a new element at the specified index
	void insert(int p_index, T p_value) {
		Node* node = getNodeFromIndex(p_index);
		Node* newNode = new Node{ p_index, node->prev, node, p_value };
		
		Node* prevNode = node->prev;
		node->prev = newNode;
		prevNode->next = newNode;

		while (node != nullptr) {
			node->index += 1;
			node = node->next;
		}
		nodes++;
	}

	void replace(int p_index, T p_value) {

	}

	// Removes element from the end of a list
	void pop() {
		if (tail->prev == nullptr) {
			head = nullptr;
			delete tail;
			tail = nullptr;
		}
		else {
			Node* tmp = tail->prev;
			tmp->next = nullptr;
			delete tail;
			tail = tmp;
		}
		nodes--;
	}

	// Removes an element at specified index
	void pop(int p_index) {
		Node* node = getNodeFromIndex(p_index);

		Node* prevNode = node->prev;
		Node* nextNode = node->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		node = nextNode;

		while (node != nullptr) {
			node->index -= 1;
			node = node->next;
		}
		nodes--;
	}

	// Removes the first element with the specified value
	void remove(T p_value) {
		Node* node = getNodeFromValue;
		if (node == nullptr) return;

		Node* prevNode = node->prev;
		Node* nextNode = node->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		node = nextNode;

		while (node != nullptr) {
			node->index -= 1;
			node = node->next;
		}
		nodes--;
	}

	// Removes every element in the list
	void clear() {
		while (nodes > 0) {
			pop();
		}
	}

	// Returns the number of elements in the list
	int length() {
		return nodes;
	}

	// Returns the number of elements with the specified value
	int count(T p_value) {
		Node* node = head;
		int count = 0;
		
		while (node != nullptr) {
			if (node->value == p_value) {
				count++;
			}
			node = node->next;
		}

		return count;
	}

	// Returns the index of the first element with the given value
	int index(T p_value) {
		Node* node = getNodeFromValue(p_value);
		return node == nullptr ? -1 : node->index;
	}

	// Prints every element in the list to the console
	void print() {
		Node* n = head;
		if (n == nullptr) {
			std::cout << "empty" << std::endl;
			return;
		}
		while (true) {
			std::cout << "{" << n->value << "}";
			if (n->next != nullptr) {
				n = n->next;
			}
			else {
				std::cout << std::endl;
				break;
			}
		}
	}

	// returns the value at the specified index
	T operator[](int p_index) {
		if (p_index < 0 || p_index > nodes)
			return NULL;
		Node* node = getNodeFromIndex(p_index);
		return node == nullptr ? -1 : node->value;
	}
};