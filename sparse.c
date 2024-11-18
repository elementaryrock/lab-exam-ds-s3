#include <stdio.h>
void main()
{
    int r, c, a[10][10], i, j, count = 0, b[10][10], k;
    printf("Enter the no of rows ad columns: ");
    scanf("%d%d", &r, &c);
    printf("Enter the elements");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
            {
                count++;
            }
        }
    }
    printf("The sparse Matrix is :\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = count;
    k = 1;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    printf("The Effective Matrix is :\n");
    for (i = 0; i <= count; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}
