class MyCircularDeque {
private:
    int* dq;      // Array to hold deque elements
    int front, rear, size, capacity;

public:
    // Constructor to initialize the deque with a given capacity
    MyCircularDeque(int k) {
        dq = new int[k];  // Dynamic array to store the deque elements
        capacity = k;
        front = -1;       // Initialize front and rear to -1 to indicate an empty deque
        rear = -1;
        size = 0;         // Start with size 0
    }
    
    // Insert an element at the front of the deque
    bool insertFront(int value) {
        if (isFull()) {
            return false;  // Deque is full
        }
        if (isEmpty()) {   // If deque is empty
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        dq[front] = value;
        size++;
        return true;
    }

    // Insert an element at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) {
            return false;  // Deque is full
        }
        if (isEmpty()) {   // If deque is empty
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        dq[rear] = value;
        size++;
        return true;
    }

    // Delete the front element from the deque
    bool deleteFront() {
        if (isEmpty()) {
            return false;  // Deque is empty
        }
        if (front == rear) {  // Only one element was in deque
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    // Delete the last element from the deque
    bool deleteLast() {
        if (isEmpty()) {
            return false;  // Deque is empty
        }
        if (front == rear) {  // Only one element was in deque
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return true;
    }

    // Get the front element of deque
    int getFront() {
        if (isEmpty()) {
            return -1;  // Return -1 if deque is empty
        }
        return dq[front];
    }

    // Get the rear element of deque
    int getRear() {
        if (isEmpty()) {
            return -1;  // Return -1 if deque is empty
        }
        return dq[rear];
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
