#include <ctime>
#include <iostream>
using namespace std;

int fib(int n){

    // Precondition: n is a positive integer
    // Postcondition: Returns the nth Fib. number
    if ( n <= 2 )
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int iterativeFib(int n){

    // Initialize base cases:
    int previous = 1; 		// initially fib(1)
    int current = 1;  		// initially fib(2)
    int next = 1;     		// result when n is 1 or 2

    // compute next Fibonacci values when n >= 3
    for (int i = 3; i <= n; ++i){
        // current is fib(i-1)
        // previous is fib(i-2)
        next = current + previous; // fib(i)

        previous = current; 	// get ready for the
        current = next;		// next iteration
    }

    return next;
}

int main() {

    cout << "-------------------------------------" << endl;
    cout << "---RECURSIVE SOLUTION TO FIBONACCI---" << endl;
    cout << "-------------------------------------" << endl;

    for (int i = 1; i < 56; i++) {

        if (i <= 32) {

            double duration;
            clock_t startTime = clock();

            cout << "Fibonacci N = " << i << " : " << fib(i) <<endl;

            for (int j = 0; j < 100000; j++)
                fib(i);

            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            duration = duration / 100000;
            cout << "Execution took " << duration << " milliseconds." << endl << endl;

        } else {

            //Store the starting time
            double duration;
            clock_t startTime = clock();

            // code block
            cout << "Fibonacci N = " << i << " : " << fib(i) <<endl;

            //Compute the number of seconds that passed since the starting time
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            cout << "Execution took " << duration << " milliseconds." << endl << endl;

        }

    }

    cout << "-------------------------------------" << endl;
    cout << "---ITERATIVE SOLUTION TO FIBONACCI---" << endl;
    cout << "-------------------------------------" << endl;

    for (int i = 1; i <= 1000000001; i += 10000000) {

        if (i == 1) {

            double duration;
            clock_t startTime = clock();

            cout << "Fibonacci N = " << i << " : " << fib(i) <<endl;

            for (int j = 0; j < 100000; j++)
                iterativeFib(i);

            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            duration = duration / 1000;
            cout << "Execution took " << duration << " milliseconds." << endl << endl;

        } else {

            //Store the starting time
            double duration;
            clock_t startTime = clock();

            // code block
            cout << "Fibonacci N = " << i << " : " << iterativeFib(i) <<endl;

            //Compute the number of seconds that passed since the starting time
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            cout << "Execution took " << duration << " milliseconds." << endl << endl;

        }
    }

    return 0;
}