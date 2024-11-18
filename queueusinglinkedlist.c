#include <stdio.h>
#include <stdlib.h>
int i,c;

struct node{
    int data;
    struct node *link;
}*start,*ptr,*temp,*prev=NULL;

void enque(){
    temp=malloc(sizeof(struct node));
    printf("\nEnter element: \n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    ptr=start;
    if(start==NULL){
        start=temp;
        return;
    }
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void deque(){
    if(start==NULL){
        printf("\nList is empty\n");
        return;
    }
    ptr=start;
    if(start->link==NULL){
        free(ptr);
        start=NULL;
        return;
    }
    else{
        while(ptr->link!=NULL){
            prev=ptr;
            ptr=ptr->link;
        }
        prev->link=NULL;
        free(ptr);
    }
}

void display(){
    if(start==NULL){
        printf("Queue is empty");
        return;
    }
    else{
        ptr=start;
        while(ptr!=NULL){
            printf("%d->",ptr->data);
            ptr=ptr->link;
        }
    }
}
void main(){
    do{
        printf("\nMenu\n1.Enque\n2.Deque\n3.Display\n4.Exit\n");
        printf("\nEnter choice: \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                enque();
            }break;
            case 2:
            {
                deque();
            }break;
            case 3:
            {
                display();
            }break;
        }
    }while(c!=4);
}