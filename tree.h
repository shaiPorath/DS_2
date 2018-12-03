//
// Created by Hagar on 28/11/2018.
//

#ifndef LIST_TREE_H
#define LIST_TREE_H


#include <exception>

using namespace std;

class tnode{
public:
    int key;
    void* value;
    int height;
    tnode* right;
    tnode* left;
    tnode* parent;

    tnode(int key, void* value) : key(key), value(value),height(0), right(nullptr), left
            (nullptr), parent(nullptr){};
};

//enum StatusType {ALLOCATION_ERROR, INVALID_INPUT, FAILURE, SUCCESS};

typedef class tree *Tree;
typedef class tnode *TNode;

class tree{

    int size;
public:
    TNode root;

    /*------------------------------------------*/
    tree();
    /**
     * returns a pointer to the data struct or NULL if failed
     */

    void* Add(int key, void* value);
/**
 *
 * @param key - the key of the item we want to find
 * @return the node with requested key.
 * null - if was not found
 */
    void* Find(int key);
    void* Delete(int key);


    void* DeleteByPointer(void* tnode);
    int Size();
    void Quit();

    void insert_node (TNode new_node, TNode iterator, int key);

    void display(TNode ptr, int level);
    bool is_balanced(TNode n);

};

#endif //LIST_TREE_H
