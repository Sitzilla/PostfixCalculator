#include "linkedlist.h"
#include <iostream>
using namespace std;

Node::Node(char sym, float val, Node *nxt) {
    symbol = sym;
    value = val;
    next = nxt;
}

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

LinkedList::LinkedList(const LinkedList &other) {
    head = NULL;
    tail = NULL;
    size = other.size;
    if(other.head != NULL) {
#include <iostream>
        head = new Node(other.head->symbol, other.head->value);
        tail = head;
        
        Node *n = other.head->next;
        Node *m = head;
        
        while(n != NULL) {
            tail = m;
            m->next = new Node(n->symbol, n->value);
            m = m->next;
            n = n->next;
        }
    }
}

LinkedList::~LinkedList() {
    Node *n = head;
    while(n != NULL) {
        Node *m = n->next;
        delete n;
        n = m;
    }
}


const float LinkedList::get(char symbol, bool &legalSymbol) const {
    Node *n = head;

    while(n != NULL && n->symbol != symbol) {
        n = n->next;
    }
    if (n == NULL) {
        legalSymbol = false;
        return 0;
    }
    return n->value;
}

float LinkedList::get(char symbol, bool &legalSymbol) {
    Node *n = head;

    while(n != NULL && n->symbol != symbol) {
            n = n->next;
        }
        if (n == NULL) {
            legalSymbol = false;
            return 0;
        }
        return n->value;
}


void LinkedList::set(char symbol, float value) {
    Node *n = head;

    while(n != NULL && n->symbol != symbol) {
        n = n->next;
    }
    // what if n is null?
    if (n == NULL) {
        append(symbol, value);
    } else {
        n->value = value;
    }
}

void LinkedList::insert(int i, char symbol, float value) {
    size++;

    if(head == NULL) {
        head = new Node(symbol, value);
        tail = head;
    }
    else if(i == 0) {
        head = new Node(symbol, value, head);
    }
    else if(i == size - 1) {
        tail->next = new Node(symbol, value);
        tail = tail->next;
    }
    else {
        //COULD WRITE CODE HERE TO APPEND ONE DAY
        Node *n = head;
        for(int j = 0; j < i - 1; j++) {
            n = n->next;
        }
        n->next = new Node(symbol, value, n->next);
    }
}

void LinkedList::append(char symbol, float value) {
    insert(length(), symbol, value);
}

void LinkedList::remove(char symbol) {
    size--;

    int i = 0;

    Node *n = head;

    while(n->symbol != symbol) {
        n = n->next;
        i++;
    }

    if(i == 0) {
        Node *n = head->next;
        delete head;
        head = n;
    }
    else {
        Node *n = head;
        for(int j = 0; j < i - 1; j++) {
            n = n->next;
        }
        Node *next = n->next->next;
        delete n->next;
        n->next = next;
    
        if(next == NULL) {
            tail = n;
        }
    }
}

void LinkedList::clear() {
    Node *n = head;
    while(n != NULL) {
        Node *m = n->next;
        delete n;
        n = m;
    }
    head = NULL;
    size = 0;
}

int LinkedList::length() const {
    return size;
}

void LinkedList::print() const {
    Node *n = head;
    while(n != NULL) {
        cout << n->symbol << ": " << n->value << "\n";
        n = n->next;
    }
    cout << "\n";
}
