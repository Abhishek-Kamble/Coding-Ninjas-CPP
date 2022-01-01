#include <iostream>
using namespace std;
//TODO
int longestIncreasingSubsequence(int* arr, int n)
{
  int *dp = new int[n+1];
  dp[0] = 0;
  dp[1] = 1;
  
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}