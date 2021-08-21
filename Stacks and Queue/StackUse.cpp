#include<iostream>
using namespace std;
#include "StacksUsingArrays.h"
#include "StackUsingTemplates.h"

int main()
{
    // StacksUsingArrays s;
    StackUsingTemplates<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
};
