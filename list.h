#ifndef LIST_H
#define LIST_H

class List {
    public:
        virtual ~List() {};

        virtual const float get(char symbol, bool &legalSymbol) const = 0;
        virtual float get(char symbol, bool &legalSymbol) = 0;
        virtual void set(char symbol, float value) = 0;

        virtual void insert(int i, char symbol, float value) = 0;
        virtual void append(char symbol, float value) = 0;
        virtual void remove(char symbol) = 0;
        virtual void clear() = 0;

        virtual int length() const = 0;
        virtual void print() const = 0;
};

#endif

