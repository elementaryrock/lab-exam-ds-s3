#include <stdio.h>
#include <stdlib.h>
int i,j,top,c;
struct node{
    int data;
    struct node *link;
}*start,*temp,*ptr;

void push(){
    temp=malloc(sizeof(struct node));
    printf("\nEnter element: \n");
    scanf("%d",&temp->data);
    temp->link=start;
    start=temp;
}

void pop(){
    if(start==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    ptr=start;
    if(start->link==NULL){
        start=NULL;
        free(ptr);
        return;
    }
    else{
        start=ptr->link;
        free(ptr);
    }
}

void display(){
    if(start==NULL){
        printf("\nList is empty\n");
        return;
    }
    else{
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->link;
        }
    }
}
void main(){
    do{
        printf("\nMenu\n1.Push\n2.Pop\n3.Display\n");
        printf("\nEnter choice: \n");
        scanf("%d",&c);
        switch(c){
            case 1:
            {
                push();
            }break;
            case 2:
            {
                pop();
            }break;
            case 3:
            {
                display();
            }break;
        }
    }while(c!=4);
}