#pragma once
template <typename T> class Node {
	public:
		T content;
		Node<T>* prev;
		Node<T>* next;

		Node(T content) {
			this->content = content;
			this->prev = NULL;
			this->next = NULL;
		}
};