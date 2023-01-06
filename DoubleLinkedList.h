#pragma once

template <typename T> class DoubleLinkedList {
public:
    Node <T>* pfirst;

    DoubleLinkedList()
    { //constructeur
        pfirst = NULL;
    }

    void add(T info) {
        Node<T>* aux = new Node<T>(info);
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

    void display() {
        Node <T>* aux = pfirst;
        do {
            std::cout << "Info" << aux->content;
            aux = aux->next;
        } while (aux != pfirst);
    }

};