package datastructures;

class CircularQueue {
    int n;
    int[] arr;
    int front = -1, rear = -1;

    CircularQueue(int n) {
        this.n = n;
        arr = new int[n];
    }

    // Enqueue operation
    void enqueue(int x) {
        if ((rear + 1) % n == front) {
            System.out.println("Queue Overflow!");
        } else {
            if (front == -1) front = 0; // First element
            rear = (rear + 1) % n;
            arr[rear] = x;
            System.out.println("Enqueued: " + x);
        }
    }

    // Dequeue operation
    int dequeue() {
        if (front == -1) {
            System.out.println("Queue Underflow!");
            return -1;
        }
        int val = arr[front];
        if (front == rear) { // Only one element left
            front = rear = -1;
        } else {
            front = (front + 1) % n;
        }
        return val;
    }

    // Display elements in the queue
    void display() {
        if (front == -1) {
            System.out.println("Queue is Empty!");
            return;
        }
        System.out.print("Queue elements are: ");
        int i = front;
        while (true) {
            System.out.print(arr[i] + " ");
            if (i == rear) break;
            i = (i + 1) % n;
        }
        System.out.println();
    }
}

public class CircularQueueDS {
    public static void main(String[] args) {
        CircularQueue cq = new CircularQueue(5);
        cq.enqueue(1);
        cq.enqueue(2);
        cq.enqueue(3);
        cq.enqueue(4);
        cq.enqueue(5); // Queue full now
        cq.display();

        cq.dequeue();
        cq.dequeue();
        cq.display();

        cq.enqueue(6);
        cq.enqueue(7);
        cq.display();

        cq.dequeue();
        cq.display();
    }
}
