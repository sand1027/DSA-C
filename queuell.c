#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*front = NULL,*rear = NULL;
void enqueue(int data){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    rear->link = newNode;
    rear = newNode;
}
void dequeue(){
    struct node *temp = front;
    front = front->link;
    free(temp);
    temp = NULL;
}
void display(){
    struct node *temp = front;
    while ( temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->link;
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    display();
}