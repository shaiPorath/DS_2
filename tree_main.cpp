//
// Created by Hagar on 01/12/2018.
//
#include <iostream>
#include "tree.h"
#include <assert.h>

int main() {
    void *new_tree = new tree(); //init();
    assert(!((Tree) new_tree)->root); //init to null
    assert(!((Tree) new_tree)->Size());  //init size to 0
    //int* size_ptr = new int(0);
    int *value1 = new int(1);
    int *value2 = new int(2);
    int *value3 = new int(3);

    /*function add*/
    TNode tnode3 = ((TNode)((Tree) new_tree)->Add(3, value3));
    assert(tnode3->key == 3);
    assert((((Tree) new_tree)->first)->key = 3);

    TNode tnode1 = ((TNode)((Tree) new_tree)->Add(1, value1));
    assert(tnode1->key == 1);
    assert((((Tree) new_tree)->first)->key = 1);

    TNode tnode2 = ((TNode)((Tree) new_tree)->Add(2, value2));
    assert(tnode3->key == 3);
    assert((((Tree) new_tree)->first)->key = 2);


    assert(((Tree) new_tree)->Size() == 3);       //size increased

    std::cout << "Add step complete!" << std::endl
}