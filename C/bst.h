
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
    if (key < head->key){
        head->left = insert(head->left, key);
    }
    //else key is larger than the value of the head
    else{
        head->right = insert(head->right, key);
    }

    return head;

    
}

//returns level of node if match is found, else returns -1
int search(struct node *head, int key){
    
    //if end of tree
    if(head == NULL){
        return -1;
    }
    //if key would be found to the right of the current node
    else if (key > head->key){
        //check right side
        int temp = search(head->right, key);
        //if match is found, increment count
        if (temp != -1){
            return ++temp;
        }
        //else return -1
        else return temp;
    }
    //if key would be found to the left of the current node
    else if (key < head->key){
        //check right side
        int temp = search(head->left, key);
        //if match is found, increment count
        if (temp != -1){
            return ++temp;
        }
        else return temp;
    }
    else if (key == head->key){
        return 1;
    }
    

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