#include <stdio.h>
#include <stdlib.h>

#define N 8
#define Q 13

int* conv(int* poly1, int* poly2, int n1, int n2)
{
    int* convolution = (int *) malloc(sizeof(int) * (n1*n2-1));
    for (int i = 0; i < n2+n1-1; i++)
    {
        convolution[i] = 0;
        for (int j = 0; j < n2; j++)
        {
            if (i-j >= 0 && i-j < n2)
            {
                convolution[i] += poly1[j]*poly2[i-j];
            }
        }
    }
    return convolution;
}

int mod(int x, int q)
{
    return x >= 0 ? x % q : q + (x % q);
}

void poly_mod(int* poly, int degree, int q)
{
    for (int i = 0; i < degree+1; i++)
    {
        poly[i] = mod(poly[i], q);
    }
}

int* negacyclic_conv(int* poly, int degree, int n) {
    int* remainder = (int *) calloc(sizeof(int), n);

    for (int i = n; i <= degree; i++) {
        poly[i - n] -= poly[i];
        poly[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        remainder[i] = poly[i];
    }

    return remainder;
}

int main()
{
    int degree_c = N + N - 2;
    int degree_r = N-1;

    int a[N] = {9, 12, 6, 6, 12, 10, 4, 9};
    int b[N] = {7, 10, 11, 3, 4, 6, 1, 2};

    int* c = conv(a, b, N, N);
    poly_mod(c, degree_c, Q);

    int* remainder = negacyclic_conv(c, degree_c, N);
    poly_mod(remainder, degree_r, Q);
    
    for (int i = 0; i < degree_r+1; i++)
    {
        printf("%d, ", remainder[i]);
    }
    printf("\n");

    return 0;
}