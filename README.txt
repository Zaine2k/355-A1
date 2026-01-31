CPSC 355 Assignment 1
Name: Zaine Ancheta
UCID: 30214484

General Description:
    This program will generate a 100x100 table and the first 100 prime numbers. The program will then construct a main diagonal with primes
and fill the table's even rows with even numbers and odd rows with odd numbers while maintaing the main diagonal. After table generation, 
the user is able to search a number where the program will count the inputted number's multiples and the percentage of how much the multiples 
occupy the table. The results and runtime processes will be printed onto the 'assign1.log' file where users can view the table, output and 
the processes that ran. The program will continue to run and search for multiples until the user exits. 

How to Run the Program:

    I feel this is necessary given that I've taken out the prompt messages that display on the terminal for the autograder. The comments are still
in the code and you can uncomment them to use the terminal commands for the program. Other than that, here is the necessary steps to run the program:

    1. To run, type in './assign1' into the terminal on VSCode.

    2. Input a number into the terminal that you want to search on the table.

    3. Enter 1 to continue using the program or 0 to end the program in the terminal after you inputted the number you wanter to search.

    4. Results will appear in the 'assign1.log' file, where it will be appended at the bottom of the file.

Search Algorithm Used for Search Function:
    I decided not to use anything fancy and I decided to use a linear search over the 100x100 table. The nested linear search will warrant a time
complexity of O(n^2), where n represents the size of the table, in this case n = 100. 


Prime Number Generator Function:
    The prime number generator function will checked for diviibility by 2 and the inputted number minus 1. After checking for divisibility,
if the divisors are only just the number itself and 1, then the program will think there are no divisors and thus we can store it as a 
prime number. The prime numbers are outputted into the prime number array, which is then iterated through to be printed onto the main
diagonal.


Side Notes:
    - It is only until the program terminates that the log file will be updated! Make sure to input 0 to end the program after inputting the 
    number you want to search in the terminal.
    - For the sake of clarity for the autograder, I've commented out all the print statements. They are all in the code still if you want to
    uncomment and inspect/run the code yourself.