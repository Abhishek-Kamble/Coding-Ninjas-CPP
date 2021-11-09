#include<bits/stdc++.h>
#define mod 1000000007;
using namespace std;

int balancedBTs(int n)
{
    if(n <= 1)
    {
        return 1;
    }

    int x = balancedBTs(n-1);
    int y = balancedBTs(n-2);

    long long int temp1 = ((long long int)x * x) % mod;
    long long int temp2 = (2 * (long long int)x * y) % mod;
    long long int ans = (temp1 + temp2) % mod;

    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}