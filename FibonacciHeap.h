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
		}

		T* extractMin(){
			//calculates next min

			//deletes current min

			//returns min
			return min->info;
		}

		void decreaseKey(T value, int key) {
		
		}

		void deleteNode(T value){
		
		}

		static FibonacciHeap *  merge(FibonacciHeap * H1, FibonacciHeap * H2) {
			FibonacciHeap* H = new FibonacciHeap;

			return H;
		}

		int D() {
			return floor(log(this->nrNodes)/log(2));
		}

};