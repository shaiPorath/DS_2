//
// Created by Hagar on 30/11/2018.
//

#include "library1_list.h"

void *Init(){
    try {
        return ((void *) new tree());
    }catch (bad_alloc& e) {return nullptr;}
}

StatusType Add(void *DS, int key, void* value, void** node){
    if (!DS || !node) return INVALID_INPUT;

    try {
        *node = ((Tree) DS)->Add(key, value);
        return SUCCESS;
    }catch (bad_alloc& e ) { return ALLOCATION_ERROR; }
}

StatusType Find(void *DS, int key, void** value){
    if (!DS || !value)
        return INVALID_INPUT;

    value = &(((Tree) DS)->Find(key));
    if (!value) return FAILURE;

    return SUCCESS;
}

StatusType Delete(void *DS, int key){
    if (!DS) return INVALID_INPUT;
    if (!((Tree)DS)->Delete(key)) return FAILURE;
    return SUCCESS;

}

StatusType DeleteByPointer(void *DS, void* p){
    if (!DS || !p) return INVALID_INPUT;

    ((Tree)DS)->DeleteByPointer(p);

    return SUCCESS;
}

StatusType Size(void *DS, int *n){
    if (!DS || !n) return INVALID_INPUT;

    *n = ((Tree)(DS))->Size();
    return SUCCESS;
}

void Quit(void** DS){
    if (!DS) return;
    ((Tree)DS)->Quit();
    DS = nullptr;
}