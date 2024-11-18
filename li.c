#include <stdio.h>
#include <stdlib.h>
int i,c,after,del;

struct node{
    int data;
    struct node *link;
}*start,*ptr,*prev=NULL,*temp;

void insertionatbeginning(){
    temp=malloc(sizeof(struct node));
    printf("\nEnter element: \n");
    scanf("%d",&temp->data);
    temp->link=start;
    start=temp;
}

void insertioninbetween(){
    temp=malloc(sizeof(struct node));
    printf("\nEnter element: \n");
    scanf("%d",&temp->data);
    printf("\nEnter element after which to insert: \n");
    scanf("%d",&after);
    if(start==NULL){
        printf("\nList is Empty\n");
        free(temp);
        return;
    }
    else{
        ptr=start;
        while(ptr!=NULL && ptr->data!=after){
            ptr=ptr->link;
        }
        if(ptr==NULL){
            printf("\nElement not found\n");
            return;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}

void insertionatend(){
    temp=malloc(sizeof(struct node));
    printf("\nEnter element: \n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    ptr=start;
    if(start==NULL){
        start=temp->link;
    }
    else{
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}
void deletionatbeginning(){
    ptr=start;
    if(start==NULL){
        printf("\nList is empty\n");
        return;
    }
    else if(start->link==NULL){
        start=NULL;
        free(ptr);
        return;
    }
    else{
        start=ptr->link;
        free(ptr);
        return;
    }
}

void deletioninbetween(){
    printf("\nEnter element to be deleted:\n");
    scanf("%d",&del);
    ptr=start;
    if(start==NULL){
        printf("\nList is empty\n");
        return;
    }
    else{
        while(ptr->link!=NULL && ptr->data!=del)
        {
            prev=ptr;
            ptr=ptr->link;
        }
        if(prev==NULL){
            start=prev->link;
            return;
        }
        else{
            prev->link=ptr->link;
            free(ptr);
        }
    }
}

void deletionatend(){
    ptr=start;
    if(start==NULL){
        printf("\nList is empty\n");
        return;
    }
    else{
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
    if (start==NULL){
        printf("\nList is empty\n");
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
        printf("\nMenu\n1.Insertion at Beginning\n2.Insertionin Between\n3.Insertion at end\n4.Deletion at Beginning\n5.Deletion in between\n6.Deletion at end\n7.Display\n8.Exit\n");
        printf("\nEnter Choice: \n");
        scanf("%d",&c);
        switch(c){
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