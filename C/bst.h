
/*==============================================================================================
 |       Author:  Darrin McAdams
 |         Date:  January 18, 2019
 |     Language:  C
 |    File Type:  .h
 |  Description:  This is an implementation of a Binary Search Tree (bst). 
 | 
 *==============================================================================================*/

#ifndef BST_H
#define BST_H
#include<stdlib.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
//the main structure of the binary search tree
struct node{
    int key;
    struct node *left;
    struct node *right;   
};

//create a new node based 
struct node *createNode(int key){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

    
//insert a node into the binary search tree. Uses recursion to find a suitable location for the key.
struct node *insert(struct node *head, int key){
    
    //if head is empty
    if (head == NULL){
        //replace head with new node
        head = createNode(key);
        return head;
    }
    
    //if key is smaller than or equal to the value of the head
    if (key <= head->key){
        head->left = insert(head->left, key);
    }
    //else key is larger than the value of the head
    else{
        head->right = insert(head->right, key);
    }

    return head;

    
}

 /*
    Search a tree recursively. 
    This function is not ment to be called directly, use search() instead.
 */ 
 int recursive_search(struct node *tree, int key){
     
     //if end of tree
     if (tree == NULL){
         return FALSE;
     }
     //else if match found
     else if (key == tree->key){
         return TRUE;
     }
     //else search left half of tree
     else if (key < tree->key){
         int temp_level = recursive_search(tree->left, key);
         //if match found
         if (temp_level != FALSE){
             return ++temp_level;
         }
     }
     //else search right half of tree
     else {
         int temp_level = recursive_search(tree->right, key);
         //if match found
         if (temp_level != FALSE){
             return ++temp_level;
         }
     }

 }
 
 //search the tree for a matching key value
 int search(struct node *tree, int key){
     //if tree is empty
     if (tree == NULL){
         return FALSE;
     }
         //else if head of tree is a match
     else if (tree->key == key){
         return TRUE;
     }
     //else search left side using the recursive search method
     else if (key < tree->key){
         int temp = recursive_search(tree->left, key);
         if (temp == FALSE)
            return FALSE;
         else return temp+1;
        
     }
     //else search right side using the recursive search method
     else if (key > tree->key){
         int temp = recursive_search(tree->right, key);
         if (temp == FALSE)
            return FALSE;
         else return temp+1;
     }
     //else match found at head of tree
     else return TRUE;
 } 
//print out the tree from left to right
void printTree(struct node *head){
    //if end of tree
    if(head == NULL)
        return;
    //else print everything to the left
    printTree(head->left);
    //then print the current node
    printf(" %d " , head->key);
    //then print out everything to the right of the node
    printTree(head->right);
}
#endif