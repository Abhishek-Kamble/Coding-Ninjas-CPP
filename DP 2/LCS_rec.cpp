//Longest common subsequence using rec
#include<bits/stdc++.h>
using namespace std;

int LCS_rec(string s, string t)
{
    // base case
    if(s.size() == 0 || t.size() == 0)
        return 0;

    //small cal.
    if(s[0] == t[0])
        return 1 + LCS_rec(s.substr(1), t.substr(1));

    int a = LCS_rec(s.substr(1), t);
    int b = LCS_rec(s, t.substr(1));
    int c = LCS_rec(s.substr(1), t.substr(1));

    return max(a, max(b, c));
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << "Ans: " << LCS_rec(s, t) << endl;

    return 0;
}