#include <stdio.h>
struct poly{
    int coeff;
    int exp;
};

void main(){
    struct poly p[10], p2[10], p3[20], temp;
    int m, n, i, j, k = 0;

    printf("Enter the number of terms for first poly: ");
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        printf("Enter coeff and expo: ");
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }

    // Sort first polynomial by exponent in descending order
    for(i = 0; i < m-1; i++) {
        for(j = 0; j < m-i-1; j++) {
            if(p[j].exp < p[j+1].exp) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    printf("Enter the number of terms for second poly: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter coeff and expo: ");
        scanf("%d%d", &p2[i].coeff, &p2[i].exp);
    }

    // Sort second polynomial by exponent in descending order
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(p2[j].exp < p2[j+1].exp) {
                temp = p2[j];
                p2[j] = p2[j+1];
                p2[j+1] = temp;
            }
        }
    }

    // Add polynomials
    i = 0;  // Index for first polynomial
    j = 0;  // Index for second polynomial
    k = 0;  // Index for resultant polynomial

    while(i < m && j < n) {
        if(p[i].exp == p2[j].exp) {
            p3[k].coeff = p[i].coeff + p2[j].coeff;
            p3[k].exp = p[i].exp;
            i++;
            j++;
        }
        else if(p[i].exp > p2[j].exp) {
            p3[k].coeff = p[i].coeff;
            p3[k].exp = p[i].exp;
            i++;
        }
        else {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
        }
        k++;
    }

    // Copy remaining terms of first polynomial
    while(i < m) {
        p3[k].coeff = p[i].coeff;
        p3[k].exp = p[i].exp;
        i++;
        k++;
    }

    // Copy remaining terms of second polynomial
    while(j < n) {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }

    printf("Resultant polynomial: ");
    for(i = 0; i < k; i++) {
        if(i != 0 && p3[i].coeff > 0)
            printf("+");
        printf("%dx^%d", p3[i].coeff, p3[i].exp);
    }
    printf("\n");
}