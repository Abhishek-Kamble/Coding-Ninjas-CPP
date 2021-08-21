#include<climits>
template <typename T>
class StackUsingTemplates{
private:
    T* data;
    int nextIndex;
    int capacity;

public:
    StackUsingTemplates()
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
            return 0;
        }

        return data[nextIndex-1];
    }

    void push(int tempData)
    {
        if(nextIndex == capacity)
        {
            T* newData = new T[2 * capacity];
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
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }
};
