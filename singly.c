#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
}*head = NULL,*tail = NULL;

void insert_at_beg(int data)
{
    struct node* newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    
    if(head == NULL)
    {
        head = tail = newNode;
    }
    else{
    newNode->link = head;
    head = newNode;
    }
}

void insert_at_end(int data)
{
    struct node* newNode;
    newNode = malloc(sizeof(struct node));
    newNode->link = NULL;
    newNode->data = data;
    
    if(tail == NULL){
        head = tail = newNode;
    }
    else{
    tail->link = newNode;
    tail = newNode;
    }
}

void delete_at_beg()
{
    // if(head == NULL)
    // {
    //     printf("List is empty\n");
    //     return;
    // }
    struct node* temp;
    temp = head;
    head= head->link;
    free(temp);
    temp = NULL;
}

void delete_at_end()
{
    // if(head == NULL || tail == NULL)
    // {
    //     printf("List is empty\n");
    //     return;
    // }
    struct node* temp,*temp1;
    temp = head;
    while(temp->link != tail)
    {
        temp = temp->link;
    }
    temp1 = temp->link;
    free(temp1);
    temp->link = NULL;
    tail = temp;
}

void display()
{
    struct node* temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d",temp->data);
        printf("\n");
        temp=temp->link;
    }
}
void insert_at_pos(int data,int pos)
{
    struct node* temp,*newNode,*temp1;
    newNode = malloc(sizeof(struct node));
    newNode->link = NULL;
    newNode->data = data;
    temp = head;
    while(pos!=1)
    {
        temp = temp->link;
        pos--;
    }
    temp1 = temp->link;
    temp->link = newNode;
    newNode->link = temp1;
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
void count()
{
    int count = 0;
    struct node* temp;
    temp = head;
    do
    {
        count ++;
        temp = temp->link;
    } 
    while (temp != NULL);
    {
        printf("the total number of nodes are :%d",count);
    }
    
}
void reverse(){
    struct node *prev,*next;
    while (head!=NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
}
void find_max(){
    int max = 0;
    struct node *temp;
    temp = head;
    while(temp!=NULL){
    if (temp->data>max)
        {
            max = temp->data;
        }
        temp = temp->link;
    }
    printf("The Maximun Number in list is : %d",max);
}

int main()
{
    int data;
    insert_at_beg(1);
    insert_at_beg(100);
    insert_at_beg(2);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(15);
    insert_at_pos(78,2);
    insert_at_pos(79, 3);
    delete_at_end();
    reverse();
    display();
    find_max();
    count();
    
    return 0;
}