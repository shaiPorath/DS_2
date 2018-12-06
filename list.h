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
/**
 *
 * @param key - the key of the item we want to find
 * @return the node with requested key.
 * null - if was not found
 */
    void* Find(int key);
    void* Delete(int key);

    /**
     *
     * @param node - node to delete
     * @return this - if found and deleted,
     *          null if node == null.
     */
    void* DeleteByPointer(void* node);


    int Size();
    void Quit();

    int* key_arr(); //returns an array of all keys
    //void insert_node (Node new_node, Node iterator, int key);
}*List;



#endif //LIST_LIST_H
