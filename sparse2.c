#include <stdio.h>
void main()
{
    int a[10][10], b[10][10], i, j, k, count, r, c;
    printf("Enter the rows and columns of the matrix: ");
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
    printf("Sparse matrix is : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    k = 1;
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = count;
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
    printf("Effective matrix is : \n");
    for (i = 0; i <= count; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}