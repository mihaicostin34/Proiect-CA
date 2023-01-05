#include <iostream>
#include "Node.h"
#include "BinomialTree.h"
#include "DoubleLinkedList.h"
#include "FibonacciHeap.h"

int main()
{
	//double linked list test works
	DoubleLinkedList<char> list;
	list.add('c', 20);
	list.add('d', 2);
	list.add('a', 40);
	list.display();
}

