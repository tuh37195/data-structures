/*==============================================================================================
 |       Author:  Darrin McAdams
 |         Date:  January 18, 2019
 |     Language:  C
 |    File Type:  .c
 |  Description:  This is a program for testing the binary search tree header. 
 | 
 *==============================================================================================*/
#include"./bst.h"
#define TRUE 1
#define FALSE 0
 
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

 void search_test(struct node *tree, int key){
     int level = search(tree, key);
     if (level == FALSE){
         printf("%d not found in tree\n", key);
     }
     else printf("%d found on level %d\n", key, level);
 }
 int main(){
     //create the start of the tree
     struct node *tree = createNode(50);
     //print the tree
     printTree(tree);
     puts("");
     //add a bunch of values
     insert(tree, 20);
     insert(tree, 30);
     insert(tree, 20);
     insert(tree, 65);
     insert(tree, -12);
     insert(tree, -2);
     insert(tree, 60);
     //print out the tree
     printTree(tree);
/*
    tree should look like this:
                  50
          20              65
      20     30       60
 -12
     -2

*/
     
 puts("");
     
     //used for searching tree
     search_test(tree, 50);
     search_test(tree, -12);
     search_test(tree, -1000);
     search_test(tree, 65);
     search_test(tree, 60);
     search_test(tree, 90);

 }