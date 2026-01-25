#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// CPSC 355 A1
// Zaine Ancheta
// UCID: 30214484

// Variables
const int TABLE_COUNT = 100;

int table [TABLE_COUNT][TABLE_COUNT]; // Table Size Initialization (100x100)

int pos_rows, pos_cols, neg_rows, neg_cols, search_rows, search_cols, z; // Iteration variables

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

// Table Initialization Function
void init_table () {

    even = 0;
    odd  = 1;

    // Main Diagonal Initialization
    for (z = 0; z < TABLE_COUNT; z++) {
        table[z][z] = primes[z];
    }

    // Main Table Initialization

    // Positive Rows
    for(pos_rows = 0; pos_rows < TABLE_COUNT; pos_rows = pos_rows + 2) { 

        for(pos_cols = 0; pos_cols < TABLE_COUNT; pos_cols++) {
            if (pos_rows != pos_cols) { // Detects Main Diagonal Pair, we skip the pair
                table[pos_rows][pos_cols] = even;
                even = even + 2;
            }
            
        }
    }

    // Negative Rows
    for (neg_rows = 1; neg_rows < TABLE_COUNT; neg_rows = neg_rows + 2) {
        for (neg_cols = 0; neg_cols < TABLE_COUNT; neg_cols++) {
            if (neg_rows != neg_cols) {
                table[neg_rows][neg_cols] = odd;
                odd = odd + 2;
            }
        }
    }
}

// Search Function
int search (int input) {

        int mul_count = 0; 

        for (search_rows = 0; search_rows < TABLE_COUNT; search_rows++) {
            for (search_cols = 0; search_cols < TABLE_COUNT; search_cols++) {
                if (input != 0 && table[search_rows][search_cols] % input == 0) {
                    mul_count++;
                    printf("(%d, %d) = %d\n", search_rows, search_cols, table[search_rows][search_cols]);
            }
        }
    }
        return mul_count;
}

float percent_calculation (float amount) {

    float mul_percent = amount / (100.0f * 100.f) * 100.0f;
    printf("Percentage of Table: %.2f%%\n", mul_percent);

    return mul_percent;
}

int main() {

    int input, mul_count;
    float mul_percent;
    int run = true;
    int run_con;

    init_table();

    // Main Program Loop
    while (run) {

        printf("Enter a Number to Search: ");
        scanf("%d", &input);

        mul_count = search(input);
        
        percent_calculation((float)mul_count);

        printf("Multiple(s) of %d Found: %d\n", input, mul_count);
        printf("Input a new number? (1 = Yes / 0 = No): ");
        scanf("%d", &run_con);

        if  (run_con == 0) {
            printf("Program Stopped!");
            run = false;
            break;
        } else {
            printf("\n");
            continue;
        }
    }

    return 0;
}

