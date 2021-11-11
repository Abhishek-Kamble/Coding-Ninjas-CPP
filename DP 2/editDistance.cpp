//edit distance using rec
#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    
    if(m == 0)
        return n;
    
    if( n == 0)
        return m;
    
    if(s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));

    int a = editDistance(s1.substr(1), s2);
    int b = editDistance(s1, s2.substr(1));
    int c = editDistance(s1.substr(1), s2.substr(1));
    
    int ans = min(a, min(b, c)) + 1;
    
    return ans;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t) << endl;
}