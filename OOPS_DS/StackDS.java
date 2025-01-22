package datastructures;

class StackImp{
    int n;
    int[] arr;
    int top=-1;
    StackImp(int n){
        this.n=n;
        arr=new int[n];
    }
    void push(int x){
        if (top==n-1){
            System.out.println("Stack Overflow!");
        }
        else{
            arr[++top]=x;
            System.out.println("Pushed: "+x);
        }
    }
    int pop(){
        if (top==-1){
            System.out.println("Stack Underflow!");
            return -1;
        }
        else{
            return arr[top--];
        }
    }
    void display(){
        if (top==-1){
            System.out.println("Stack is Empty!");
            return;
        }
        System.out.println("Items are: ");
        for (int j=top;j>=0;j--){
            System.out.print(arr[j]+" ");
        }
        System.out.println();
    }
}

public class StackDS {
    public static void main(String[] args) {
        StackImp s=new StackImp(10);
        s.push(1);
        s.push(2);
        s.push(3);
        s.display();
        s.pop();
        s.display();
        s.push(5);
        s.display();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.display();
    }
}
