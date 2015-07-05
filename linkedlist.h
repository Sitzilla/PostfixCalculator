#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "list.h"

struct Node {
    Node(char sym, float val, Node *nxt = NULL);
    char symbol;
    float value;
    Node *next;
};

class LinkedList: public List {
    public:
        LinkedList();
        LinkedList(const LinkedList &other);
        virtual ~LinkedList();

        virtual const float get(char symbol, bool &legalSymbol) const;
        virtual float get(char symbol, bool &legalSymbol);
        virtual void set(char symbol, float value);

        virtual void insert(int i, char symbol, float value);
        virtual void append(char symbol, float value);
        virtual void remove(char symbol);
        virtual void clear();

        virtual int length() const;
        virtual void print() const;
    private:
        Node *head, *tail;
        int size;
};

#endif

