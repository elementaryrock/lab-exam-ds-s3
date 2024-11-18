#include <stdio.h>
struct poly{
    int coeff;
    int exp;
};
void main(){
    struct poly p[5],temp;
    int n,i,j;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter coeff and expo: ");
        scanf("%d%d",&p[i].coeff,&p[i].exp);
    }
    for (i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if (p[j].exp<p[j+1].exp)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%dx^%d",p[i].coeff,p[i].exp);
        if(i!=n-1)
        {
            printf("+");
        }
    }
    
}