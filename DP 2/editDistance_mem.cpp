//edit distance using memoization
#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2, dp)
{
    int m = s1.size();
    int n = s2.size();
    
    if(m == 0)
        return n;
    
    if( n == 0)
        return m;

    if(s[m][n] != -1)
        return dp[m][n];
    
    if(s1[0] == s2[0])
    {
        dp[m][n] = editDistance(s1.substr(1), s2.substr(1), dp);
        return dp[m][n];
    }
    int a = editDistance(s1.substr(1), s2, dp);
    int b = editDistance(s1, s2.substr(1), dp);
    int c = editDistance(s1.substr(1), s2.substr(1), dp);
    
    int ans = min(a, min(b, c)) + 1;
    dp[m][n] = ans;
    return ans;
}

int editDistance_helper(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int** dp = new int*[m+1];
    for(int i=0; i<=m; i++)
    {
        dp[i] = new int[n+1]
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;
    }

    return editDistance(s, t, dp);

}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << editDistance_helper(s, t) << endl;
}