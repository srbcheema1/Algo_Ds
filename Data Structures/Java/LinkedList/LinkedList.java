public class LinkedList {
  private class Node {
      Node next;
      String item;
      
      public Node(String item, Node next) {
          this.item = item;
          this.next = next;
      }
  }
  Node head;
  
  LinkedList() {
    head = null;
  }
  
  public boolean isEmpty() {
    return head == null;
  }
  
  public int size() {
      Node curr = head;
      int size = 0;
      while(curr != null) {
         size++;
      }
      return size;
  }
  public void insert(String item) {
    if(head == null) {
      head = new Node(item, null);
    }
    else {
      Node curr = head;
      while(curr.next != null) {
        curr = curr.next;
      }
      curr.next = new Node(item, null);
    }
  }
  
  public void delete(int index) {
    if(head.next == null) {
      head = null;
    }
    Node curr = head, prev = null;
    for(int i = 0; i < size(); i++) {
      prev = curr;
      curr = curr.next;
    }
    prev.next = curr.next;
  }
}
