//
// Created by Hagar on 26/11/2018.
//

#include "list.h"


list::list():size(0), first(nullptr){}
//list::node::node(int key, void* value) : key(key), value(value), next(nullptr), last
   //     (nullptr){};

void* list::Add(int key, void* value) {

        Node new_node = new node(key, value);
        if(this->first) {
            (this->first)->last = new_node;
            new_node->next = this->first;

        }
        this->first = new_node;
        this->size++;
        return (new_node);

}


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


void* list::Find(int key){

    Node iterator = this->first;
    while (iterator && (iterator->key != key)){
        iterator = iterator->next;
    }

    if (!iterator) return nullptr; //item was not found

    return iterator; //returns the found node
}

void* list::Delete(int key){
    return (DeleteByPointer(this->Find(key)));
}

void* list::DeleteByPointer(void* node){
    if (!node) return nullptr;

    if (!((Node)node)->last){       //If the first is being deleted
        first = ((Node)node)->next;
        if(((Node)node)->next)      //in case list is not empty.
            (first)->last = nullptr;
        delete(((Node)node));
        this->size--;
        return this;
    }

    if (!((Node)node)->next){   //If the last is being deleted
        (((Node)node)->last)->next = nullptr;
        delete(((Node)node));
        this->size--;
        return this;
    }

    (((Node)node)->last)->next = ((Node)node)->next;
    (((Node)node)->next)->last = ((Node)node)->last;
    delete(((Node)node));
    this->size--;
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

int* list::key_arr(){
    if (size == 0) return nullptr;

    auto key_arr = (int*)malloc((this->size)* sizeof(int));
    if (!key_arr) return nullptr;

    Node iterator = first;

    for (int i = 0; i < size; i++, iterator = iterator->next){
        key_arr[i] = iterator->key;
    }

    return key_arr;
}