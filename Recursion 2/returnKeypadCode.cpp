/*
Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

string key[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int num, string output[])
{
    //base case
    if(num==0)
    {
		output[0]="";
        return 1;
    }

    int small=keypad(num/10, output);
	int last=num%10;
    int k=small;

    for(int i=0; i<key[last].size()-1; i++)
    {
        for(int j=0; j<small; j++)
        {
            output[k++]=output[j];
        }
    }

    k=0;
    for(int i=0; i<key[last].size(); i++)
    {
        for(int j=0; j<small; j++)
        {
            output[k++]+=key[last][i];
        }
    }
    return k;
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
