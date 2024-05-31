#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head = NULL,*tail = NULL;
void insert_at_beg(int data){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insert_at_end(int data){
        struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insert_at_pos(int data, int pos){
    struct node *newNode,*temp,*temp1;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    temp = head;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    temp1 = temp->next;
    temp->next = newNode;
    newNode->next = temp1;
    newNode->prev = temp;
}
void del_at_beg(){
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
}
void del_at_end(){
    struct node *temp;
    temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
    temp = NULL;
}
void display(){
    struct node *temp = head;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
};
int main (){
    insert_at_beg(2);
    insert_at_beg(1);
    insert_at_beg(5);
    insert_at_beg(8);
    insert_at_end(3);
    del_at_beg();
    del_at_end();
    insert_at_pos(4, 1);
    display();
}