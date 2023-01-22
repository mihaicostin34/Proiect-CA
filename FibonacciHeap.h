#pragma once
#include "Node.h";
#include "DoubleLinkedList.h";
#include "BinomialTree.h";
#include <cmath>

template <typename T> class FibonacciHeap {
	public:
		DoubleLinkedList<BinomialTree<T>> rootList;
		BinomialTree<T> * min;
		int nrNodes;

		FibonacciHeap() {
			//constructor
			nrNodes = 0;
			min = NULL;
			DoubleLinkedList<BinomialTree<T>> rootList();
		}

		void insertNode(T info, int priority) {
			BinomialTree<T>* aux = new BinomialTree<T>(info, priority);
			if (min == NULL) {
				min = aux;
				rootList.add(BinomialTree<T>(info, priority));
				
			}
			else {
				rootList.add(BinomialTree<T>(info, priority));
				if (priority < min->priority) {
					min->info = aux->info;
				}
			}
			nrNodes++;
			consolidate();
		}

		/*
		T* extractMin(){
			
			BinomialTree<T>* z = min;
			Node<BinomialTree<T>> * minNode = rootList->find(*z);
			if (z != NULL) {
				//for each child of z
				Node<T> * child = z->children->pfirst;
				do {
					rootList->add(*child);
					child = child->next;
				} while (child != z->children->pfirst);
				rootList->remove(*minNode);
				if (z == minNode->next->content) { //list only has one element
					min = NULL;
				}
				else {
					min = minNode->next->content;
					consolidate();
				}
				this->nrNodes--;
			}
			else {
				return NULL;
			}
			return min->root->info;
		}
		*/

		void decreaseKey(T value, int key) {
		
		}

		void deleteNode(T value){
			decreaseKey(value, (int)(INFINITY * (-1)));
			//extractMin();
		}

		static FibonacciHeap *  merge(FibonacciHeap * H1, FibonacciHeap * H2) {
			FibonacciHeap* H = new FibonacciHeap;
			H->min = H1->min;
			Node<BinomialTree<T>> * secondRootList = H2->rootList.pfirst;
			do {
				H1->rootList.add(secondRootList->content);
				secondRootList = secondRootList->next;
			} while (secondRootList != H2->rootList.pfirst);
			if (H1->min == NULL or (H2->min != NULL and H2->min->priority < H1->min->priority)) {
				H->min = H2->min;
			}
			H->nrNodes = H1->nrNodes + H2->nrNodes;
			H->consolidate();
			return H;
		}

		void consolidate() {
			int n = (int)floor(log(nrNodes) / log(2))+1;
			std::cout << n << std::endl;
			BinomialTree<T>* A = new BinomialTree<T>[n];
			for (int i = 0; i < n; i++) { //ok
				A[i].degree = -1;
			}
			Node<BinomialTree<T>>* node =rootList.pfirst;
			do {
				Node<BinomialTree<T>> * x = node;
				int d = x->content.degree;
				std::cout << d;
				while (A[d].degree != -1 and d<n) {
					Node<BinomialTree<T>> * y = new Node<BinomialTree<T>>(A[d]);
					if (x->content.priority > y->content.priority) {
						Node<BinomialTree<T>>* aux = x;
						x = y;
						y = aux;
					}
					rootList.remove(y->content);
					x->content.children->add(y->content);
					x->content.degree++;
					y->content.marked = false;
					A[d].degree = -1;
					d++;
				}
				node = node->next;
			} while (node != rootList.pfirst);
			for (int i = 0; i < n; i++)
				if (A[i].degree != -1)
					std::cout << i << " ";
			std::cout << std::endl;
			this->min = NULL;
			for (int i = 0; i < n; i++) {
				if (A[i].degree != -1) {
					if (this->min == NULL) {
						BinomialTree<T> rootList;
						min = &A[i];
					}
					else {
						rootList.add(A[i]);
						if (A[i].priority < min->priority) {
							min = &A[i];
						}
					}
				}
			}

		}

		void display() {
			Node<BinomialTree<T>>* node = rootList.pfirst;
			do {
				std::cout << node->content.info;
				node = node->next;
			} while (node != rootList.pfirst);
		}
};