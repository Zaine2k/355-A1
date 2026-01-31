#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// CPSC 355 A1
// Zaine Ancheta
// UCID: 30214484

// Variables
#define TABLE_COUNT 100

int table[TABLE_COUNT][TABLE_COUNT]; // Table Size Initialization (100x100)

int pos_rows, pos_cols, neg_rows, neg_cols, search_rows, search_cols; // Iteration variables

// Initialize first 100 Prime Numbers
int primes[TABLE_COUNT];

// Prime Numbers Generator Function
void genPrimes(int count_prime) {
    int prime_array_num = 0;
    int prime_num = 2;
    while (prime_array_num < count_prime) {
        bool is_prime = true; 
        for (int i = 2; i < prime_num; i++) {
            if (prime_num % i == 0) {
                is_prime = false; 
                break;
            }
        }
        
        if (is_prime == true) {
            primes[prime_array_num] = prime_num;
            prime_array_num++;
        }
        prime_num++;
    }
}

// Table Initialization Function
void init_table (FILE *log) {

    int even = 0;
    int odd  = 1;

    fprintf(log, "Initial 100x100 Table:\n");

    // Main Diagonal Initialization
    for (int z = 0; z < TABLE_COUNT; z++) {
        table[z][z] = primes[z];
    }

    // Main Table Initialization
    // Positive Rows
    for(pos_rows = 0; pos_rows < TABLE_COUNT; pos_rows = pos_rows + 2) { 
        for(pos_cols = 0; pos_cols < TABLE_COUNT; pos_cols++) {
            if (pos_rows != pos_cols) {
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

     // Print table to LOG file
    for (int i = 0; i < TABLE_COUNT; i++) {
        for (int j = 0; j < TABLE_COUNT; j++){
            fprintf(log, "%d ", table[i][j]);
        }
        fprintf(log, "\n");
    }
}

// Search Function
int search (int input, FILE *log) {

        int mul_count = 0; 

        fprintf(log, "User input: %d\n", input);

        for (search_rows = 0; search_rows < TABLE_COUNT; search_rows++) {
            for (search_cols = 0; search_cols < TABLE_COUNT; search_cols++) {
                if (input != 0 && table[search_rows][search_cols] % input == 0) {
                    mul_count++;
                    // printf("(%d, %d) = %d\n", search_rows, search_cols, table[search_rows][search_cols]);
                    fprintf(log, "(%d, %d) = %d\n", search_rows, search_cols, table[search_rows][search_cols]);
            }
        }
    }
    return mul_count;
}

// Percentage Calculation Function 
float percent_calculation (float multiples) {

    float mul_percent = multiples / (100.0f * 100.f) * 100.0f;
    // printf("Percentage of Table: %.2f%%\n", mul_percent);

    return mul_percent;
}

int main() {

    FILE *log = fopen("assign1.log", "w");

    int input, mul_count;
    float mul_percent;
    int run = true;
    int run_con;

    // Prime Number Generation
    genPrimes(TABLE_COUNT);

    // Intialize Table
    init_table(log);

    // Main Program Loop
    while (run) {

        // Input
        // printf("Enter a Number to Search: ");
        scanf("%d", &input);

        // Search Function
        mul_count = search(input, log);
        
        // Percentage Calculation
        mul_percent = percent_calculation((float)mul_count);

        // printf("Multiple(s) of %d Found: %d\n", input, mul_count);

        fprintf(log, "Multiple(s) of %d Found: %d\n", input, mul_count);
        fprintf(log, "Percentage: %.2f%%\n\n", mul_percent);

        // printf("Input a new number? (1 = Yes / 0 = No): ");
        scanf("%d", &run_con);
        
        if  (run_con == 0) {
            // printf("Program Stopped!");
            fprintf(log, "Program stopped by user.\n");
            run = false;
            break;
        } else {
            printf("\n");
            continue;
        }
    }
    
    fclose(log);
    return 0;
}

