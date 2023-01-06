#pragma once
template <typename T> class BinomialTree {
	public:
		BinomialTree<T>* root, * parent;
		T* info;
		int priority;
		DoubleLinkedList<BinomialTree<T>>* children;
		int degree;

		BinomialTree() {
		
		}

		BinomialTree(T inf, int priority) {
			root = NULL;
			parent = NULL;
			children = new DoubleLinkedList<BinomialTree<T>>;
			info = new T;
			*info = inf;
			this->priority = priority;
			degree = 0;
		}

		



};