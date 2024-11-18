#include <stdio.h>
int top=-1,i,j,n,c,a[5];
void push(int n){
    if (top>=n-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        printf("Enter data: ");
        scanf("%d",&a[top]);
    }
}

void pop(int n){
    if(top==-1)
    {
        printf("\nStack Underflow");
    }
    else{
        printf("%d has been deleted",a[top]);
        top--;
    }
}

void display(){
    if(top==-1)
    {
        printf("\nStack Underflow");
    }
    else{
        for (i=top;i>=0;i--)
        {
            printf("%d",a[i]);
        }
    }
}

void main(){
    printf("Enter the limit");
    scanf("%d",&n);
    do{
        printf("\nMenu\n1.Push\n2.pop\n3.display\n4.exit");
        printf("\nEnter the choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                push(n);
                break;
            }
            case 2:
            {
                pop(n);
                break;
            }
            case 3:
            {
                display();
                break;
            }
            default:
                break;
        }
    }while (c!=4);
    


}