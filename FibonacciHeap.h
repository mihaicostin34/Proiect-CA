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
			DoubleLinkedList<BinomialTree<T>> rootlist();
		}

		void insertNode(T info, int priority) {
			BinomialTree<T>* aux = new BinomialTree<T>(info, priority);
			if (min == NULL) {
				min = aux;
				rootList.add(*aux);
			}
			else {
				rootList.add(*aux);
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
			int n = (int) floor(log(this->nrNodes) / log(2)) +1;
			BinomialTree<T> * A = new BinomialTree<T>[n];
			for (int i = 0; i < n; i++) {
				A[i].degree = -1;
		 		std::cout << "Something";
			}
			Node<BinomialTree<T>>* list_item = rootList.pfirst;
			do {
				std::cout << "Do loop";
				Node<BinomialTree<T>>* x = list_item;
				int d = x->content.degree;
				while (A[d].degree != -1 and d<n-1) {
					Node<BinomialTree<T>>* y = new Node<BinomialTree<T>>(A[d]);
					if (x->content.priority > y->content.priority) {
						Node<BinomialTree<T>> * aux = y;
						y = x;
						x = aux;
					}
					rootList.remove(y->content); //remove y from root list
					x->content.children->add(y->content); //add y to x children
					y->content.marked = false;
					A[d].degree = -1;
					d++;
				}
				A[d] = x->content;
				list_item = list_item->next;
			} while (list_item != rootList.pfirst);
			min = NULL;
			for (int i = 0; i < n; i++) {
				if (A[i].root != NULL) {
					if (min == NULL) {
						this->rootList.add(A[i]);
						min = &A[i];
					}
					else {
						this->rootList.add(A[i]);
						if (A[i].priority < min->priority)
							min = &A[i];
					}
				}
			}
		}



};