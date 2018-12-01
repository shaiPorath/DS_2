//
// Created by Hagar on 26/11/2018.
//

#include "list.h"


/*------------------------------------------------*/
//static Node node_create(int key, void* value);

/*------------------------------------------------*/

list::list() : first(nullptr), size(0){};



void* list::Add(int key, void* value) {

        Node new_node = new node(key, value);
        if(this->first) {
            (this->first)->last = new_node;
            new_node->next = first;

        }
        first = new_node;
        size++;
        return new_node;

}

/*
static Node node_create(int key, void* value){
    Node new_node = new class node();
    new_node->key = key;
    new_node->value = value;
    new_node->next = nullptr;
    new_node->last = nullptr;
    return (new_node);
}
 */
/*
void list::insert_node (Node new_node, Node iterator, int key){

    if(!iterator->last) { //insert first in the list
        new_node->next = iterator;
        this->first = new_node;
        iterator->last = new_node;
        return;
    }

    if (!iterator->next && key > iterator->key) { //insert last in the list
        iterator->next = new_node;
        new_node->last = iterator;
        return;
    }

    Node last = iterator->last;
    last->next = new_node;
    new_node->last = last;
    new_node->next = iterator;
    iterator->last = new_node;
*/

/*
void* list::Find(void* DS, int key, void** value){
    if (!DS || !value)
        return INVALID_INPUT;

    Node iterator = ((List)DS)->first;
    while (iterator && (iterator->key != key)){
        iterator = iterator->next;
    }

    if (!iterator) return FAILURE;

    *value = iterator->value;
    return SUCCESS;
}

void* list::Delete(void *DS, int key){
    if (!DS) return INVALID_INPUT;

    Node iterator = ((List)DS)->first;

    if (!iterator) return FAILURE; // list is empty

    while (iterator && key != (iterator)->key ){
        iterator = iterator->next;
    }
    if (!iterator) {
        return FAILURE;
    }

    ((List)DS)->size--;

    return (DeleteByPointer(DS, iterator));
}
*/
void* list::DeleteByPointer(void* node){
    if (!node) return nullptr;

    if (!((Node)node)->last){       //If the first is being deleted
        first = ((Node)node)->next;
        if(((Node)node)->next)      //in case list is not empty.
            (first)->last = nullptr;
        delete(((Node)node));
        return this;
    }

    if (!((Node)node)->next){   //If the last is being deleted
        (((Node)node)->last)->next = nullptr;
        delete(((Node)node));
        return this;
    }

    (((Node)node)->last)->next = ((Node)node)->next;
    (((Node)node)->next)->last = ((Node)node)->last;
    delete(((Node)node));
    return this;
}

int list::Size(){

    return this->size;

}

void list::Quit(){

    Node iterator = first;

    while (iterator->next){
        iterator = iterator->next;
        delete (iterator->last);
        iterator->last = nullptr;
    }
    delete (iterator);                  //deletes last node
    delete (this);

}