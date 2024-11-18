#include <stdio.h>
#include <stdlib.h>
int i, n;
struct poly
{
    int coeff;
    int exp;
    struct poly *link;
} *start, *start1, *start2, *start3, *ptr, *ptr1, *ptr2, *ptr3, *temp;

struct poly *Create()
{
    start = NULL;
    printf("\nEnter the no of terms: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        temp = malloc(sizeof(struct poly));
        printf("\nEnter the coeff and expo: \n");
        scanf("%d%d", &temp->coeff, &temp->exp);
        temp->link = NULL;
        if ((start == NULL) || (start->exp < temp->exp))
        {
            temp->link = start;
            start = temp;
        }
        else
        {
            ptr = start;
            while (ptr->link != NULL && ptr->link->exp >= temp->exp)
            {
                ptr = ptr->link;
            }
            temp->link = ptr->link;
            ptr->link = temp;
        }
    }
    return start;
}

void main()
{
    start1 = Create();
    start2 = Create();
    start3 = NULL;
    ptr1 = start1;
    ptr2 = start2;
    ptr3 = start3;

    printf("\nThe first polynomial is: \n");
    while (ptr1 != NULL)
    {
        printf("%dx^%d", ptr1->coeff, ptr1->exp);
        if (ptr1->link != NULL)
        {
            printf("+");
        }
        ptr1 = ptr1->link;
    }
    printf("\nThe second polynomial is: \n");
    while (ptr2 != NULL)
    {
        printf("%dx^%d", ptr2->coeff, ptr2->exp);
        if (ptr2->link != NULL)
        {
            printf("+");
        }
        ptr2 = ptr2->link;
    }
    ptr1 = start1;
    ptr2 = start2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        temp = malloc(sizeof(struct poly));
        temp->link = NULL;
        if (ptr1->exp > ptr2->exp)
        {
            temp->exp = ptr1->exp;
            temp->coeff = ptr1->coeff;
            ptr1 = ptr1->link;
        }
        else if (ptr2->exp > ptr1->exp)
        {
            temp->exp = ptr2->exp;
            temp->coeff = ptr2->coeff;
            ptr2 = ptr2->link;
        }
        else
        {
            temp->exp = ptr1->exp;
            temp->coeff = ptr1->coeff + ptr2->coeff;
            ptr2 = ptr2->link;
            ptr1 = ptr1->link;
        }
        if (start3 == NULL)
        {
            start3 = temp;
            ptr3 = start3;
        }
        else
        {
            ptr3->link = temp;
            ptr3 = temp;
        }
    }
    while (ptr1 != NULL)
    {
        temp = malloc(sizeof(struct poly));
        temp->link = NULL;
        temp->exp = ptr1->exp;
        temp->coeff = ptr1->coeff;
        ptr1 = ptr1->link;
        if (start3 == NULL)
        {
            start3 = temp;
            ptr3 = start3;
        }
        else
        {
            ptr3->link = temp;
            ptr3 = temp;
        }
    }
    while (ptr2 != NULL)
    {
        temp = malloc(sizeof(struct poly));
        temp->link = NULL;
        temp->exp = ptr2->exp;
        temp->coeff = ptr2->coeff;
        ptr2 = ptr2->link;
        if (start3 == NULL)
        {
            start3 = temp;
            ptr3 = start3;
        }
        else
        {
            ptr3->link = temp;
            ptr3 = temp;
        }
    }
    ptr3 = start3;
    printf("\nThe resultant polynomial is: \n");
    while (ptr3 != NULL)
    {
        printf("%dx^%d", ptr3->coeff, ptr3->exp);
        if (ptr3->link != NULL)
        {
            printf("+");
        }
        ptr3 = ptr3->link;
    }
}
