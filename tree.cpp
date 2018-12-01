//
// Created by Hagar on 28/11/2018.
//

#include "tree.h"
/*-------------------------------------------------*/
static TNode insert (TNode root, TNode new_tnode);
static int bf_calc (TNode node);
static int max(int a, int b);
static int height(TNode tnode);
static int abs(int x);
/*-------------------------------------------------*/

tree::tree():size(0), root(nullptr){}

void* tree::Add(int key, void* value) {
    TNode new_tnode = new tnode(key, value);
    insert(root, new_tnode);
    size++;
    return new_tnode;
}


static TNode insert (TNode root, TNode new_tnode) {

    if (!root) {
        root = new_tnode;
        return root;
    }


    else if (root->key < new_tnode->key) {
        root->right = insert(root->right, new_tnode);
        //insert(root->right, new_tnode);

        if (height(root->left) - height(root->right) == 2) {
            //RL

            //RR
        }
        root->height = max(height(root->left), height(root->right)) + 1;
        check_height();
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
static TNode balance (TNode temp){
    int b_factor = bf_calc(temp);
    if (b_factor > 1){
        if (bf_calc(temp->left) >= 0)
            temp = LL_rotation(temp);
        else
            temp = LR_rotation(temp);
    }
    else if (b_factor< -1){
        if (bf_calc(temp->right) <= 0)
            temp = RL_rotation(temp);
        else
            temp = RR_rotation(temp);
    }
    return temp;
}

static TNode LL_rotation (TNode root){
    TNode temp;
    temp = root-> left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

static TNode LR_rotation(TNode root){
    TNode temp;
    temp = root->left;
    root->left = RR_rotation(temp);
    return LL_rotation(root);
}

static TNode LR_rotation(TNode root){

}
static TNode LR_rotation(TNode root){

}

static int bf_calc (TNode node){
    return (height(node->left)-height(node->right));
}
StatusType Find(void* DS, int key, void** value);
StatusType Delete(void *DS, int key);

StatusType DeleteByPointer(void *DS, void* tnode);
StatusType Size(void *DS, int *n);
void Quit(void **DS);

static void LR(TNode root) {
    TNode temp = (root->right)->left;
    (root->right)->left = root->left;
    (root->left)->right = temp;

    temp = (root->right)->right;
    (root->right)->right = root;
    root->left = temp;
}

static void RL(TNode root){

}

static int max(int a, int b){
    return (a>b? a : b);
}
static int height(TNode tnode){
    if (!tnode) return -1;
    return tnode->height;
}

static int abs(int x){
    return (x>0? x: -x);
}