#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head = NULL,*tail = NULL;
void insert_at_beg(int data){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else{
        newNode ->link = head;
        head = newNode;
        tail->link = head;
    }
}
void insert_at_end(int data){
struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else{
        tail->link = newNode;
        tail = newNode;
        tail->link = head;
    }
}
void insert_at_pos(int data, int pos){
    struct node *newNode,*temp,*temp1;
    newNode = malloc(sizeof(struct node));
    newNode ->data = data;
    newNode ->link = NULL;
    temp = head;
    while (pos != 1)
    {
        temp = temp->link;
        pos--;
    }
    temp1 = temp->link;
    temp->link = newNode;
    newNode->link = temp1;
}
void del_at_beg(){
    struct node *temp = head;
    head = head->link;
    tail->link = head;
    free(temp);
    temp = NULL;
}
void del_at_end(){
    struct node *temp = head, *temp1;
    while (temp->link != tail)
    {
        temp = temp->link;
    }
    temp1 = temp->link;
    free(temp1);
    temp1 = NULL;
    temp->link = head;
}
void del_at_pos(int pos){
    struct node *temp = head,*prev;
    while (pos != 1)
    {
        prev = temp;
        temp = temp->link;
        pos--;
    }
    prev->link = temp->link;
    free(temp);
    temp = NULL;
    
}
void display(){
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->link;
        if (temp == head)
        {
            break;
        }
    }
}
int main(){
    insert_at_beg(1);
    insert_at_beg(2);
    insert_at_end(10);
    insert_at_pos(4, 1);
    del_at_pos(2);
    display();
}