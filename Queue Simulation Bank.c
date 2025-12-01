//Project name: Queue Bank Simulation in C
//Step 1:To add customer and remove customer using enqueue and dequeue.

#include <stdio.h>
#define MAX 10
int customer[MAX];
int front = -1, rear = -1;
int arrived=0,served=0;

//For adding customer in bank queue
//We are using circular queue

void enqueue() 
{
    if((front == 0 && rear == MAX-1) || (rear+1)%MAX == front) 
    {
        // Condition: Queue is full
      
        printf("Queue is full\n");
    } 
    else 
    {
        int tokennumber;
        printf("Enter customer token number to add to queue: ");
        scanf("%d", &tokennumber);
        if(front == -1) front = 0;
        rear = (rear + 1) % MAX;  
        customer[rear] = tokennumber;
        printf("Customer %d added to queue\n", tokennumber);
        arrived++;
        printf("Total customers arrived:%d\n",arrived);
    }
}

// Now serve the customer who came first in queue, and then remove them from the queue afterward.

void dequeue() 
{
    if(front == -1) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        int tokennumber= customer[front];
        printf("Customer %d served and removed from queue\n", tokennumber);
        served++;
        printf("Total customers served:%d\n",served);
        if(front == rear) 
        {
       
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % MAX;
        }
    }
}


int main() 
{
    int option = 0;
    while(option!=3) 
    {
        printf("Enter 1 to add customer, 2 to serve customer, 3 to exit: ");
        scanf("%d", &option);
        switch(option) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: printf("Exiting program.\n");
            printf("---Final Summary---\n");
            printf("Total customer arrived finally:%d\n",arrived) ;
            printf("Total customer served finally:%d\n",served);
            break;
            default: printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
