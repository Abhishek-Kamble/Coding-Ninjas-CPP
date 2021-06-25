/*
Replace pi (recursive)
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix
Sample Output :
x3.14x

Sample Input 2 :
pipi
Sample Output :
3.143.14

Sample Input 3 :
pip
Sample Output :
3.14p
***********************************************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void replacePi(char input[])
{
    // Write your code here

    //base case
    if (input[0] == '\0')
        return;

    //Recursive call
    replacePi(input + 1);

    //small calculation
    int start = 0;
    if (input[start] == 'p' && input[start + 1] == 'i')
    {
        for (int i = strlen(input) + 2; i > start + 2; i--)
        {
            input[i] = input[i - 2];
        }

        input[start] = '3';
        input[start + 1] = '.';
        input[start + 2] = '1';
        input[start + 3] = '4';
    }
}

//main function
int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
