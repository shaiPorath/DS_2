//
// Created by Hagar on 26/11/2018.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>
#include <exception>

using namespace std;

typedef class node *Node;

//typedef enum {ALLOCATION_ERROR, INVALID_INPUT, FAILURE, SUCCESS} StatusType ;

class node{
public:
    int key;
    void* value;
    node* next;
    node* last;

    node(int key, void* value) : key(key), value(value), next(nullptr), last
            (nullptr){};
};

typedef class list{
    int size;
public:
    Node first;

    /*------------------------------------------*/
    list();

    void* Add(int key, void* value);
    void* Find(int key);
    void* Delete(int key);
    void* DeleteByPointer(void* node);
    int Size();
    void Quit();

}*List;



#endif //LIST_LIST_H