package datastructures;

import java.util.Scanner;

public class ArrayCreation {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array");
        n = sc.nextInt();
        int[] arr = new int[n];
        int[] arr2 = new int[n+1];
        int[] arr3 = new int[n];
        System.out.println("Enter the elements of array");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Elements in array: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        System.out.println("Enter the index: ");
        int idx = sc.nextInt();
        System.out.println("Enter the value to be inserted: ");
        int val = sc.nextInt();
        for (int i = 0; i < n+1; i++) {
            if (i<idx){
                arr2[i] = arr[i];
            }else if (i==idx){
                arr2[i]=val;
            }else{
                arr2[i] = arr[i-1];
            }
        }
        for (int i = 0; i < n+1; i++) {
            System.out.print(arr2[i] + " ");
        }
        System.out.println();
        System.out.println("Enter the index to be deleted: ");
        int id2 = sc.nextInt();
        for (int i = 0; i < arr2.length; i++) {
            if (i<id2){
                arr3[i] = arr2[i];
            }
            else if (i==id2){
                continue;
            }else{
                arr3[i-1] = arr2[i];
            }
        }
        for (int i = 0; i < arr2.length-1; i++) {
            System.out.print(arr3[i] + " ");
        }
        System.out.println();
    }
}
