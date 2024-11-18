#include <stdio.h>
void main()
{
    int q[10], i, n, c, r = -1, f = -1;
    printf("Enter the limit");
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
            if (r >= n - 1)
            {
                printf("\nQueue Overflow");
            }
            else
            {
                r++;
                printf("\nEnter Data: ");
                scanf("%d", &q[r]);
                if (f == -1)
                {
                    f = 0;
                }
            }
        }
        break;
        case 2:
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
                else
                    f++;
            }
        }
        break;
        case 3:
        {
            if (f == -1)
            {
                printf("Queue Underflow");
            }
            else
            {
                for (i = f; i <= r; i++)
                {
                    printf("%d", q[i]);
                }
            }
        }
        break;
        default:
            break;
        }
    } while (c != 4);
}