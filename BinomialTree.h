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
			root = NULL;
			parent = this;
			children = new DoubleLinkedList<BinomialTree<T>>;
			this->priority = 0;
			degree = 0;
			marked = false;
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

		void display() {
			std::cout << info << " " << priority << " "<< degree << std::endl;
			if (!children->isEmpty()) {
				Node<BinomialTree<T>>* node = children->pfirst;
				do {
					node->content.display();
					node = node->next;
				} while (node != children->pfirst);
			}
		}

		bool operator==(BinomialTree<T> &a) {
			return (a.info == info && a.priority == priority);
		}
};
