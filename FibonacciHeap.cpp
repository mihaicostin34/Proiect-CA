#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"
#include "BinomialTree.h"
#include "FibonacciHeap.h"

int main()
{
	FibonacciHeap<char> heap;
	heap.insertNode('c', 4);
	heap.insertNode('e', 8);
	heap.insertNode('g', 3);
	heap.insertNode('z', 34);
	heap.insertNode('a', 6);
	heap.display();
	std::cout << std::endl;
	heap.extractMin();
	heap.display();

	
	FibonacciHeap<char> heap2;
	heap2.insertNode('d', 2);
	FibonacciHeap<char>* res = FibonacciHeap<char>::merge(&heap, &heap2);

	std::cout << res->min->info<< std::endl;
	std::cout << (res->min->priority);
	
}

