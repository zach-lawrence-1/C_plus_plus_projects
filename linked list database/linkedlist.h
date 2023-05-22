#ifndef LINKEDLIST
#define LINKEDLIST

#include "database.h"

class Node
{
    public:
        Node* next;
        Employee data;
    
    public:

        Node();
        Node(const Node& node);
        Node(string company, string name, int id, string job);
        Node& operator=(const Node& node);
        ~Node() {};

        bool operator<(const Node& node);
};

class LinkedList
{
    private:
        Node* head;

    public:
        void insert(Node& node);
        void clear();
        void print();

        //rule of three
        LinkedList();
        LinkedList(const LinkedList& ll);
        LinkedList& operator=(const LinkedList& ll);
        ~LinkedList();
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);

#endif