//Memoization
#include <bits/stdc++.h>
using namespace std;

int minCostPath_Mem(int **input, int m, int n, int i, int j, int **dp) {
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Check if ans already exists
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    // Recursive calls
    int x = minCostPath_Mem(input, m, n, i, j+1, dp);
    int y = minCostPath_Mem(input, m, n, i+1, j+1, dp);
    int z = minCostPath_Mem(input, m, n, i+1, j, dp);
    // Small Calculation
    int a = min(x, min(y, z)) + input[i][j];
    
    // Save the answer for future use
    dp[i][j] = a;
    
    return a;
}

int minCostPath_Mem(int **input, int m, int n) {
    int **dp = new int*[m];
    for(int i = 0; i < m; i++) {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    
    return minCostPath_Mem(input, m, n, 0, 0, dp);
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
	cout << minCostPath_Mem(arr, n, m) << endl;
}