#pragma once
#include "DoubleLinkedList.h";
#include "Node.h";
#include "BinomialTree.h";

template <typename T> class FibonacciHeap {
	public:
		DoubleLinkedList<T> rootList;
		Node<T> * min;
		int nrNodes;

		FibonacciHeap() {
			//constructor
			nrNodes = 0;
			min = NULL;
			DoubleLinkedList<T> rootlist();
		}

		void insertNode(T info, int priority) {
			Node<T>* aux = new Node<T>(info, priority);
			if (min == NULL) {
				min = aux;
				rootList->add(info, priority);
			}
			else {
				rootList->add(info, priority);
				if (priority < min->priority) {
					min = aux;
				}
			}
			nrNodes++;
		}

		Node<T>* extractMin(){
			//calculates next min

			//deletes current min

			//returns min
			return min;
		}

		void decreaseKey(T value, int key) {
		
		}

		void deleteNode(T value){
		
		}

		static FibonacciHeap *  merge(FibonacciHeap * H1, FibonacciHeap * H2) {
			FibonacciHeap* H = new FibonacciHeap;

			return H;
		}

};