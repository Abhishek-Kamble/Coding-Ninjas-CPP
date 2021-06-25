/*
String to Integer
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")

Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 <= |S| <= 9
where |S| represents length of string S.

*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int stringToNumber(char input[]) 
{
    //base case
    if(strlen(input) == 1)
        return input[0]-48;

    //small calculations
    int b = input[0] - 48;
    int smallAns = b * pow(10, strlen(input)-1);

    //recursive call
    int ans = smallAns + stringToNumber(input+1);

	return ans;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
