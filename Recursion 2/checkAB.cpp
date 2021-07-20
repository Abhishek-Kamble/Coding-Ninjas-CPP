/*
Check AB

Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.

Input format :
String S

Output format :
'true' or 'false'

Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
abb

Sample Output 1 :
true

Sample Input 2 :
abababa

Sample Output 2 :
false

*/
#include<iostream>
#include<cstring>
using namespace std;

bool checkAB(char* str, int startIndex)
{
    if(strlen(str) == 0)
        return true;

    if(str[0] != 'a')
        return false;

    if(str[strlen(str)+1]!='\0' && str[strlen(str)+2]!='\0')
    {
        if(str[1]=='b' && str[2]=='b')
        {
            return checkAB(str+3, 3);
        }
    }
    return checkAB(str+1, 1);
}

bool checkAB(char* input)
{
    return checkAB(input, 0);
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
