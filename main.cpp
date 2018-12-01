#include <iostream>
#include "list.h"
#include "library1.h"
#include <assert.h>


int main() {
    void* new_list = new list(); //init();
    assert(!((List)new_list)->first); //init to null
    assert(!((List)new_list)->size);  //init size to 0
    int* size_ptr = new int(0);
    int* value1 = new int(1);
    int* value2 = new int(2);
    int* value3 = new int(3);
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    int** value_ptr1 = new int*();
    int** value_ptr3 = new int*();

    //function add/
    assert(((List)new_list)->Add(3, value3));
    assert(((List)new_list)->first->key=3);


    assert(((List)new_list)->Add(1, value1));
    assert(((List)new_list)->first->key == 1); //added success
    assert(((List)new_list)->Add(2, value2));
    assert(((List)new_list)->first->key == 2); //added success
/*
    assert(((List)new_list)->Size(new_list, size_ptr) == SUCCESS);       //size increased
    assert(*size_ptr == 3);       //size increased
*/
    std::cout << "Add step complete!" << std::endl;

    //function find/
              /*
              assert(((List)new_list)->Find(new_list, 2, (void**)value_ptr1)==SUCCESS); //find an
              // existing key
              assert(*value_ptr1 == value2);
              assert(((List)new_list)->Find(new_list, 4, (void**)value_ptr1)==FAILURE); //find
              // key that doesnt exist
              assert(((List)new_list)->Find(nullptr, 4, (void**)value_ptr1)==INVALID_INPUT);
              // give invalid params to func
              assert(((List)new_list)->Find(new_list, 3, (void**)value_ptr3)==SUCCESS);
              assert(*value_ptr3 == value3); //find an existing key

              std::cout << "Find step complete!" << std::endl;
          */
              //function delete/
                        /*
                            assert (((List)new_list)->Delete(new_list, 1) == SUCCESS); //remove first node
                            assert (((List)new_list)->Find(new_list, 1, (void**)value_ptr1)== FAILURE);
                            //check that first node was removed
                            assert(((List)new_list)->first == *node2); //check that now node3 is first
                            assert(((List)new_list)->Size(new_list, size_ptr) == SUCCESS);
                            assert(*size_ptr == 2);       //size decreased

                            assert (((List)new_list)->Delete(new_list, 4) == FAILURE); //bad key
                            assert (((List)new_list)->Delete(new_list, 3) == SUCCESS); //remove a node
                            assert(((List)new_list)->Size(new_list, size_ptr) == SUCCESS);
                            assert(*size_ptr == 1);       //size decreased


                            assert (((List)new_list)->Delete(new_list, 2) == SUCCESS); //remove a node
                            assert(((List)new_list)->Size(new_list, size_ptr) == SUCCESS);
                            assert(*size_ptr == 0);       //size decreased
                            assert(((List)new_list)->first == nullptr); //check that now node2 is first

                            assert (((List)new_list)->Delete(new_list, 1) == FAILURE); //remove a node

                            std::cout << "Delete step complete!" << std::endl;


                            assert(((List)new_list)->Add(new_list, 3, value3, (void**)node3)==SUCCESS);
                            assert(((List)new_list)->Add(new_list, 1, value1, (void**)node1)==SUCCESS);
                            assert(((List)new_list)->Add(new_list, 2, value2, (void**)node2)==SUCCESS);
                        */
                        //function DeleteByPointer :):)/
    //function Size :):)/

    //(((List)new_list)…

    //(((List)new_list)->Quit((new_list)*));
    void** p = &new_list;

    Quit(p);
    assert (!new_list);
    std::cout << "Quit step complite!" << endl;

    std::cout <<size_ptr<<node3<<node2<<node1<<value_ptr3<<value_ptr1<<value3<< value1
                              <<value2<<
                           std::endl ;
    delete(size_ptr);
    delete(node3);
    delete(node2);
    delete(node1);
    delete(value_ptr3);
    delete(value_ptr1);
    delete(value3);
    delete(value1);
    delete(value2);
    return 0;
}

