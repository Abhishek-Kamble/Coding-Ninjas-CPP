#include <iostream>
using namespace std;

//Solution
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = arr[0];
    
    for(int i=2; i<n+1; i++)
    {
        int x = dp[i-2] + arr[i-1];
        int y = dp[i-1];
        
        dp[i] = max(x, y);
    }
    
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}