/*
Staircase
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.

Input format :
Integer N

Output Format :
Integer W

Constraints :
1 <= N <= 30

Sample Input 1 :
4

Sample Output 1 :
7

Sample Input 2 :
5

Sample Output 2 :
13

*/

#include <iostream>
using namespace std;

int staircase(int n){
    //base case
    int x,y,z;

    if(n==1||n==0)
        return 1;
	else if(n==2)
        return 2;
    else
    {
        x=staircase(n-1);
        y=staircase(n-2);
        z=staircase(n-3);
        return x+y+z;
    }
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
