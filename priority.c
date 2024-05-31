#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node *link;
}*head = NULL;
void enqueue(int data, int priority){
    struct node *newNode, *temp = NULL;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    newNode->priority = priority;

    if (head == NULL || priority<head->priority)
    {
        newNode->link = head;
        head = newNode;
    }
    else{
        temp = head;
        while (temp != NULL && temp->link->priority <= priority)
        {
            temp = temp->link;
            newNode->link = temp->link;
            temp = newNode;
        }
    }
}
void dequeue(){
    struct node *temp;
    temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
}
void display(){
    struct node *temp = head;
    while (temp != NULL)
    {
        /* code */
    }
    
}