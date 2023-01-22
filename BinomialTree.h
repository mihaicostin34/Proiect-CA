#pragma once
template <typename T> class BinomialTree {
	public:
		BinomialTree<T>* root, * parent;
		T info;
		int priority;
		DoubleLinkedList<BinomialTree<T>>* children;
		int degree;
		bool marked;

		BinomialTree() {
		
		}

		BinomialTree(T info, int priority) {
			root = NULL;
			parent = this;
			children = new DoubleLinkedList<BinomialTree<T>>;
			this->info = info;
			this->priority = priority;
			degree = 0;
			marked = false;
		}

		bool operator==(BinomialTree<T> &a) {
			return (a.info == info && a.priority == priority);
		}

};