//Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    //write your code here
    if (n == 0 || maxWeight == 0)
        return 0;

    if (dp[n - 1][maxWeight] != -1)
        return dp[n - 1][maxWeight];

    if (weights[n - 1] > maxWeight)
        return knapsack(weights, values, n - 1, maxWeight);

    int includeItem = values[n - 1] + knapsack(weights, values, n - 1, maxWeight - weights[n - 1]);
    int excludeItem = knapsack(weights, values, n - 1, maxWeight);

    dp[n - 1][maxWeight] = max(includeItem, excludeItem);
    return max(includeItem, excludeItem);
}
int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}