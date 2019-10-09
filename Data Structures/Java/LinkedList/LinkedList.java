import java.util.Scanner;

public class LinkedList {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Node start = null, temp = null, newNode;
        int ele;
        while((ele = scan.nextInt()) > 0) {
            if(start == null) {
                start = new Node();
                start.setValue(ele);
                start.setNext(null);
                temp = start;
            }
            else {
                newNode = new Node();
                newNode.setValue(ele);
                newNode.setNext(null);
                temp.setNext(newNode);
                temp = newNode;
            }
        }
        System.out.println("ELEMENTS ARE: ");
        temp = start;
        while(temp != null) {
            System.out.print(temp.getValue() + " ");
            temp = temp.getNext();
        }
    }
}
