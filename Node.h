#pragma once
template <typename T> class Node {
	public:
		T content;
		int priority;
		Node<T>* prev;
		Node<T>* next;

		Node(T content, int priority) {
			this->content = content;
			this->priority = priority;
			this->prev = NULL;
			this->next = NULL;
		}
};