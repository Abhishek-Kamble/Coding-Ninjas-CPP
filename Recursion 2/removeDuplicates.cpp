/*
Remove Duplicates Recursively
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

*/

#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char* input)
{
    //base case
    if(strlen(input)<=1)
        return;

    //small calculation
    int start = 0;
    if(input[start] == input[start+1])
    {
        for(int i = start; i < strlen(input)-1; i++)
        {
            input[i] = input[i+1];
        }
        input[strlen(input)-1] = '\0';
        removeConsecutiveDuplicates(input);
    }
    else
        removeConsecutiveDuplicates(input+1);
}

//main function
int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
