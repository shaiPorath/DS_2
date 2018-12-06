#include <iostream>
#include "library1_list.h"
#include <assert.h>


int main() {
    List new_list = new list(); //init();
    assert(!new_list->first); //init to null
    assert(!new_list->Size());  //init size to 0
    //int* size_ptr = new int(0);
    int* value1 = new int(1);
    int* value2 = new int(2);
    int* value3 = new int(3);

    /*function add*/
    Node node3 = ((Node)(new_list)->Add(3, value3));
    assert(node3->key == 3);
    assert((((List)new_list)->first)->key = 3);

    Node node1 = ((Node)((List)new_list)->Add(1, value1));
    assert(node1->key == 1);
    assert((((List)new_list)->first)->key = 1);

    Node node2 = ((Node)((List)new_list)->Add(2, value2));
    assert(node3->key == 3);
    assert((((List)new_list)->first)->key = 2);


    assert(((List)new_list)->Size() == 3);       //size increased

    std::cout << "Add step complete!" << std::endl;

    /*function find*/

    assert(((Node)(((List)new_list)->Find(2)))->value == value2 ); //find an
    // existing key

    assert((((List)new_list)->Find(4)) == nullptr); //find
    // key that doesnt exist
    //assert(((List)new_list)->Find(nullptr, 4, (void**)value_ptr1)==INVALID_INPUT);
    // give invalid params to func
    assert(((Node)(((List)new_list)->Find(3)))->value == value3);
    //assert(*value_ptr3 == value3); //find an existing key

    std::cout << "Find step complete!" << std::endl;

    /*function delete*/

    assert (((List)new_list)->Delete(1) == ((List)new_list)); //remove first node
    assert (((List)new_list)->Find(1)== nullptr); //check that first node was removed

    assert(((List)new_list)->first == node2); //check that now node2 is first
    assert(((List)new_list)->Size() == 2); //size decreased

    assert (((List)new_list)->Delete(4) == nullptr); //bad key
    assert (((List)new_list)->Delete(3) == ((List)new_list)); //remove a node
    assert (((List)new_list)->Size() == 1);


    assert (((List)new_list)->Delete(2) == ((List)new_list)); //remove a node
    assert(((List)new_list)->Size() == 0);

    assert(((List)new_list)->first == nullptr); //check that now node2 is first

    assert (((List)new_list)->Delete(1) == nullptr); //remove a node when list is null

    std::cout << "Delete step complete!" << std::endl;


    /*function DeleteByPointer :):)*/

    node1 = ((Node)((List)new_list)->Add(1, value1));
    node2 = ((Node)((List)new_list)->Add(2, value2));
    node3 = ((Node)((List)new_list)->Add(3, value3));

    assert(((List)new_list)->DeleteByPointer(node2) == (new_list));
    assert(((List)new_list)->first == node3);
    assert(((List)new_list)->Size() == 2);


    //(((List)new_list)->Quit((new_list)*));
    ((List)new_list)->Quit();

    std::cout <<node3<<node2<<node1<<value3<< value1 <<value2<<std::endl ;


    delete(value3);
    delete(value1);
    delete(value2);
    return 0;
}