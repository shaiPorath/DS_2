//
// Created by Hagar on 30/11/2018.
//

#include "library1.h"


void *Init(){
    try {
        return ((void *) new list());
    }catch (bad_alloc& e) {return nullptr;}
}

StatusType Add(void *DS, int key, void* value, void** node){
    if (!DS || !node) return INVALID_INPUT;

    try {
        *node = ((List) DS)->Add(key, value);
        if (!*node) return FAILURE;
        return SUCCESS;

    }catch (bad_alloc& e ) { return ALLOCATION_ERROR; }
}

StatusType Find(void *DS, int key, void** value){
    if (!DS || !value)
        return INVALID_INPUT;
    Node found = (Node)((List) DS)->Find(key);
    if (!found) return FAILURE;
    *value = ((Node)(((List) DS)->Find(key)))->value;
    return SUCCESS;
}

StatusType Delete(void *DS, int key){
    if (!DS) return INVALID_INPUT;
    if (!((List)DS)->Delete(key)) return FAILURE;
    return SUCCESS;

}
StatusType DeleteByPointer(void *DS, void* p){
    if (!DS || !p) return INVALID_INPUT;

    ((List)DS)->DeleteByPointer(p);

    return SUCCESS;
}

StatusType Size(void *DS, int *n){
    if (!DS || !n) return INVALID_INPUT;

    *n = ((List)(DS))->Size();
    return SUCCESS;
}


void Quit(void** DS){
    if (!DS) return;

    ((List)DS)->Quit();

    DS = nullptr;
}