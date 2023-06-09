#pragma once

#define LOG(x) std::cout << x << std::endl;

// Trying to make the same lists that python has
/*
Methods added:
	append
	clear
	count
	index
	insert
	pop
	reverse
	sort
	toArray
	overload[]
Methods to add:
	copy
	extend

*/

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

	// Removes element from the end of a list
	T pop() {
		T value = tail->value;
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
		return value;
	}

	// Removes an element at specified index
	void pop(int p_index) {
		Node* node = getNodeFromIndex(p_index);
		T value = node->value;
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
		return value;
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

	// Sorts the list using bubble sort
	void sort() {
		int i, j;
		for (i = 0; i < nodes; i++)
			for (j = 0; j < nodes - i - 1; j++)
				if (getNodeFromIndex(j)->value > getNodeFromIndex(j + 1)->value) {
					T temp = getNodeFromIndex(j)->value;
					replace(j, getNodeFromIndex(j + 1)->value);
					replace(j + 1, temp);
				}
	}

	// Reverses the list
	void reverse() {
		for (int i = 0; i < nodes / 2; i++) {
			T temp = getNodeFromIndex(i)->value;
			replace(i, getNodeFromIndex(nodes - 1 - i)->value);
			replace(nodes - 1 - i, temp);
		}
	}

	// Return array of current elements
	T* toArray() {
		T* arr = new T[nodes];
		for (int i = 0; i < nodes; i++) {
			arr[i] = getNodeFromIndex(i)->value;
		}
		return arr;
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

	// returns a reference to the value at the index
	T& operator[](int p_index) {
		T& ref = getNodeFromIndex(p_index)->value;
		return ref;
	}

	void operator=(PyList that) {
		clear();
		for (int i = 0; i < that.length(); i++) {
			this->append(that[i]);
		}
	}
};