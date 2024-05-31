#include<stdio.h>
#define Max 10
int stackarr[Max];
int top = -1;
void push(int data){
    top++;
    stackarr[top] = data;
}
void pop(){
    int value;
    value = stackarr[top];
    top--;
}
void display(){
    int temp;
    temp = top;
    while (temp != -1)
    {
        printf("%d\n",stackarr[temp]);
        temp--;
    }
}
int main(){
    push(1);
    push(2);
    push(3);
    pop();
    display();
}