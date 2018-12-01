//
// Created by Hagar on 28/11/2018.
//

#ifndef LIST_TREE_H
#define LIST_TREE_H


#include <exception>

using namespace std;

class node{
public:
    void* value;
    int key;
    int height;
    node* right;
    node* left;
};

enum StatusType {ALLOCATION_ERROR, INVALID_INPUT, FAILURE, SUCCESS};

typedef class tree *Tree;
typedef class node *Node;

class tree{

public:
    Node root;
    int size;

    /*------------------------------------------*/
    tree();
    /**
     * returns a pointer to the data struct or NULL if failed
     */


    StatusType Add(void *DS, int key, void* value, void** node);

    StatusType Find(void* DS, int key, void** value);
    StatusType Delete(void *DS, int key);

    StatusType DeleteByPointer(void *DS, void* node);
    StatusType Size(void *DS, int *n);
    void Quit(void **DS);

    void insert_node (Node new_node, Node iterator, int key);
};

void* init();


#endif //LIST_TREE_H
