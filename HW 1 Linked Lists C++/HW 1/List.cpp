#include <iostream>
#include "List.h"
#include<typeinfo>



List::List() {}

void List::insertFront(int a)
{
    P = new node;                           // makes a new node that will become the front of the list.
    if (P == NULL) {                        // error in creating a new node.
        std::cout << "System out of Memory.\n";
    }

    P->Data = a;                            // gets int fron 'insertFront(int a)'.

    if (front == NULL) {                    // empty list, front = rear.
        P->next = NULL;                     // Sets the 'next' of the new node 'P' to null, b/c 1 item list.
        P->prev = NULL;                     // Sets the 'previous' node in list to null b/c first node.
        front = rear = P;                   // sets the pointers for front/rear to the new node P.
    }
    else {                                  // list has 1 or more nodes.
        P->prev = NULL;                     // Sets the 'previous' node of the new front to nothing.
        P->next = front;                    // sets the 'next' of new node 'P' to the previous front node.
                                            // front is set to the value of the next node from-P. 
        front = P;                          // sets the front-pointer to the new node P.
    }
}

void List::insert_front(void* a)
{
    P = new node;                           // makes a new node that will become the front of the list.
    if (P == NULL) {                        // error in creating a new node.
        std::cout << "System out of Memory.\n";
    }

    P->DataLink = a;                        // gets int fron 'insertFront(int a)'.

    if (front == NULL) {                    // empty list, front = rear.
        P->next = NULL;                     // Sets the 'next' of the new node 'P' to null, b/c 1 item list.
        P->prev = NULL;                     // Sets the 'previous' node in list to null b/c first node.
        front = rear = P;                   // sets the pointers for front/rear to the new node P.
    }
    else {                                  // list has 1 or more nodes.
        P->prev = NULL;                     // Sets the 'previous' node of the new front to nothing.
        P->next = front;                    // sets the 'next' of new node 'P' to the previous front node.
                                            // front is set to the value of the next node from-P. 
        front = P;                          // sets the front-pointer to the new node P.
    }
}

void List::insertRear(int a)
{
    P = new node;
    P->Data = a;

    if (front == NULL) {                    // empty list.
        P->prev = NULL;                     // Sets the previous node to null.
        P->next = NULL;                     // Sets the next node to null.
        front = rear = P;                   // sets the front/rear pointers to the value of P.
        
    }
    else {                                  // list has 1 or more nodes.
        P->next = NULL;                     // Sets the next node from P to NULL.
        P->prev = rear;                     // Sets the previous node from P to rear.
        rear = P;                           // Makes P the new rear, next=null AND prev=(old)rear.
    }
}

void List::insert_rear(void* a)
{
    P = new node;
    P->DataLink = a;

    if (front == NULL) {                    // empty list.
        P->prev = NULL;                     // Sets the previous node to null.
        P->next = NULL;                     // Sets the next node to null.
        front = rear = P;                   // sets the front/rear pointers to the value of P.

    }
    else {                                  // list has 1 or more nodes.
        P->next = NULL;                     // Sets the next node from P to NULL.
        P->prev = rear;                     // Sets the previous node from P to rear.
        rear = P;                           // Makes P the new rear, next=null AND prev=(old)rear.
    }
}

int List::removeFront()
{
    P = new node;
    Temp = new node;
    if (front == NULL) {                    // empty list
        hold = 0;
        std::cout << "The list is empty";
    }
    else if (front == rear) {               // List has exactly one node.
        hold = front->Data;                 // grabs the Data from the front node and stores it in hold for return. 
        P = front;                          // sets P(temp) to the value of front
        delete P;                           // deletes the pointer value of P(pointing to the front node).
        P = NULL;                           // clears the value of P.
        front = rear = P;                   // sets the front/rear pointers to P, ALL == NULL b/c was 1-list. 
    }
    else {                                  // List has more than 1 nodes.
        hold = front->Data;                 // hold gets the Data of the value of the front node.
        Temp = front->next;                 // Sets Temp to the second node in list.
        Temp->prev = NULL;                  // Clears the prevois pointer of seccond node in list.

        P = front;                          // sets P to the value of the front node.
        delete P;                           // deletes the node front from the reference pointer P.
        P = NULL;                           // clears P.

        front = Temp;                       // The second node becomes front after old-front deleted.
    }
    return hold;
}

void* List::remove_front_p()
{
    P = new node;
    Temp = new node;
    if (front == NULL) {                    // empty list
        holdLink = 0;
        std::cout << "The list is empty";
    }
    else if (front == rear) {               // List has exactly one node.
        holdLink = front->DataLink;                 // grabs the Data from the front node and stores it in hold for return. 
        P = front;                          // sets P(temp) to the value of front
        delete P;                           // deletes the pointer value of P(pointing to the front node).
        P = NULL;                           // clears the value of P.
        front = rear = P;                   // sets the front/rear pointers to P, ALL == NULL b/c was 1-list. 
    }
    else {                                  // List has more than 1 nodes.
        holdLink = front->DataLink;                 // hold gets the Data of the value of the front node.
        Temp = front->next;                 // Sets Temp to the second node in list.
        Temp->prev = NULL;                  // Clears the prevois pointer of seccond node in list.

        P = front;                          // sets P to the value of the front node.
        delete P;                           // deletes the node front from the reference pointer P.
        P = NULL;                           // clears P.

        front = Temp;                       // The second node becomes front after old-front deleted.
    }
    return &holdLink;

/*
        Bug Adventures:
            The void* HoldLink does NOT properly retrieve int types. CDCDCDCDCD == AAAAAHHHHHH

*/


}

int List::removeRear()
{   
    Temp = new node;
    P = new node;
    if (front == NULL) {         // empty list
        std::cout << "Cannot remove from Rear, List empty.\n";
    }
    else if (front == rear) {    // list has only one item
        hold = rear->Data;       // hold gets the data from rear to return
        delete rear;             // rear is deleted
        front = rear = NULL;     // b/c only one item in list, empty list == NULL now.
    }
    else {                      // list has 2 or more elements
        hold = rear->Data;      // hold gets data from rear to return

        Temp = rear->prev;      // Temp becomes the second to last node.
        P = rear;
        delete P;
        P = NULL;

        rear = Temp;
    }
    return hold;
}

void* List::remove_rear_p()
{
    holdLink = NULL;                        // void-pointer type variable for 'hold'.
    if (front == NULL) {                    // empty list
        std::cout << "Cannot remove from Rear, List empty.\n";
    }
    else if (front == rear) {               // list has only one item
        holdLink = rear->DataLink;          // hold gets the data from rear to return
        delete rear;                        // rear is deleted
        front = rear = NULL;                // b/c only one item in list, empty list == NULL now.
    }
    else {                                  // list has 2 or more elements
        holdLink = rear->DataLink;          // hold gets data from rear to return

        Temp = rear->prev;                  // Temp becomes the second to last node.
        P = rear;
        delete P;
        P = NULL;

        rear = Temp;
    }
    return holdLink;
}

void List::printList()
{
    P=front;
    while (P != NULL) {
        std::cout << P->Data << ",";
        P = P->next;
    }
}

int List::ListSize()
{
    int size;
    if (front == NULL) {   // size of list is 0 when empty
        size = 0;
    }
    else if (front != NULL) {
        size = 0;
        P = front;
        while (P != NULL) {
            P->Data;
            P = P->next;
            size++;
        }
    }
    return size;
}

void List::empty() {
    if (front == NULL) {
        std::cout << "List is empty.";
    }
    else {
        std::cout << "\nThe list has " << List::ListSize() << " elements.";
    }
}