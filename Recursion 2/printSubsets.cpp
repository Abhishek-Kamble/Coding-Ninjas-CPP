/*
Print Subsets of Array

Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12
20
20 12
15
15 12
15 20
15 20 12

*/

#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;

void printSubsetsOfArray(int arr[], int n)
{
    int  count = pow(2,n);
    // The outer for loop will run 2^n times to print all subset .
    // Here variable i will act as a binary counter
    for (int i = 0; i < count; i++)
    {
    // The inner for loop will run n times , As the maximum number of elements a set can have is n
    // This loop will generate a subset
        for (int j = 0; j < n; j++)
        {
            // This if condition will check if jth bit in binary representation of  i  is set or not
            // if the value of (i & (1 << j)) is greater than 0 , include arr[j] in the current subset
            // otherwise exclude arr[j]
            if ((i & (1 << j)) > 0)
                cout << arr[j] << " ";
        }
        cout << "\n";
    }
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
