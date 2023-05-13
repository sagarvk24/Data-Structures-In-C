#include <stdio.h>
#define N 50
int queue[N];
int front = -1 ;int rear = -1;

void enqueue(int val)
{
    if (rear==N-1)
        printf("OVERFLOW. Queue is already full.");
    else{
        if (front==-1 && rear==-1)
        {
            front=rear=0;
            queue[rear]=val;
        }
        else{
            rear++;
            queue[rear]=val;
        }
    }
}

void dequeue(){
    if(front==-1 && rear==-1)
    printf("Queue is empty!!");
    else{
        if(front==rear)
        front=rear=-1;
        else{
            printf("%d element has been dequeued from the queue!", queue[front]);
            front++;
        }
    }
}

void




















int main(){
    
}