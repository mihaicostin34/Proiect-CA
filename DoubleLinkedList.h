#pragma once

template <typename T> class DoubleLinkedList {
public:
    Node <T>* pfirst, *plast;

    DoubleLinkedList()
    { //constructeur
        pfirst = NULL;
        plast = NULL;

    }

    void add(T info) {
        Node<T>* aux = new Node<T>(info);
        if (pfirst == NULL) { //daca lista este goala, il adauga ca prim element
            pfirst = aux;
            plast = aux;
            aux->next = aux;
            aux->prev = aux;

        }
        else { //daca lista nu este goala
            plast->next = aux;
            aux->prev = plast;
            plast = aux;
            pfirst->prev = plast;
            plast->next = pfirst;
        }
        //std::cout << "Added node";
        //std::cout << std::endl;
        //std::cout << "First is" << pfirst->content.info;
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
        if (target != NULL and target != plast) {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
        else {
            //target is last element
            plast = target->prev;
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