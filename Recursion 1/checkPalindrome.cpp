/*
Check Palindrome (recursive)
Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar

Sample Output 1:
true

Sample Input 2 :
ninja

Sample Output 2:
false
*/

#include <iostream>
#include<cstring>
using namespace std;

bool helper(char *str, int start, int end)
{
	//base case
	if(start >= end )
        return true;
    
    //small cal
    if(str[start] != str[end])
        return false;
    
    return helper(str, start+1, end-1);
    
}

bool checkPalindrome(char input[]) {
    // Write your code here
	return helper(input, 0, strlen(input)-1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

