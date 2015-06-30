#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "list.h"

struct Node {
    Node(char sym, int val, Node *nxt = NULL);
    char symbol;
    int value;
    Node *next;
};

class LinkedList: public List {
    public:
        LinkedList();
        LinkedList(const LinkedList &other);
        virtual ~LinkedList();

        virtual const int &get(char symbol) const;
        virtual int &get(char symbol);
        virtual void set(char symbol, int value);

        virtual void insert(int i, char symbol, int value);
        virtual void append(char symbol, int value);
        virtual void remove(char symbol);
        virtual void clear();

        virtual int length() const;
        virtual void print() const;
    private:
        Node *head, *tail;
        int size;
};

#endif

