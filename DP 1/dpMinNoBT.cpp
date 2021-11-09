#include<bits/stdc++.h>
#define mod 1000000007;
using namespace std;

int balancedBTs(int n)
{
//    TODO Implementation
    int *dp = new int[n+1];
    dp[0] = dp[1] = 1;
    for(int i=3; i<=n; i++)
    {
        dp[i] = long long(dp[i-1]) * ((long long(dp[i-1]) + 2 * (long long(dp[i-2]))));
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}