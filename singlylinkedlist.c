#include <stdio.h>
#include <stdlib.h>
int c,i,after,del;

struct node {
    int data;
    struct node *link;
}*start,*ptr,*prev=NULL,*temp,*link,*q;

void insertionatbeginning(){
    temp=malloc(sizeof(struct node));
    printf("\nEnter the element: \n");
    scanf("%d",&temp->data);
    temp->link=start;
    start=temp;
}

void insertioninbetween(){
    temp=malloc(sizeof(struct node));
    printf("\nEnter the element: \n");
    scanf("%d",&temp->data);
    printf("\nEnter the element after which to insert: \n");
    scanf("%d",&after);
    ptr=start;
    if(start==NULL)
    {
        printf("\nList is empty\n");
        free(temp);
        return;
    }
    while(ptr->data!=after && ptr!=NULL)
    {
        ptr=ptr->link;
    }
    if (ptr==NULL)
    {
        printf("\nElement not found \n");
        free(temp);
        return;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    
}

void insertionatend(){
    temp=malloc(sizeof(struct node));
    printf("\nEnter the element\n");
    scanf("%d",&temp->data);
    ptr=start;
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else{
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}

void deletionatbeginning(){
    if(start==NULL){
        printf("\nList is empty\n");
    }
    else{
        ptr=start;
        start=ptr->link;
        free(ptr);
    }
}

void deletioninbetween(){
    if(start==NULL){
        printf("\nList is empty\n");
        return;
    }
    else{
        ptr=start;
        printf("\nEnter the element to delete:\n");
        scanf("%d",&del);
        while(ptr!=NULL && ptr->data!=del)
        {
            prev=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL){
            printf("\nElement not found\n");
            return;
        }
        if(prev==NULL){
            start=ptr->link;
        }
        else{
            prev->link=ptr->link;
        }
        free(ptr);
    }
}

void deletionatend(){
    if(start==NULL){
        printf("\nList is empty\n");
        return;
    }
    else{
        ptr=start;
        if(start->link==NULL){
            free(ptr);
            start=NULL;
            return;
        }
        while(ptr->link!=NULL){
            prev=ptr;
            ptr=ptr->link;
        }
        prev->link=NULL;
        free(ptr);
    }
}

void display(){
    if(start==NULL)
    {
        printf("\nList is empty\n");
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
        printf("\nMenu\n1.Insertion at Beginning\n2.Insertionin Between\n3.Insertion at end\n4.Deletion at Beginning\n5.Deletion in between\n6.Deletion at end\n7.Display\n8.Exit\n");
        printf("\nEnter Choice: \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                insertionatbeginning();
            }break;
            case 2:
            {
                insertioninbetween();
            }break;
            case 3:
            {
                insertionatend();
            }break;
            case 4:
            {
                deletionatbeginning();
            }break;
            case 5:
            {
                deletioninbetween();
            }break;
            case 6:
            {
                deletionatend();
            }break;
            case 7:
            {
                display();
            }break;
        }

    }while(c!=8);
}