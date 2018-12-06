//
// Created by Hagar on 01/12/2018.
//
#include <iostream>
#include "tree.h"
#include <assert.h>


int main() {
    Tree new_tree = new tree(); //init();
    assert(!((Tree) new_tree)->root); //init to null
    assert(!((Tree) new_tree)->Size());  //init size to 0
    //int* size_ptr = new int(0);
    int *value1 = new int(1);
    int *value2 = new int(2);
    int *value3 = new int(3);
    int *value4 = new int(4);
    int *value5 = new int(5);
    int *value6 = new int(6);


    /*function add*/
    TNode tnode3 = ((TNode)((Tree) new_tree)->Add(3, value3));
    assert(tnode3->key == 3);
    assert((((Tree) new_tree)->root)->key = 3);
    //new_tree->display(new_tree->root,0);

    TNode tnode1 = ((TNode)((Tree) new_tree)->Add(1, value1));
    assert(tnode1->key == 1);
    assert((((Tree) new_tree)->root->left)->key = 1);
    //new_tree->display(new_tree->root,0);

    TNode tnode2 = ((TNode)((Tree) new_tree)->Add(2, value2));
    assert(tnode3->key == 3);
    //assert((((Tree) new_tree)->first)->key = 2);
    //new_tree->display(new_tree->root,0);

    assert(((Tree) new_tree)->Size() == 3);       //size increased
    assert(new_tree->is_balanced(new_tree->root));

    TNode tnode4 = ((TNode)((Tree) new_tree)->Add(4, value4));
    //new_tree->display(new_tree->root,0);

    TNode tnode5 = ((TNode)((Tree) new_tree)->Add(5, value5));
    //new_tree->display(new_tree->root,0);

    TNode tnode6 = ((TNode)((Tree) new_tree)->Add(6, value6));
    //new_tree->display(new_tree->root,0);

    assert(new_tree->is_balanced(new_tree->root));


    //new_tree->display(new_tree->root,0);
    std::cout << "\n" <<"Add step complete!" << std::endl;


    /*function find*/

    assert(((TNode)(((Tree)new_tree)->Find(2))) == tnode2 ); //find an
    // existing key

    assert((((Tree)new_tree)->Find(10)) == nullptr); //find
    // key that doesnt exist
    //assert(((Tree)new_tree)->Find(nullptr, 4, (void**)value_ptr1)==INVALID_INPUT);
    // give invalid params to func
    assert(((TNode)(new_tree->Find(3)))->value == value3);
    //assert(*value_ptr3 == value3); //find an existing key

    std::cout << "Find step complete!" << std::endl;

    /*function delete*/
    assert (new_tree->Delete(1) == new_tree); //remove first node
    assert (((Tree)new_tree)->Find(1)== nullptr); //check that first node was removed
    assert(((Tree)new_tree)->root == tnode4); //check that now node2 is first
    assert(((Tree)new_tree)->Size() == 5); //size decreased
    assert (((Tree)new_tree)->Delete(10) == nullptr); //bad key
    assert (((Tree)new_tree)->Delete(4) == ((Tree)new_tree)); //remove a node
    assert (((Tree)new_tree)->Size() == 4);
    assert (((Tree)new_tree)->Delete(2) == ((Tree)new_tree)); //remove a node
    assert (((Tree)new_tree)->Delete(3) == ((Tree)new_tree)); //remove a node
    assert (((Tree)new_tree)->Delete(5) == ((Tree)new_tree)); //remove a node
    assert(((Tree)new_tree)->Size() == 1);
    assert (((Tree)new_tree)->Delete(6) == ((Tree)new_tree)); //remove a node
    assert(((Tree)new_tree)->Size() == 0);
    assert(((Tree)new_tree)->root == nullptr); //check that now root is null
    assert (((Tree)new_tree)->Delete(1) == nullptr); //remove a node when tree is null

    std::cout << "Delete step complete!" << std::endl;

    /*function DeleteByPointer :):)*/
    tnode1 = ((TNode)((Tree) new_tree)->Add(1, value1));
    tnode2 = ((TNode)((Tree) new_tree)->Add(2, value2));
    tnode3 = ((TNode)((Tree) new_tree)->Add(3, value3));
    tnode4 = ((TNode)((Tree) new_tree)->Add(4, value4));

    assert(new_tree->DeleteByPointer(tnode3) == new_tree);
    assert (((Tree)new_tree)->Find(3)== nullptr); //check that first node was removed
    assert(((Tree)new_tree)->Size() == 3);


    assert(new_tree->DeleteByPointer(tnode1) == new_tree);
    assert (((Tree)new_tree)->Find(1)== nullptr); //check that first node was removed
    assert(((Tree)new_tree)->Size() == 2);

    assert(new_tree->DeleteByPointer(tnode2) == new_tree);
    assert (((Tree)new_tree)->Find(2)== nullptr); //check that first node was removed
    assert(((Tree)new_tree)->Size() == 1);

    assert(new_tree->DeleteByPointer(tnode4) == new_tree);
    assert (((Tree)new_tree)->Find(4)== nullptr); //check that first node was removed
    assert(((Tree)new_tree)->Size() == 0);

    assert(new_tree->root == nullptr);

    new_tree->Quit();
    delete(value1);
    delete(value2);
    delete(value3);
    delete(value4);
    delete(value5);
    delete(value6);
    std::cout << endl << "Quit step complete!" << std::endl;
}