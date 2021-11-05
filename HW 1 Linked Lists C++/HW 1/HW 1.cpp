// HW 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Brian Ciszewski. 1/29/2020

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List AAA;
    
    AAA.insertFront(5);
    void* f = AAA.remove_front_p();                 // gets the address of the variable removed.
    AAA.insertRear(47);    
    void* r = AAA.remove_rear_p();
    AAA.insertFront(88);
    std::cout << "Hello World!\n" << AAA.ListSize() << "\nremoved: " << f << "\nremoved: " << r;
    

    AAA.insertFront(1);
    AAA.insertRear(2);
    int d = AAA.removeRear();
    AAA.insertFront(3);
    AAA.insertFront(4);
    AAA.insertRear(5);
   int b = AAA.removeRear();
    AAA.insertFront(6);

    std::cout << "\n\nList size: " << AAA.ListSize();
    std::cout << "\n\nList = ";
    AAA.printList();
    AAA.empty();

    std::cout << "\n\n";
    return 0;
}

