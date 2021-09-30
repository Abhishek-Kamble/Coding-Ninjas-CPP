#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(42);
    pq.push(5);

    cout << pq.empty() << endl;
    cout << pq.size() << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << pq.size() << endl;

    return 0;
}