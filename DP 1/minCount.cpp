/*
Code : Minimum Count
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
*/
#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    int *minSquaresRequired = new int[n + 1];
    minSquaresRequired[0] = 0;
    minSquaresRequired[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        minSquaresRequired[i] = INT_MAX;
        for (int j = 1; i - (j * j) >= 0; ++j)
        {
            minSquaresRequired[i] = min(minSquaresRequired[i], minSquaresRequired[i - (j * j)]);
        }
        minSquaresRequired[i] += 1;
    }
    int result = minSquaresRequired[n];
    delete minSquaresRequired;
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}