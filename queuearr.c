#include<stdio.h>
#define Max 10
int queuearr[Max];
int front = -1;
int rear = -1;
void enqueue(int data){
    if(rear == -1){
        front = rear = 0;
    }
    queuearr[rear] = data;
    rear++;
}
void dequeue(){
    int value;
    value = queuearr[front];
    front++;
}
void display(){
    int temp;
    temp = front;
    while (temp <= rear - 1)
    {
        printf("%d\n", queuearr[temp]);
        temp++;
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
}