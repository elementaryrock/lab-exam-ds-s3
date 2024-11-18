#include <stdio.h>
int i, j, n, a[10], search, c, lb, ub, mid, t;

void linear(int n, int a[10])
{
    int found = 0;
    printf("\nArray is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            printf("\nElement %d found at index %d", search, i);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\nElement not found");
    }
}

void binary(int n, int a[10])
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    printf("\nSorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    lb = 0;
    ub = n - 1;
    int found = 0;

    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (a[mid] == search)
        {
            printf("\nElement %d found at index %d", search, mid);
            found = 1;
            break;
        }
        else if (a[mid] < search)
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }

    if (!found)
    {
        printf("\nElement not found");
    }
}

void main()
{
    printf("\nEnter the limit: ");
    scanf("%d", &n);
    printf("\nEnter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    do
    {
        printf("\nEnter the element to be searched: ");
        scanf("%d", &search);
        printf("\nMenu\n1.Linear Search\n2.Binary Search\n3.Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            linear(n, a);
            break;
        case 2:
            binary(n, a);
            break;
        case 3:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice!");
            break;
        }
    } while (c != 3);
}