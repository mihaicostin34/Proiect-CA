#pragma once
template <typename T> class Node {
	public:
		T content;
		int priority;
		bool marked;
		
		Node <T>* next;
		Node <T>* prev;

		Node(T content, int priority) {
			next = NULL;
			prev = NULL;
			this->content = content;
			this->priority = priority;
			this->marked = false;
		}
};