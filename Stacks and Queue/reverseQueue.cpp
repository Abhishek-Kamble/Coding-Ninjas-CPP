/*
Reverse Queue

You have been given a queue that can store integers as the data. You are required to write a function that reverses the populated queue itself without using any other data
*/

#include <iostream>
using namespace std;

//SOLUTION
#include<queue>
void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.size()<=0)
        return;

    int temp = input.front();
    input.pop();

    reverseQueue(input);

    input.push(temp);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}
