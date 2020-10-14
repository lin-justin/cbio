/*
Two events A and B are independent if Pr(A and B) is equal to Pr(A)×Pr(B). In other words, the events do not 
influence each other, so that we may simply calculate each of the individual probabilities separately and then 
multiply.

More generally, random variables X and Y are independent if whenever A and B are respective events for X and Y, A 
and B are independent (i.e., Pr(A and B)=Pr(A)×Pr(B)).

As an example of how helpful independence can be for calculating probabilities, let X and Y represent the numbers 
showing on two six-sided dice. Intuitively, the number of pips showing on one die should not affect the number 
showing on the other die. If we want to find the probability that X+Y is odd, then we don't need to draw a tree 
diagram and consider all possibilities. We simply first note that for X+Y to be odd, either X is even and Y is 
odd or X is odd and Y is even. In terms of probability, Pr(X+Y is odd)=Pr(X is even and Y is odd)+Pr(X is odd and 
Y is even). Using independence, this becomes [Pr(X is even)×Pr(Y is odd)]+[Pr(X is odd)×Pr(Y is even)], or 
(1/2)^2 + (1/2)^2 = 1/2

Given: Two positive integers k (k ≤ 7) and N (N ≤ 2^k). In this problem, we begin with Tom, who in the 0th generation 
has genotype Aa Bb. Tom has two children in the 1st generation, each of whom has two children, and so on. 
Each organism always mates with an organism having genotype Aa Bb.

Return: The probability that at least N Aa Bb organisms will belong to the k-th generation of Tom's family tree 
(don't count the Aa Bb mates at each level). Assume that Mendel's second law holds for the factors.

Reference: http://rosalind.info/problems/lia/
*/

#include <iostream>
#include <cmath>

double binomial(int k, int n);
double prob(int k, int n);
double getProb(int k, int n);

int main()
{

    int k = 2;
    int n = 1;

    double probability = getProb(k, n);

    std::cout << probability << '\n';

    return 0;
}

double binomial(int k, int n)
{
    if (k > n - k)
    {
        k = n - k;
    }

    double total = 1.0;
    for (int i = 1; i < k + 1; ++i)
    {
        total *= (n - (k - i));
        total /= i;
    }

    return total;
}

double prob(int k, int n)
{
    return binomial(n, std::pow(2, k)) * (std::pow(0.25, n)) * (std::pow(0.75, (std::pow(2, k) - n)));
}

double getProb(int k, int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += prob(k, i);
    }

    return 1 - sum;
}