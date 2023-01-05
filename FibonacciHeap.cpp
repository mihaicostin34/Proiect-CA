#include <iostream>
#include "Node.h"
#include "BinomialTree.h"
#include "DoubleLinkedList.h"
#include "FibonacciHeap.h"

int main()
{
    //DoubleLinkedList test
    DoubleLinkedList<char> list;
    std::cout << list.isEmpty();
    list.add('c', 20);
    list.add('x', 1);
    list.add('g', 5);
    list.add('t', 70);
    list.display(); //display is working

    list.remove('g');
    list.display();





}

