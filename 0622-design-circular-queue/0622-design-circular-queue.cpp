class MyCircularQueue {
public:
    vector<int> data;
    int front;
    int rear;
    int size;
    int count;

    MyCircularQueue(int k) {
        size = k;
        data.resize(k);
        front = 0;
        rear = -1;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        rear = (rear + 1) % size;
        data[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % size;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return data[rear];
    }
    
    bool isEmpty() {
        return (count == 0);
    }
    
    bool isFull() {
        return (count == size);
    }
};
