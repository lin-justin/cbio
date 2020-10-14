/*
A sequence is an ordered collection of objects (usually numbers), which 
are allowed to repeat. Sequences can be finite or infinite.

A recurrence relation is a way of defining the terms of a sequence with 
respect to the values of the previous terms.

Problem:
=======
Given: Positive integers n <= 40 and k <= 5
Return: The total number of rabbit pairs that will be present after n months,
        if we begin with 1 pair and in each generation, every pair of reproduction-age
        rabbits produces a litter of k rabbit pairs (instead of only 1 pair).

Reference: http://rosalind.info/problems/fib/
*/

#include <iostream>

// Function prototype
int fib(int n, int k);

int main()
{
    int n = 5;
    int k = 3;

    int result = fib(n, k);

    std::cout << result << '\n';

    return 0;
}

int fib(int n, int k)
{
    if (n < 1)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fib(n - 1, k) + (k * fib(n - 2, k));
    }
}