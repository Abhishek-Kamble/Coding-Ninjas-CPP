//Brute force
#include <bits/stdc++.h>
using namespace std;

// int dp[101][101];

int minCostPathHelper(int **input, int m, int n, int i, int j)
{
    if(i == m-1 && j == n-1)
        return input[i][j];

    if(i >= m || j >= n)
        return INT_MAX;

    int rightAns = minCostPathHelper(input, m, n, i+1, j);
    int downAns = minCostPathHelper(input, m, n, i, j+1);
    int crossAns = minCostPathHelper(input, m, n, i+1, j+1);

    int ans = min(rightAns, min(downAns, crossAns)) + input[i][j];

    return ans;
}

int minCostPath(int **input, int m, int n)
{
    return minCostPathHelper(input, m, n, 0, 0);
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
    // memset(dp, -1, sizeof(dp));
	cout << minCostPath(arr, n, m) << endl;
}