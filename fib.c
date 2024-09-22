#include <stdio.h>
#include <stdlib.h>

typedef int unsigned long long ll;
static ll* memoizationArray;

// Function prototypes
ll memoize(ll num);

// Iterative method for fibonacci
ll iterative(ll cycles) {
    // Initialize variables
    ll x = 0;
    ll y = 1;
    ll z = 1;
    
    for(ll i = 0; i < cycles-1; i++) {
        x = y;
        y = z;
        z = x + y;
    }
    return z;
}

// Recursive method for fibonacci
ll recursive(ll cycles) {
    if(cycles == 0)
        return 0;
    else if(cycles == 1)
        return 1;
    return memoize(cycles-1) + memoize(cycles-2);
}

// Initialize and fill array
ll* init_array(ll size) {
    static ll* array;
    array = malloc(size * sizeof(ll));

    array[0] = 0;
    array[1] = 1;
    array[2] = 1;
    for(int i = 3; i <= size * sizeof(ll); i++) {
        array[i] = -1;
    }
    return array;
}

// Memoization function
ll memoize(ll N) {
    if(memoizationArray[N] == -1)
        memoizationArray[N] = recursive(N);
    return memoizationArray[N];
}


int main(int argc, char **argv) {
    // Initialize variables
    char recursiveOrIterate = *(argv[2]);
    char* p;
    ll firstInteger = strtoll((argv[1]), &p, 10);
    ll fileInteger;
    ll N;
    ll nthFibonacciNumber;

    // Defines N as file number + user input
    N = firstInteger;
    //printf("N is: %d\n", N);

    memoizationArray = init_array(N);
    ll (*funcPtr)(ll);

    // Run iterative or recursive methods
    if(recursiveOrIterate == 'i')
        funcPtr = iterative;
    else
        funcPtr = recursive;

    nthFibonacciNumber = funcPtr(N-1);
    
    printf("%llu\n\n", nthFibonacciNumber);

    free(memoizationArray);
    return nthFibonacciNumber;
}