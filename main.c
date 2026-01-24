#include <stdio.h>
#include <math.h>

// CPSC 355 A1
// Zaine Ancheta
// UCID: 30214484

// Initialize table FIRST
// Address Primes in Main Diagonal First then fill table
int table [100][100];
int prime;
int i, j, x, y;

// First 100 Primes
int primes[100] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
    419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
    467, 479, 487, 491, 499, 503, 509, 521, 523, 541
};


int search (int input) {
}

int main() {


    // User Input
    int input, prime;
    printf("Enter a Number to Search: \n");
    scanf("%d", &input);

    // Main diagonal
    for (x = 0; x<100; x++) {
        table[x][x] = primes[x];
    }

    
    // Main Table
    for(i = 0; i<100; i++) { // Rows

        if (i % 2 == 0) { // Checks if row index is even
                
        } else { // Row index Odd

        }

        for(j = 0; j<100; j++) { // Columns

        }
    }

   


    // printf(("%d", "%d")\n, i, j);

}

