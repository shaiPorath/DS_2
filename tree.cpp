//
// Created by Hagar on 28/11/2018.
//

#include <new> //check!#$%#$%#$
#include "tree.h"
/*-------------------------------------------------*/
static Node node_create(int key, void* value);
static Node insert (Node root, int key, void* value);
static int max(int a, int b);
static int height(Node node);
static int abs(int x);
/*-------------------------------------------------*/
/*void* init(){
    try {
        Tree new_list = new tree;
        return (void*) new_list;
    } catch (bad_alloc& e) { return nullptr; }
}

tree::tree():root(nullptr),size(0){}

StatusType Add(void *DS, int key, void* value, void** node){
    if (!DS || !node)
        return INVALID_INPUT;

    try {


        if (!iterator) {
            ((Tree)DS)->root = new_node;
            ((Tree)DS)->size++;
            *node = new_node;
            return SUCCESS;
        }

        while ((key > (iterator)->key )&& iterator->next!= nullptr){
            iterator = iterator->next;
        }
        if (key == iterator->key) return FAILURE;

        ((List)DS)->insert_node(new_node, iterator, key);
        *node = new_node;
        (((List) DS)->size)++;

        return SUCCESS;

    }catch (bad_alloc& e) { return ALLOCATION_ERROR; }

}
*/
StatusType Find(void* DS, int key, void** value);
StatusType Delete(void *DS, int key);

StatusType DeleteByPointer(void *DS, void* node);
StatusType Size(void *DS, int *n);
void Quit(void **DS);

void insert_node (Node new_node, Node iterator, int key);


static Node node_create(int key, void* value){
        Node new_node = new class node;
        new_node->key = key;
        new_node->value = value;
        new_node->right = nullptr;
        new_node->left = nullptr;
        new_node->height = 0;
        return (new_node);
    }
    /*
static StatusType insert (Node root, int key, void* value, void** node) {
    try {
        if (!root) {
            root = node_create(key, value);
            *node = root;
        }
    } catch (bad_alloc &e) { return FAILURE; }

    else if (root->key < key) {
        insert(root->right, key, value);
        if (height(root->left) - height(root->right) == 2) {
            //RL

            //RR
        }
        root->height = max(height(root->left), height(root->right)) + 1;
    } else if (root->key > key) {
        insert(root->left, key, value);
        if (height(root->left) - height(root->right) == -2) {
            //LL
            if (height((root->left)->left) - height((root->left)->right) > 0) { //bf=+1

            }
            //LR
            if (height((root->left)->left) - height((root->left)->right) <= 0) { //bf=-1


            }
            root->height = max(height(root->left), height(root->right)) + 1;
        }

        return SUCCESS;

    }
}
     */
static void LR(Node root) {
    Node temp = (root->right)->left;
    (root->right)->left = root->left;
    (root->left)->right = temp;

    temp = (root->right)->right;
    (root->right)->right = root;
    root->left = temp;
}

static void RL(Node root){

}

static int max(int a, int b){
    return (a>b? a : b);
}
static int height(Node node){
    if (!node) return -1;
    return node->height;
}

static int abs(int x){
    return (x>0? x: -x);
}