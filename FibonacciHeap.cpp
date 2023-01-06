#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"
#include "BinomialTree.h"
#include "FibonacciHeap.h"

int main()
{
	FibonacciHeap<char> heap;
	heap.insertNode('c', 4);
	std::cout << heap.nrNodes;
	std::cout << *(heap.min->info);



}

