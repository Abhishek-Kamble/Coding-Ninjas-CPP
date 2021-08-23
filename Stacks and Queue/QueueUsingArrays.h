template <typename T>
class QueueUsingArrays{
    T *data;
    int size;
    int firstIndex;
    int capacity;
    int nextIndex;

public:
    QueueUsingArrays(int s){
        data = new T[s];
        size = 0;
        capacity = s;
        firstIndex = -1;
        nextIndex = 0;
    }

    int getSize(){
        return size;
    }

    int isEmpty(){
        return size == 0;
    }

    T front(){
        return data[firstIndex];
    }

    void enqueue(T element){
        if(size == capacity){
            cout << "Queue is full!" << endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }

    T dequeue(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }

};
