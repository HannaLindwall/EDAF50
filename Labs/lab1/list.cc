#include <iostream>
#include "list.h"

List::List() {
	first = nullptr;
}

List::~List() {
	if(!empty()) {
		while(first != nullptr) {
			Node* del = first;
			first = first->next;
			delete del;
		}
	}
}

bool List::exists(int d) const {
	Node* temp = first;
	if(!empty()) {
		while(temp != nullptr) {
			if(temp->value == d) {
				return true;
			}
			temp = temp->next;
		}
	}
	return false;
}

int List::size() const {
	int size = 0;
	Node* temp = first;
	if(!empty()) {
		while(temp != nullptr) {
			size++;
			temp = temp->next;
		}
	}
	return size;
}

bool List::empty() const {
	if(first == nullptr) {
		return true;
	} else {
		return false;
	}
}

void List::insertFirst(int d) {
	Node* node = new Node(d, first);
	first = node;
}

void List::remove(int d, DeleteFlag df) {
	if(!empty()) {
		Node* pre = first;
		Node* current = first;
		int value;
		bool flag = false;
		while (current != nullptr) {
			value = current->value;
			if(df == DeleteFlag::LESS) {
				if(d > value) {
					flag = true;
				}
			} else if(df == DeleteFlag::EQUAL) {
				if(d == value) {
					flag = true;
				}
			} else {
				if(d < value) {
					flag = true;
				}
			}
			if(flag) {
				if(current == first) {
					first = current->next;
				} else {
					pre->next = current->next;
				}
				delete current;
				return;
			}
			pre = current;
		 	current = current->next;
		}
	}
}

void List::print() const {
	if(!empty()) {
		Node* temp = first;
		std::cout << std::endl;
		while(temp != nullptr) {
			std::cout << temp->value << std::endl;
			temp = temp->next;
		}
	}
	std::cout << "size: " << size() << std::endl;
}
