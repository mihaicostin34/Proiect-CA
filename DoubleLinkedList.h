#pragma once

template <typename T> class DoubleLinkedList {
public:
    Node <T>* pfirst;

    LinkedList()
    { //constructeur
        pfirst = NULL;
    }

    void add(T info, int priority) {
        Node<T>* aux = new Node<T>(info, priority);
        if (pfirst == NULL) { //daca lista este goala, il adauga ca prim element
            pfirst = aux;
            aux->next = aux;
            aux->prev = aux;

        }
        else { //daca lista nu este goala
            pfirst->prev->next = aux;
            aux->prev = pfirst->prev;
            pfirst->prev = aux;
            aux->next = pfirst;
        }
    }

    Node<T>* find(T info) {
        Node<T>* aux = pfirst;
        do {
            if (aux->content == info)
                return aux;
            aux = aux->next;
        } while (aux != pfirst);
        return NULL;
    }

    void remove(T info) {
        Node<T>* target;
        target = find(info);
        if (target != NULL) {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
    }

    int isEmpty() {
        return (pfirst == NULL);
    }

};