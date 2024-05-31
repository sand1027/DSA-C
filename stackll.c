#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*top = NULL;
void push(int data){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    if (top == NULL)
    {
        top = newNode;
    }
    else{
    newNode->link = top;
    top = newNode;
}
}
void pop(){
    struct node *temp;
    temp = top;
    top = top->link;
    free(temp);
    temp = NULL;
}
void display(){
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->link;
    }
}
int main(){
    push(1);
    push(2);
    push(3);
    pop();
    display();
}