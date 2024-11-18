#include <stdio.h>
#include <ctype.h>
int max=20,top=-1;
char stack[20];

void push(char x){
    if (top>=max-1){
        printf("\nstack overflow\n");
        return;
    }
    stack[++top]=x;
}

char pop(){
    if(top==-1)
    {
        return -1;
    }
    return stack[top--];
}

int priority(char x){
    if (x=='(')
    {
        return 0;
    }
    if (x=='+'||x=='-')
    {
        return 1;
    }
    if (x=='*'||x=='/'||x=='%')
    {
        return 2;
    }
    if (x=='^')
    {
        return 3;
    }
    return -1;
}

int main(){
    char exp[20],*e,x;
    printf("\nEnter the expression:\n");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e=='('){
            push(*e);
        }
        else if(*e==')'){
            while((x=pop())!='('){
                printf("%c",x);
            }
        }
        else{
            while(priority(stack[top])>=priority(*e))
            {
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }
    
    while(top!=-1){
        printf("%c",pop());
    }
    printf("\n");
    return 0;
}