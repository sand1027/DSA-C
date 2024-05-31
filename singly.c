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
void del_value(int data){
struct node *temp = head,*temp2=NULL;
while (temp!=NULL && temp->data!=data)
{
    temp2=temp;
    temp = temp->link;
}
temp2->link = temp->link;
free(temp);
temp=NULL;

}
void count()
{
int count = 0;
struct node *temp;
temp = head;
while(temp!=NULL){
    count++;
    temp=temp->link;
}
printf("the number node in list is :%d\n",count);
}
void reverse() {
    struct node *prev = NULL, *next = NULL;
    while (head != NULL) {
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
    printf("The Maximun Number in list is : %d\n",max);
}
void find_mid(){
    struct node *onestep=head,*twostep=head;
    while(twostep!=NULL&&twostep->link!=NULL){
        onestep=onestep->link;
        twostep=twostep->link->link;
    }
    printf("The middle node is %d\n",onestep->data);
}

int main()
{
    int data;
    insert_at_beg(1);
    insert_at_beg(19);
    insert_at_beg(10);
    insert_at_beg(2);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(15);
    insert_at_pos(78,2);
    insert_at_pos(79, 3);
    delete_at_end();
    del_value(4);
     reverse();
    display();
    find_max();
    count();
    find_mid();
    return 0;
}
