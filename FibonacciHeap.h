#pragma once
#include "DoubleLinkedList.h";
#include "Node.h";
#include "BinomialTree.h";

template <typename T> class FibonacciHeap {
	public:
		DoubleLinkedList<BinomialTree> topLevel;
		Node<T> min;

		FibonacciHeap() {
			//constructor
		}

		void insertNode(Node n) {
			
		}

		Node<T> getMin(){
			//calculates next min

			//returns min
			return min;
		}

		void decreaseKey(T value, int key) {
		
		}

		void delete(T value){
		
		}

};