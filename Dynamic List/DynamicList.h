#pragma once
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
	Node* firstNode;
	Node* prevNode;
	Node* currentNode;

public:
	DynamicList() {
		nodes = 0;
		firstNode = nullptr;
		prevNode = nullptr;
		currentNode = nullptr;
	}

	void append(T p_data) {
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

	void pop() {
		prevNode = currentNode->prev;
		delete currentNode;

		if (prevNode == nullptr) {
			firstNode = nullptr;
			prevNode = nullptr;
		}
		else {
			currentNode = prevNode;
			currentNode->next = nullptr;
		}
		nodes--;
	}

	void pop(int p_pop) {

	}

	void clear() {
		while (nodes > 0) {
			pop();
		}
	}

	void print() {
		Node* n = firstNode;
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