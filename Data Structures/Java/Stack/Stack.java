import java.lang.IndexOutOfBoundsException;
import java.util.Arrays;

public class Stack<E> {
    private int max;
    private int top;
    private Object[] list;

    public Stack() {
        max = 512;
        top = 0;
        list = new Object[max];
    }

    public Stack(int size) {
        max = size;
        top = 0;
        list = new Object[max];
    }

    @SuppressWarnings("unchecked")
    public boolean isEmpty() {
        for(E t : (E[]) list) {
            if(t != null) {
                return false;
            }
        }

        return true;
    }

    @SuppressWarnings("unchecked")
    public E peek() {
        return (E) list[top];
    }

    @SuppressWarnings("unchecked")
    public int size() {
        if(top == 0) {
            return 0;
        }

        int count = 0;
        for(E t : (E[]) list) {
            if(t != null) {
                count++;
            }
        }

        return count;
    }

    @SuppressWarnings("unchecked")
    public E pop() {
        if(isEmpty()) {
            throw new IndexOutOfBoundsException("This stack is empty; nothing to pop.");
        }

        E data = (E) list[top];

        top = (top == 0 ? 0 : top - 1);
        return data; 
    }

    public void push(E data) {
        if(top == max - 1) {
            list = Arrays.copyOf(list, list.length * 2);
        }

        top++;
        list[top] = data;
    }
}
