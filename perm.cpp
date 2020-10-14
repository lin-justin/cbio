/*
A permutation of length n is an ordering of the positive integers {1,2,…,n}. For example, π=(5,3,2,1,4) is a 
permutation of length 5.

Problem:
=======
Given: A positive integer n ≤ 7.

Return: The total number of permutations of length n, followed by a list of all such permutations (in any order).

Reference: http://rosalind.info/problems/perm/
*/

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int> > getPermutation(int n);

int main()
{
    int n = 3;

    std::vector<std::vector<int> > result = getPermutation(n);

    std::cout << result.size() << '\n';
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}

std::vector<std::vector<int> > getPermutation(int n)
{
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        nums[i] = i + 1;
    }

    std::vector<std::vector<int> > result;
    do
    {
        result.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));

    return result;
}