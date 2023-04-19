#pragma once

// Trying to make the same lists that python has

#define LOG(x) std::cout << x << std::endl;

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
	Node* tail;

public:
	DynamicList() {
		nodes = 0;
		head = nullptr;
		tail = nullptr;
	}

	~DynamicList() {
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

	void insert(T p_data, int p_pos) {
		//float middle = nodes / 2;
		if (p_pos > 1) {
			Node* node = tail;
			while (node->pos != p_pos) {
				node = node->prev;
			}
			Node* newNode = new Node{ p_pos, node->prev, node, p_data };
			nodes++;
			while (node->next != nullptr) {
				node->pos++;
				node = node->next;
			}
		}
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