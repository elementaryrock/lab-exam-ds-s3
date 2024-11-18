#include <stdio.h>
int i, q[10], n, c, f = -1, r = -1;

void enque(int n)
{
    if ((f == 0 && r == n - 1) || f == r + 1)
    {
        printf("Queue overflow");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
            r = 0;
        }
        else if (r == n - 1)
        {
            r = 0;
        }
        else
        {
            r++;
        }
        printf("Enter data: ");
        scanf("%d", &q[r]);
    }
}

void deque(int n)
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

void display()
{
    if (f == -1)
    {
        printf("Queue is empty");
        return;
    }

    if (f <= r)
    {
        for (i = f; i <= r; i++)
        {
            printf("%d ", q[i]);
        }
    }
    else
    {
        for (i = f; i < n; i++)
        {
            printf("%d ", q[i]);
        }
        for (i = 0; i <= r; i++)
        {
            printf("%d ", q[i]);
        }
    }
}

void main()
{
    printf("Enter the limit: ");
    scanf("%d", &n);
    do
    {
        printf("\nMenu\n1.Enque\n2.Deque\n3.Display\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            enque(n);
        }
        break;

        case 2:
        {
            deque(n);
        }
        break;

        case 3:
        {
            display();
        }
        break;

        default:
            break;
        }
    } while(c!=4);
}