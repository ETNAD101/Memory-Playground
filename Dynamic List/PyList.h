#pragma once

// Trying to make the same lists that python has

#define LOG(x) std::cout << x << std::endl;

template <class T>
class PyList {
private:
	struct Node {
		int pos;
		Node* prev;
		Node* next;
		T data;
	};

private:
	int nodes;
	Node* head;
	Node* tail;

public:
	PyList() {
		nodes = 0;
		head = nullptr;
		tail = nullptr;
	}

	~PyList() {
		clear();
	}

	void append(T p_data) {
		Node* node = new Node{ nodes, tail, nullptr, p_data };

		if (nodes == 0) {
			head = node;
		}
		else {
			tail->next = node;
		}

		tail = node;
		nodes++;
	}

	void insert(int p_pos, T p_data) {
		Node* node = head;
		while (node->pos != p_pos) {
			node = node->next;
		}
		Node* newNode = new Node{ p_pos, node->prev, node, p_data };
		
		Node* prevNode = node->prev;
		node->prev = newNode;
		prevNode->next = newNode;

		while (node != nullptr) {
			node->pos += 1;
			node = node->next;
		}
		nodes++;
	}

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

	void pop(int p_pos) {
		Node* node = head;
		while (node->pos != p_pos) {
			node = node->next;
		}

		Node* prevNode = node->prev;
		Node* nextNode = node->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		node = nextNode;

		while (node != nullptr) {
			node->pos -= 1;
			node = node->next;
		}
		nodes--;
	}

	int length() {
		return nodes;
	}

	int index(T p_data) {
		Node* node = head;
		while (node->data != p_data) {
			node = node->next;
			if (node == nullptr) {
				return -1;
			}
		}
		return node->pos;
	}

	void clear() {
		while (nodes > 0) {
			pop();
		}
	}

	void print() {
		Node* n = head;
		if (n == nullptr) {
			std::cout << "empty" << std::endl;
			return;
		}
		while (true) {
			std::cout << "{" << n->data << "}";
			if (n->next != nullptr) {
				n = n->next;
			}
			else {
				std::cout << std::endl;
				break;
			}
		}
	}

	T operator[](int index) {
		if (index < 0 || index > nodes)
			return NULL;
		Node* node = head;
		while (node->pos != index) {
			node = node->next;
			if (node == nullptr) {
				return -1;
			}
		}
		return node->data;
	}
};