#include<stdio.h>
#include<stdlib.h>
#define Max 5
int cirque[Max];
int front = -1;
int rear = -1;
int is_empty(){
    if (front == -1)
        return 1;
        else
        return 0;
}
int is_full(){
    if((front == 0 && rear == Max-1)||(front == rear+1))
        return 1;
    else
        return 0;
}
void enqueue(int data){
    if (is_full())
    {
        printf("QUEUE ID FULL");
        exit(1);
    }
    if (rear == -1)
    {
        front = 0;
    }
    if (rear == Max-1)
    {
        rear = 0;
    }
    else{
        rear = rear+1;
    }
    cirque[rear] = data;
}

void dequeue(){
    int value;
    value = cirque[front];
    if (is_empty())
    {
        printf("QUEUE IS EMPTY");
        exit(1);
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    if (front == Max-1)
    {
        front = 0;
    }
    else{
        front = front+1;
    }
}
void display(){
    int temp;
    temp = front;
    if (front <= rear)
    {
        while (temp<=rear)
        {
            printf("%d\n",cirque[temp]);
            temp++;
        }
    }
    else{
        while(temp<=Max-1){
            printf("%d\n",cirque[temp]);
            temp++;
        }
        temp = 0;
        while (temp<=rear)
        {
            printf("%d\n",cirque[temp]);
            temp++;
        }
        
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
}