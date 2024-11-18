#include <stdio.h>
int i, j, q[10], n, c, c2, f = -1, r = -1;
void irear(int n)
{
    if ((f == 0 && r == n - 1) || (f == r + 1))
    {
        printf("Queue Overflow");
    }
    else
    {
        if (r == n - 1)
        {
            r = 0;
        }
        else if (f == -1)
        {
            f = 0;
            r = 0;
        }
        else
        {
            r++;
        }
        printf("\nEnter data: ");
        scanf("%d", &q[r]);
    }
}
void ifront(int n)
{
    if ((r == 0 && f == n - 1) || (r == f + 1))
    {
        printf("Queue Overflow");
    }
    else
    {
        if (f == n - 1)
        {
            f = 0;
        }
        else if (r == -1)
        {
            f = 0;
            r = 0;
        }
        else
        {
            f++;
        }
        printf("\nEnter data: ");
        scanf("%d", &q[f]);
    }
}

void dfront(int n)
{
    if (f == -1)
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("%d has been deleted", q[f]);
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else if (f == n - 1)
        {
            f = 0;
        }
        else
        {
            f++;
        }
    }
}

void drear(int n)
{
    if (r == -1)
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("%d has been deleted", q[r]);
        if (r == f)
        {
            f = -1;
            r = -1;
        }
        else if (r == n - 1)
        {
            r = 0;
        }
        else
        {
            r++;
        }
    }
}

void display(int n)
{
    if (f < r)
    {
        for (i = f; i <= r; i++)
        {
            printf("%d", q[i]);
        }
    }
    else
    {
        for (i = 0; i <= n - 1; i++)
        {
            printf("%d", q[i]);
        }
        for (i = 0; i <= n - 1; i++)
        {
            printf("%d", q[i]);
        }
    }
}

void main()
{
    printf("\nEnter the limit");
    scanf("%d", &n);
    do
    {
        printf("\nMenu\n1.Input restricted Deque \n2.Output Restricted Deque\n3");
        printf("Enter choice");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            do
            {
                printf("\nMenu\n1.Insertion through rear \n2.Deletion through rear\n3. Deletion through front\n4.Display\n5. Exit");
                printf("Enter choice");
                scanf("%d", &c2);
                switch (c2)
                {
                case 1:
                {
                    irear(n);
                }
                break;
                case 2:
                {
                    drear(n);
                }
                break;
                case 3:
                {
                    dfront(n);
                }
                break;
                case 4:
                {
                    display(n);
                }
                break;
                default:
                    break;
                }
            } while (c2 != 5);
        }
        break;
        case 2:
        {
            do
            {
                printf("\nMenu\n1.Insertion through rear \n2.Insertion through front\n3. Deletion through front\n4.Display\n5. Exit");
                printf("Enter choice");
                scanf("%d", &c2);
                switch (c2)
                {
                case 1:
                {
                    irear(n);
                }
                break;
                case 2:
                {
                    ifront(n);
                }
                break;
                case 3:
                {
                    dfront(n);
                }
                break;
                case 4:
                {
                    display(n);
                }
                break;
                default:
                    break;
                }
            } while (c2 != 5);
        }
        break;
        }
    } while (c != 3);
}