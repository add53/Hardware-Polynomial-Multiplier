#include <stdio.h>
#include <stdlib.h>

#define MOD 17   // Modulus, a prime number
#define ROOT 3   // Primitive root, nth root of unity
#define N 4      // Size of the input vector

// Function to calculate (a * b) % mod
int mod_mult(int a, int b, int mod) {
    return (a * b) % mod;
}

// Function to calculate a^b % mod
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mod_mult(result, base, mod);
        }
        base = mod_mult(base, base, mod);
        exp /= 2;
    }
    return result;
}

// Perform the NTT transformation
void NTT(int *a, int *A, int n, int root, int mod) {
    int w = mod_exp(root, (mod - 1) / n, mod);
    for (int i = 0; i < n; i++) {
        A[i] = 0;
        for (int j = 0; j < n; j++) {
            int power = (i * j) % n;
            int w_power = mod_exp(w, power, mod);
            A[i] = (A[i] + mod_mult(a[j], w_power, mod)) % mod;
        }
    }
}

// Perform the inverse NTT transformation
void inverse_NTT(int *A, int *a, int n, int root, int mod) {
    int w = mod_exp(root, (mod - 1) / n, mod);
    int w_inv = mod_exp(w, mod - 2, mod);
    for (int i = 0; i < n; i++) {
        a[i] = 0;
        for (int j = 0; j < n; j++) {
            int power = (i * j) % n;
            int w_power = mod_exp(w_inv, power, mod);
            a[i] = (a[i] + mod_mult(A[j], w_power, mod)) % mod;
        }
        a[i] = mod_mult(a[i], mod_exp(n, mod - 2, mod), mod);
    }
}


void poly_mult(int *A, int *B, int *C, int n, int mod) {
    for (int i = 0; i < n; i++) {
        C[i] = mod_mult(A[i], B[i], mod);
    }
}

int main() {
    int a[N], b[N];

    printf("Enter the coefficients for the first polynomial:\n");
    for (int i = 0; i < N; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter the coefficients for the second polynomial:\n");
    for (int i = 0; i < N; i++) {
        printf("b[%d]: ", i);
        scanf("%d", &b[i]);
    }

    int A[N], B[N];
    int inv_c[N];
    int C[N];


    NTT(a, A, N, ROOT, MOD);
    NTT(b, B, N, ROOT, MOD);


    poly_mult(A, B, C, N, MOD);


    inverse_NTT(C, inv_c, N, ROOT, MOD);

    printf("Result of polynomial multiplication:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", inv_c[i]);
    }
    printf("\n");

    return 0;
}