/*
Probability is the mathematical study of randomly occurring phenomena. We will model such a phenomenon with a 
random variable, which is simply a variable that can take a number of different distinct outcomes depending on 
the result of an underlying random process.

For example, say that we have a bag containing 3 red balls and 2 blue balls. If we let X represent the random 
variable corresponding to the color of a drawn ball, then the probability of each of the two outcomes is given by
P(X = red) = 3/5 and P(X = blue) = 2/5.

Random variables can be combined to yield new random variables. Returning to the ball example, let Y model the 
color of a second ball drawn from the bag (without replacing the first ball). The probability of Y being red 
depends on whether the first ball was red or blue. To represent all outcomes of X and Y, we therefore use a 
probability tree diagram. This branching diagram represents all possible individual probabilities for X and Y, 
with outcomes at the endpoints ("leaves") of the tree. The probability of any outcome is given by the product of 
probabilities along the path from the beginning of the tree.

An event is simply a collection of outcomes. Because outcomes are distinct, the probability of an event can be 
written as the sum of the probabilities of its constituent outcomes. For our colored ball example, let A be the 
event "Y is blue." P(A) is equal to the sum of the probabilities of two different outcomes:
P(X = blue and Y = blue) + P(X = red and Y = blue), or (3/10) + (1/10) = 2/5.

Problem:
=======
Given: Three positive integers k, m, and n, representing a population containing k+m+n organisms: k individuals are 
       homozygous dominant for a factor, m are heterozygous, and n are homozygous recessive.

Return: The probability that two randomly selected mating organisms will produce an individual possessing a dominant 
        allele (and thus displaying the dominant phenotype). Assume that any two organisms can mate.

Reference: http://rosalind.info/problems/iprb/
*/

#include <iostream>

double prob_dom(int k, int m, int n);

int main()
{
    int k = 2;
    int m = 2;
    int n = 2;

    double prob = prob_dom(k, m, n);

    std::cout << prob << '\n';

    return 0;
}

double prob_dom(int k, int m, int n)
{
    k = static_cast<double>(k);
    m = static_cast<double>(m);
    n = static_cast<double>(n);

    double t = k + m + n;
    double pk = k / t;
    double pm = m / t;
    double pn = n / t;

    // Max probability
    double max_prob = 1.0;

    // Subtract the probability if both are homozygous recessive
    max_prob -= pn * ((n - 1) / (t - 1));

    // Subtract the probability if one is homozygous recessive
    // and if one is heterozygous recessive
    max_prob -= 2 * pn * (m / (t - 1)) * 0.5;

    // Subtract the probability that if both are heterozygous recessive
    max_prob -= pm * ((m - 1) / (t - 1)) * 0.25;

    return max_prob; 
}