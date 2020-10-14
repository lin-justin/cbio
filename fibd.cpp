/*
Recall the definition of the Fibonacci numbers from “Rabbits and Recurrence Relations”, which followed the 
recurrence relation F_n = F_(n−1) + F_(n−2) and assumed that each pair of rabbits reaches maturity in one month and 
produces a single pair of offspring (one male, one female) each subsequent month.

Our aim is to somehow modify this recurrence relation to achieve a dynamic programming solution in the case that 
all rabbits die out after a fixed number of months. See Figure 4 for a depiction of a rabbit tree in which rabbits 
live for three months (meaning that they reproduce only twice before dying).

Problem:
=======
Given: Positive integers n ≤ 100 and m ≤ 20.

Return: The total number of pairs of rabbits that will remain after the n-th month if all rabbits live for m months.

Reference: http://rosalind.info/problems/fibd/
*/

#include <iostream>
#include <vector>

int mortalFibonacci(int n, int m);

int main()
{

    int n = 6;
    int m = 3;

    int result = mortalFibonacci(n, m);

    std::cout << result << '\n';

    return 0;
}

int mortalFibonacci(int n, int m)
{
    std::vector<std::vector<long long>> fib(102, std::vector<long long> (22, 0));

    fib[1][1] = 1;
    fib[2][2] = 1;

    for (int i = 3; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            fib[i][j] = fib[i - 1][j - 1];
        }
        for (int j = 2; j <= m; ++j)
        {
            fib[i][1] += fib[i - 1][j];
        }
    }

    long long ret = 0;
    for (int  j = 1; j <= m; ++j)
    {
        ret += fib[n][j];
    }

    return ret;
}