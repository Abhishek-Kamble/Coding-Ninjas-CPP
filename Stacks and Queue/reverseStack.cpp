/*
Reverse a Stack

You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.
*/

#include <iostream>
#include <stack>
using namespace std;

//SOLUTION
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.size() <= 1)
        return;

    int temp = input.top();
    input.pop();

    reverseStack(input, extra);

    while(!input.empty())
    {
        extra.push(input.top());
        input.pop();
    }

    input.push(temp);

    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
