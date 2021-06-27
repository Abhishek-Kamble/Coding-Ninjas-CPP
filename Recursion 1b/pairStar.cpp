/*
Pair Star
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello
Sample Output 1:
hel*lo

Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

******************************************************************************************************************************/

#include<iostream>
#include<cstring>

using namespace std;

void pairStar(char arr[])
{
    //base case
    if(arr[0] == '\0')
        return;

    //recursive call
    pairStar(arr+1);

    //small calculation
    int start = 0;
    if(arr[start] == arr[start + 1])
    {
        int l = strlen(arr);
        arr[l+1] = '\0';
        for(int i=l; i>start; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[start+1] = '*';
    }

}

//main function
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
