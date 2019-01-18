
/*==============================================================================================
 |       Author:  Darrin McAdams
 |         Date:  January 18, 2019
 |     Language:  C
 |    File Type:  .c
 |  Description:  This program is used for testing queue.h. 
 *==============================================================================================*/

#include<stdlib.h>
#include<stdio.h>
#include"./queue.h"

int main(){
    //create queue
    struct queue *q = create();
    //output queue, should be empty
    printQueue(q);
    //testing Empty function
    if(!Empty(q))
        printf("%d\n", pop(q));
   
    //loop to fill up queue
    for(int i = 0; i < 20; i++){
        //add i to queue
        push(q, i);
        //print queue
        printQueue(q);
    }
    //remove value from queue
    printf("%d removed from queue\n", pop(q));
    //add values to queue
    push (q, 7);
    push (q, 3);

    //print queue
    printQueue(q);
    
    //empty the queue
    while(Empty){
        printf("%d removed from queue\n", pop(q));
        printQueue(q);
    }
    //done
    exit(0);
}