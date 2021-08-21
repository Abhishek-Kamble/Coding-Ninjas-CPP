#include<climits>

class StacksUsingArrays{
private:
    int* data;
    int nextIndex;
    int capacity;

public:
    StacksUsingArrays()
    {
        data = new int[1];
        nextIndex = 0;
        capacity = 1;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    int size()
    {
        return nextIndex;
    }

    int top()
    {
        if(isEmpty())
        {
            return INT_MIN;
        }

        return data[nextIndex-1];
    }

    void push(int tempData)
    {
        if(nextIndex == capacity)
        {
            // cout << "Stack is full!" << endl;
            // return;

            int* newData = new int[2 * capacity];
            for(int i=0; i<capacity; i++)
                newData[i] = data[i] ;

            data = newData;
            capacity *= 2;
        }

        data[nextIndex] = tempData;
        nextIndex++;
    }

    int pop()
    {
        if(isEmpty())
        {
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }
};
