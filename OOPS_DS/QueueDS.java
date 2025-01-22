package datastructures;

class QueueImp {
    int n;
    int[] arr;
    int front = -1, rear = -1;

    QueueImp(int n) {
        this.n = n;
        arr = new int[n];
    }

    // Enqueue operation
    void enqueue(int x) {
        if (rear == n - 1) {
            System.out.println("Queue Overflow!");
        } else {
            if (front == -1) front = 0; // First element
            arr[++rear] = x;
            System.out.println("Enqueued: " + x);
        }
    }

    // Dequeue operation
    int dequeue() {
        if (front == -1 || front > rear) {
            System.out.println("Queue Underflow!");
            return -1;
        } else {
            int val = arr[front++];
            if (front > rear) { // Reset queue when empty
                front = rear = -1;
            }
            return val;
        }
    }

    // Display elements in the queue
    void display() {
        if (front == -1 || front > rear) {
            System.out.println("Queue is Empty!");
            return;
        }
        System.out.println("Queue elements are:");
        for (int i = front; i <= rear; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

public class QueueDS {
    public static void main(String[] args) {
        QueueImp q = new QueueImp(10);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.display();
        q.dequeue();
        q.display();
        q.enqueue(5);
        q.display();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.display();
    }
}
