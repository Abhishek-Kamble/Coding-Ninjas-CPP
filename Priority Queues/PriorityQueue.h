//Min-Priority Queue implementation
#include <vector>
class PriorityQueue
{

    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    //return size of Priority Queue
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
            return 0; //if PQ is empty

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;

            childIndex = parentIndex;
        }
    }

    void removeMin()
    {
        if (isEmpty())
            return 0;

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.push_back();

        int parentIndex = pq.size() - 1;
        int LCI = (2 * parentIndex) + 1;
        int RCI = (2 * parentIndex) + 2;
        int minIndex = 0;

        while (LCI < pq.size())
        {
            minIndex = parentIndex;

            if (pq[minIndex] > pq[LCI])
            {
                minIndex = LCI;
            }

            if (pq[minIndex] > pq[RCI] && pq[minIndex] < pq[LCI])
            {
                minIndex = RCI;
            }

            if (minIndex == parentIndex)
                break;

            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;

            parentIndex = minIndex;
            LCI = (2 * parentIndex) + 1;
            RCI = (2 * parentIndex) + 1;
        }

        return ans;
    }
};