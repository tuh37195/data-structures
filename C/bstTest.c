/*==============================================================================================
 |       Author:  Darrin McAdams
 |         Date:  January 18, 2019
 |     Language:  C
 |    File Type:  .c
 |  Description:  This is a program for testing the binary search tree header. 
 | 
 *==============================================================================================*/
#include"./bst.h"
 
 void search_test(struct node *tree, int key){
     //hold level key was found on
     int found = search(tree, key);
     //if no match found
         if (found == -1){
         printf("%d not found\n", key);
     }
     //else match found
     else 
        printf("%d found at level %d\n", key, found);

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