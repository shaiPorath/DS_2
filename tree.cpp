//
// Created by Hagar on 28/11/2018.
//

#include "tree.h"
#include <iostream>

/*-------------------------------------------------*/
//Add
static TNode Add_aux(TNode root, TNode new_tnode);

//Find
static void* Find_aux(TNode root,int key);
static void* Find_node(int key);

//Quit
static void Quit_aux(TNode node);

//Delete
static TNode findMin(TNode node);
static TNode Delete_aux(int key, TNode root);
static void copy_min_values (TNode min, TNode root);

//balancing functions
static int bf_calc (TNode node); //calculates the balance factor
static int max(int a, int b);
static int height(TNode tnode);// return (max of to sons+1),-1 if empty tree
static TNode LL_rotation (TNode root);
static TNode RR_rotation (TNode root);
static TNode LR_rotation (TNode root);
static TNode RL_rotation (TNode root);
static TNode balance (TNode temp);
//static int abs(int x);

/*-------------------------------------------------*/

tree::tree():size(0), root(nullptr){}

void* tree::Add(int key, void* value) {
    TNode new_tnode = new tnode(key, value);
    root = Add_aux(root, new_tnode);
    size++;
    return new_tnode;
}

static TNode Add_aux(TNode root, TNode new_tnode) {

    if (!root) {
        root = new_tnode;
        return root;
    } else if (root->key < new_tnode->key) {
        root->right = Add_aux(root->right, new_tnode);
        //insert(root->right, new_tnode);

        root = balance(root);
        root->height = max(height(root->left), height(root->right)) + 1;

    } else if (root->key > new_tnode->key) {
        root->left = Add_aux(root->left, new_tnode);
        root = balance(root);
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;

}

static TNode balance (TNode temp){

    int b_factor = bf_calc(temp);

    if (b_factor == 2){
        if (bf_calc(temp->left) == 1)
            temp = LL_rotation(temp);
        else
            temp = LR_rotation(temp);
    }
    else if (b_factor == -2){
        if (bf_calc(temp->right) == -1)
            temp = RR_rotation(temp);
        else
            temp = RL_rotation(temp);
    }
    return temp;
}

static TNode LL_rotation (TNode root){
    TNode new_root = root->left;

    //update height
    //update parent

    root->height--;
    if(new_root)
        (new_root)->height++;

    TNode temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;

    return temp;
}

static TNode RR_rotation(TNode root){
    TNode new_root = root->right;

    //update height
    root->height--;

    if(new_root)
        (new_root)->height++;


    TNode temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

static TNode LR_rotation(TNode root){
    TNode temp;
    temp = root->left;
    root->left = RR_rotation(temp);
    return LL_rotation(root);
}

static TNode RL_rotation(TNode root){
    TNode temp;
    temp = root->right;
    root->right = LL_rotation(temp);
    return RR_rotation(root);
}

static int bf_calc (TNode node){
    return (height(node->left)-height(node->right));
}

void* tree::Find(int key){
    return (((TNode)(Find_node(root, key)))->value);
}

static void* Find_node(TNode root,int key){
    if (!root) return nullptr;

    if (key == root->key){
        return root;
    }

    else if (key < root->key)
        return Find_aux(root->left ,key);

    else if (key > root->key)
        return Find_aux(root->right ,key);

}

void* tree::Delete(int key){
    //return(DeleteByPointer(Find(key)));
    if (!Find(key))
        return nullptr;

    root = Delete_aux(key, this->root);
    size--;
    if(size == 0) root = nullptr;
    return this;
}

static TNode Delete_aux(int key, TNode root) {
    //node isnt in the tree
    if (!root) return nullptr;

    //search node
    else if (key < root->key)
        root->left = Delete_aux(key, root->left);
    else if (key > root->key)
        root->right = Delete_aux(key, root->right);

    //node found!

    // If node has 2 kids

    else if (root->right && root->left) {
        TNode min = findMin(root->right);
        copy_min_values(min, root);
        root->right = Delete_aux(root->key, root->right);
    }

        // If node has one child or none

    else {
        TNode temp = root;
        if (!root->left)
            root = root->right;
        else if (!root->right)
            root = root->left;
        delete (temp);
    }
    if (!root) return nullptr;


    root->height = max(height(root->left), height(root->right))+1;

    root = balance(root);

    return root;

}

static void copy_min_values (TNode min, TNode root) {

    root->key = min->key;
    root->value = min->value;
}

void* tree::DeleteByPointer(void* to_delete) {
    if (!to_delete) return nullptr;
    return (Delete(((TNode)to_delete)->key));
}

static TNode findMin(TNode node){
    if(!node) return nullptr;
    if(!node->left) return node;
    return findMin(node->left);
}

int tree::Size(){
    return size;
}

void tree::Quit(){
    Quit_aux(this->root);
    delete(this);
}

static void Quit_aux(TNode node){
    if (!node) return;
    Quit_aux(node->left);
    Quit_aux(node->right);
    delete(node);
}

static int max(int a, int b){
    return (a>b? a : b);
}

static int height(TNode tnode){
    if (!tnode) return -1;
    return tnode->height;
}

bool tree::is_empty(){
    return (root == nullptr);
}


/*---------------- functions for tests ------------------*/



void tree::display(TNode ptr, int level) {
    int i;
    if (!ptr) return;

    display(ptr->right, level + 1);
    printf("\n");
    if (ptr == root)
        cout << "Root -> ";
    for (i = 0; i < level && ptr != root; i++)
        cout << "        ";
        cout << ptr->key;

    display(ptr->left, level + 1);

}

bool tree::is_balanced(TNode n){
    if (!n) return true;

    if (((abs(height(n->left) - height(n->right))) <= 1 )&&
        is_balanced(n->left) &&
        is_balanced(n->right))
        return true;
    return false;
}

