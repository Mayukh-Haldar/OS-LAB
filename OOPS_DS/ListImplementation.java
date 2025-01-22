package datastructures;
import java.util.ArrayList;
import java.util.Collections;

public class ListImplementation {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(1);
        list.add(2);
        list.add(3);
        System.out.println(list);
        int ele=list.get(0);
        System.out.println(ele);
        list.add(1,0);
        System.out.println(list);
        list.set(0,5);
        System.out.println(list);
        list.remove(3);
        System.out.println(list);
        System.out.println(list.size());
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i)+" ");
        }
        System.out.println();
        Collections.sort(list);
        System.out.println(list);
    }
}
