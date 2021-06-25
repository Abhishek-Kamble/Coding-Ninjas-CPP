/*
Remove X
Given a string, compute recursively a new string where all 'x' chars have been removed.

Input format :
String S
Output format :
Modified String

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 

Sample Input 1 :
xaxb
Sample Output 1:
ab

Sample Input 2 :
abc
Sample Output 2:
abc

Sample Input 3 :
xx
Sample Output 3:

*********************************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

//external function to remove X at position 1
void remove(char* str)
{
    if(strlen(str) == 1)
    {
        *str = '\0';
        return;
    }

    while(*str != '\0')
    {
        *str = *(str+1);
        *str++;
    }

    *str = '\0';
}

//recursive function to remove
void removeX(char *str)
{
    //base case
    if(str[0] == '\0')
        return;

    //small calculation
    if(str[0] == 'x')
    {
        remove(str);
        removeX(str);
    }

    //recursive call
    removeX(str+1);
}

//main function
int main() 
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
