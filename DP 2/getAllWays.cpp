/*
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2
Hence, answer is 1.
Note : x^y represents x raise to the power y
*/


#include <iostream>
using namespace std;

int power(int num, unsigned int n)
{
  if (n == 0)
    return 1;

  else if (n % 2 == 0)
    return power(num, n / 2) * power(num, n / 2);
  else
    return num * power(num, n / 2) * power(num, n / 2);
}
int helper(int x, int n, int curr_num, int curr_sum)
{
  int p = power(curr_num, n);
  int results = 0;

  while (p + curr_sum < x)
  {
    results += helper(x, n, curr_num + 1, p + curr_sum);
    curr_num++;
    p = power(curr_num, n);
  }

  if (p + curr_sum == x)
    results++;

  return results;
}

int getAllWays(int a, int b)
{
  int ans = helper(a, b, 1, 0);
  return ans;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << getAllWays(a, b);
}