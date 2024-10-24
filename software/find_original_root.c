#include <stdio.h>
#include <stdbool.h>


int mod_exp(int a, int b, int mod) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

// Function: Check if g is a primitive root modulo q
bool is_primitive_root(int g, int q) {
    bool found[q];
    for (int i = 0; i < q; i++) found[i] = false;


    for (int i = 0; i < q - 1; i++) {
        int res = mod_exp(g, i, q);
        if (found[res]) return false;
        found[res] = true;
    }
    return true;
}

// Function: Find and return the smallest primitive root modulo q
int find_primitive_root(int q) {
    for (int g = 2; g < q; g++) {
        if (is_primitive_root(g, q)) {
            return g;  // Return the first primitive root found
        }
    }
    return -1;  // Return -1 if no primitive root is found
}

int main() {
    int q;

    // Input the prime number q (modulus)
    printf("Enter a prime number (modulus): ");
    scanf("%d", &q);

    // Find and output the smallest primitive root
    int root = find_primitive_root(q);
    if (root != -1) {
        printf("The smallest primitive root modulo %d is: %d\n", q, root);
    } else {
        printf("No primitive root found.\n");
    }

    return 0;
}
