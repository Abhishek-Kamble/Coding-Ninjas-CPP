#include<bits/stdc++.h>
using namespace std;

int LCS_DP(string s, string t)
{
    int m = s.size();
	int n = t.size();
	int **dp = new int*[m+1];

	for(int i = 0; i <= m; i++) {
		dp[i] = new int[n+1];
	}

	// Fill 1st row
	for(int j = 0; j <= n; j++) {
		dp[0][j] = 0;
	}

	// Fill 1st col
	for(int i = 1; i <= m; i++) {
		dp[i][0] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			// Check if 1st char matches
			if(s[m-i] == t[n-j]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				int a = dp[i-1][j];
				int b = dp[i][j-1];
				int c = dp[i-1][j-1];
				dp[i][j] = max(a, max(b, c));
			}
		}
	}

	return output[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << "Ans: " << LCS_DP(s, t) << endl; 
    return 0;
}