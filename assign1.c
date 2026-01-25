#include <stdio.h>
#include <stdbool.h>

// CPSC 355 A1
// Zaine Ancheta
// UCID: 30214484

// Initialize table FIRST
// Address Primes in Main Diagonal First then fill table

const int COUNT = 100;

int table [100][100];
int prime;

int i, j, x, y, z; // Iteration variables

int even = 0;
int odd = 1;
bool is_even = true;


// First 100 Prime Numbers
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

void init_table () {

    even = 0;
    odd  = 1;

    // Main diagonal
    for (z = 0; z < COUNT; z++) {
        table[z][z] = primes[z];
    }

    // Main Table
    // Positive Rows
    for(i = 0; i < COUNT; i = i + 2) { 

        for(j = 0; j < COUNT; j++) {
            if (i != j) { // Detects Main Diaganol Pair, we skip the pair
                table[i][j] = even;
                even = even + 2;
            }
            
        }
    }

    // Negative Rows
    for (x = 1; x < COUNT; x = x + 2) {

        for (y = 0; y < COUNT; y++) {
            if (x != y) {
                table[x][y] = odd;
                odd = odd + 2;
            }
        }
    }
}

int search (int input) { // Return coordinates

    int og_input = input;
    
    int mul_count = 0; // Sets counter for amount of multiple

    for (i = 0; i < COUNT; i++) {
        for (j = 0; j < COUNT; j++) {
            if (input == table[i][j]) {
                mul_count++;
                printf("(%d, %d) = %d\n", i, j, input);
                input = input + og_input; // Next multiple
            } else {
                continue;
            }
        }
    }
    return mul_count;
}

int main() {

    int input, mul_count;
    int run = true;
    int run_input;

    init_table();

    while (run) {

    printf("Enter a Number to Search: ");
    scanf("%d", &input);

    mul_count = search(input);

    printf("Multiple(s) of %d Found: %d\n", input, mul_count);
    printf("Input a new number? (1 = Yes / 0 = No): \n");
    scanf("%d", &run_input);

    if (run_input == 0) {
        printf("Program Stopped!");
        run = false;
        break;
    } else {
        printf("\n");
        continue;
    }
    
    }

}

