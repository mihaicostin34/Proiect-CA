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

		T extractMin(){
			BinomialTree<T>* z = min;
			if (min != NULL) {
				Node<BinomialTree<T>>* minNode = rootList.find(*z);
				Node<BinomialTree<T>> * child = z->children->pfirst;
				do {
					rootList.add(child->content);
					child = child->next;
				} while (child != z->children->pfirst);
				std::cout << minNode->content.info;
				rootList.remove(minNode); 

				if (rootList.isEmpty()) { //list only has one element
					min = NULL;
					std::cout << "List is now empty";
				}
				else {
					minNode = minNode->next;
					consolidate();
				}
				this->nrNodes--;
			}
			else {
				return NULL;
			}
			return min->root->info;
		}

		void decreaseKey(T value, int key) {
		
		}

		void deleteNode(T value){
			decreaseKey(value, (int)(INFINITY * (-1)));
			extractMin();
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
			BinomialTree<T>* A = new BinomialTree<T>[n];
			for (int i = 0; i < n; i++) { //ok
				A[i].degree = -1;
			}
			Node<BinomialTree<T>>* node =rootList.pfirst; //ok
			do {
				BinomialTree<T> x = node->content; //starts at the first tree in the list
				int d = x.degree; 
				while (A[d].degree != -1) { //skips this at the first iteration
					BinomialTree<T> y = A[d];
					if (x.priority> y.priority) {
						BinomialTree<T> aux = x;
						x = y;
						y = aux;
					}
					x.children->add(y); //makes y a child of x to obtain a higher degree binomial tree
					x.degree++;
					y.marked = false;
					A[d].degree = -1;
					d++;
				}
				A[d] = x;
				node = node->next;
			} while (node != rootList.pfirst);
			rootList.empty();
			this->min = NULL;
			for (int i = 0; i < n; i++) {
				if (A[i].degree != -1) {
					if (this->min == NULL) {
						min = &A[i];
						rootList.add(A[i]);
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
				node->content.display();
				node = node->next;
			} while (node != rootList.pfirst);
		}
};