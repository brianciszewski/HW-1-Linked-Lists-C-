#pragma once
#ifndef LIST_H
#define LIST_H

struct node {                      // node properties
    int Data;
    void* DataLink;
    node* next;
    node* prev;
};


class List {
private:
    node* Temp;                    // used for removing nodes to hold the node second from front/rear.
    node* P;
    node* front;
    node* rear;
    int size, hold;
    void* holdLink;                // void-pointer type variable for 'hold'.
public:
    List();

    void insertFront(int a);
    void insert_front(void* a);
    int removeFront();
    void* remove_front_p();

    void insertRear(int a);
    void insert_rear(void* a);
    int removeRear();
    void* remove_rear_p();

    void printList();
    int ListSize();
    void empty();
};

#endif