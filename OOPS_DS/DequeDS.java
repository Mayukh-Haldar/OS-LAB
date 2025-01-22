package datastructures;

class Deque {
    int n;
    int[] arr;
    int front, rear;

    Deque(int n) {
        this.n = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Check if the deque is full
    boolean isFull() {
        return (rear + 1) % n == front;
    }

    // Check if the deque is empty
    boolean isEmpty() {
        return front == -1;
    }

    // Insert an element at the front
    void insertFront(int x) {
        if (isFull()) {
            System.out.println("Deque Overflow!");
            return;
        }
        if (isEmpty()) { // If empty
            front = rear = 0;
        } else if (front == 0) {
            front = n - 1;
        } else {
            front--;
        }
        arr[front] = x;
        System.out.println("Inserted at front: " + x);
    }

    // Insert an element at the rear
    void insertRear(int x) {
        if (isFull()) {
            System.out.println("Deque Overflow!");
            return;
        }
        if (isEmpty()) { // If empty
            front = rear = 0;
        } else {
            rear = (rear + 1) % n;
        }
        arr[rear] = x;
        System.out.println("Inserted at rear: " + x);
    }

    // Delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            System.out.println("Deque Underflow!");
            return;
        }
        System.out.println("Deleted from front: " + arr[front]);
        if (front == rear) { // Single element case
            front = rear = -1;
        } else {
            front = (front + 1) % n;
        }
    }

    // Delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            System.out.println("Deque Underflow!");
            return;
        }
        System.out.println("Deleted from rear: " + arr[rear]);
        if (front == rear) { // Single element case
            front = rear = -1;
        } else if (rear == 0) {
            rear = n - 1;
        } else {
            rear--;
        }
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            System.out.println("Deque is Empty!");
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) {
            System.out.println("Deque is Empty!");
            return -1;
        }
        return arr[rear];
    }

    // Display the deque elements
    void display() {
        if (isEmpty()) {
            System.out.println("Deque is Empty!");
            return;
        }
        System.out.print("Deque elements are: ");
        int i = front;
        while (true) {
            System.out.print(arr[i] + " ");
            if (i == rear) break;
            i = (i + 1) % n;
        }
        System.out.println();
    }
}

public class DequeDS {
    public static void main(String[] args) {
        Deque dq = new Deque(5);
        dq.insertRear(1);
        dq.insertRear(2);
        dq.insertFront(0);
        dq.insertRear(3);
        dq.insertFront(-1);
        dq.display(); // Deque full now

        dq.deleteFront();
        dq.deleteRear();
        dq.display();

        dq.insertFront(10);
        dq.insertRear(20);
        dq.display();

        System.out.println("Front Element: " + dq.getFront());
        System.out.println("Rear Element: " + dq.getRear());
    }
}
