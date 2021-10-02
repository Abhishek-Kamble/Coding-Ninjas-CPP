#include<iostream>
using namespace std;

//brute force
int fibo(int n)
{
    if(n<=1)
        return n;

    int a = fibo(n-1);
    int b = fibo(n-2);

    return a+b;
}

int fibo_helper(int n, int* ans)
{
    if(n<=1)
        return n;

    //check output already exists
    if(ans[n] != -1)
        return ans[n];

    int a = fibo_helper(n-1, ans);
    int b = fibo_helper(n-2, ans);

    //save current ans for future use
    ans[n] = a + b;

    //return final output
    return ans[n];
}

//memomoization (Top down) -- recursive
int fibo2(int n)
{
    int* ans = new int[n+1];
    for(int i=0; i<n+1; i++)
        ans[i] = -1;
    return fibo_helper(n, ans);
}

//dynamic programming (bottom up) -- iterations
int fibo3(int n)
{
    int* ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;

    for(int i=2; i < n+1; i++)
    {
        ans[i] = ans[i-1] + ans[i-2];
    }

    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    cout << fibo2(n) << endl;    
    cout << fibo3(n) << endl;
}