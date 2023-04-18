#pragma once

// Trying to make the same lists that python has

template <class T>
class DynamicList {
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
	Node* prevNode;
	Node* tail;

public:
	DynamicList() {
		nodes = 0;
		head = nullptr;
		prevNode = nullptr;
		tail = nullptr;
	}
	~DynamicList() {
		clear();
	}

	void append(T p_data) {
		Node* node = new Node{ nodes, nullptr, nullptr, p_data };

		if (nodes == 0) {
			head = node;
		}
		else {
			node->prev = tail;
			tail->next = node;
		}

		tail = node;
		nodes++;
	}

	void insert(T p_data, int p_pos) {

	}

	void pop() {
		prevNode = tail->prev;
		delete tail;

		if (prevNode == nullptr) {
			head = nullptr;
			prevNode = nullptr;
		}
		else {
			tail = prevNode;
			tail->next = nullptr;
		}
		nodes--;
	}

	void pop(int p_pop) {

	}

	int length() {
		return nodes;
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
};