#include <stdio.h>
void main()
{
    int top = -1, a[10], c, n, i;
    printf("Enter the limit: ");
    scanf("%d", &n);
    do
    {
        printf("\nMenu\n1.Push\n2.Pop\n3.display\n4.exit");
        printf("\nEnter choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if (top >= n - 1)
            {
                printf("\nStack Overflow");
            }
            else
            {
                top++;
                printf("\nEnter the data: ");
                scanf("%d", &a[top]);
            }
            break;

        case 2:
        {
            if (top == -1)
            {
                printf("\nStack Underflow");
            }

            else
            {
                printf("\n%d has been deleted", a[top]);
                top--;
            }
        }
        break;
        case 3:
        {
            if (top == -1)
            {
                printf("\nStack Underflow");
            }
            for (i = top; i >= 0; i--)
            {
                printf("%d", a[i]);
            }
        }
        break;
        default:
            break;
        }
    } while (c != 4);
}