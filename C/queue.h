
/*==============================================================================================
 |       Author:  Darrin McAdams
 |         Date:  January 18, 2019
 |     Language:  C
 |    File Type:  .h
 |  Description:  This is an implementation of a standard FIFO queue using linked lists for C.
 |         Note:  User is responsible for checking if a queue is empty before calling pop()
 *==============================================================================================*/



#ifndef QUEUE_H
#define QUEUE_H

#include<stdlib.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0

//each node in the queue has a key and a pointer to the next node in the queue
struct node {
    //holds a data value
    int key;
    //next node in queue
    struct node *next;

};
//queue has a pointer to the first and last node
struct queue {
    struct node *front, *back;
    //holds next node in queue
    int count;
};
//creates an empty queue and returns it
struct queue* create() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->count = 0;
    return q;
};
//creates a new node from a key value and returns it
struct node* newnode(int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}
//adds a new node to the back of the queue. takes input for the new nodes' key value
void push (struct queue *q, int key){
    //create new node
    struct node *temp = newnode(key);

    //if queue is empty, set front and back to the new node
    if (q->front == NULL){
        q->front = temp;
        q->back = q->front;
    }
    //else add node to back of queue
    else {
        q->back->next = temp;
        q->back = temp;
    }
    //add one to node count
    q->count++;
}

//removes the node at the front of the queue and replaces it with the next value in line
//the removed node gets returned
int pop (struct queue *q){

    //return null if queue is empty
    if (q->front == NULL)
        exit(0);
    //remove one to node cound
    q->count--;
    //store front as temp, replace front with next node in queue
    struct node *temp = q->front;
    q->front = q->front->next;

    //if front = null, then set back = null
    if (q->front == NULL)
        q->back = NULL;

    //get key from removed node
    int key = temp->key;
    //free memory
    free(temp);

    return key;
}

//prints out contents of queue
void printQueue(struct queue *q){

    //temp node used to traverse queue and get value for each node
    struct node *temp = q->front;

    //used for formatting output
    printf(" <--");

    //loops through queue until a null value is reached
    while (temp != NULL){
        printf("%d ", temp->key);
        temp = temp->next;
    }

    //used for formatting output
    puts("<--");
}
//return TRUE if queue is empty, FALSE otherwise
int Empty(struct queue *q){
  if (q->front == NULL)
    return TRUE;
  else return FALSE;

}

#endif
