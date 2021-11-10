//Longest common subsequence using memoization
#include<bits/stdc++.h>
using namespace std;

int LCS_mem(string s, string t, int** dp)
{
    int i = s.size();
    int j = t.size();

	//base case
    if(i == 0 || j == 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(s[0] == t[0])
    {
        dp[i][j] = 1 + LCS_mem(s.substr(1), t.substr(1), dp);
        return dp[i][j];
    }
    else
    {
    	int a = LCS_mem(s, t.substr(1), dp);
	    int b = LCS_mem(s.substr(1), t, dp);

	    dp[i][j] = max(a,b);

	    return dp[i][j];
    }
}

int main()
{
    string s, t;
    cin >> s >> t;

    int **dp = new int*[s.length() + 1];
    for(int i=0; i<=s.length(); i++)
    {
        dp[i] = new int[t.length() + 1];
        for(int j=0; j<=t.length(); j++)
            dp[i][j] = -1;
    }

    cout << "Ans: " << LCS_mem(s, t, dp) << endl; 
    return 0;
}