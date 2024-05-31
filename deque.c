#include<stdio.h>
#include<stdlib.h>
#define Max 5
int deque[Max];
int front = -1;
int rear = -1;
int is_empty(){
    if(front == -1)
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
void enqueue_at_rear(int data){
    if(rear == -1){
        front = 0;
    }
    if (rear == Max-1)
    {
        rear = 0;
    }
    else{
        rear = rear+1;
    }
    deque[rear] = data;
}
void enqueue_at_front(int data){
    if (front = -1)
    {
        rear = 0;
        front = 0;
    }
    if (front = 0)
    {
        front = Max-1;
    }
    else{
        front = front-1;
    }
    deque[front] = data;
}
    void dequeue_at_rear(){
        int value;
        value = deque[rear];
        if (front == rear)
        {
            front = rear = -1;
        }
        
        if (rear == 0)
        {
            rear = Max-1;
        }
        else{
            rear = rear-1;
        }
    }
    void dequeue_at_front(){
        int value;
        value = deque[front];
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
        while (temp <= rear)
        {
            printf("%d\n",deque[temp]);
            temp++;
        }
    }
    else{
        while(temp <= Max-1)
        {
            printf("%d\n",deque[temp]);
            temp++;
        }
        temp = 0;
        while (temp<=rear)
        {
            printf("%d\n",deque[temp]);
            temp++;
        }
    }
}
int main(){
    enqueue_at_rear(1);
    enqueue_at_front(5);
    enqueue_at_rear(6);
    dequeue_at_front();
    dequeue_at_rear();
    display();
}
    