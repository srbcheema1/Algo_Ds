package priorityQueues;
import java.util.*;

public class MinPriorityQueue {
	
	private ArrayList<Integer> heap;

	public MinPriorityQueue() {
		heap = new ArrayList<Integer>();
	}

	boolean isEmpty(){
		return heap.size() == 0;
	}

	int size(){
		return heap.size();
	}

	int getMin() throws PriorityQueueException{
		if(isEmpty()){
			// Throw an exception
			throw new PriorityQueueException();
		}
		return heap.get(0);
	}

	void insert(int element){
		heap.add(element);
		int childIndex = heap.size() - 1;
		int parentIndex = (childIndex - 1) / 2;

        //up-heapify
		while(childIndex > 0){
			if(heap.get(childIndex) < heap.get(parentIndex)){
				int temp = heap.get(childIndex);
				heap.set(childIndex, heap.get(parentIndex));
				heap.set(parentIndex, temp);
				childIndex = parentIndex;
				parentIndex = (childIndex - 1) / 2;
			}else{
				return;
			}
		}
	}

	int removeMin() {
        int minValue=heap.get(0);
        int lastIndex=heap.size()-1;
        heap.set(0,heap.get(lastIndex));
        heap.remove(heap.size()-1);
        
        //down-Heapify
        int index=0;
        int minIndex=index;
        int leftchildIndex=1;
        int rightchildIndex=2;
        while(leftchildIndex<heap.size()){

            if(heap.get(leftchildIndex)<heap.get(minIndex)){
                minIndex=leftchildIndex;
            }
            if(rightchildIndex<heap.size() && heap.get(rightchildIndex)<heap.get(minIndex)){
                minIndex=rightchildIndex;  
            }
            if(minIndex==index){
                break;
            }
            int temp=heap.get(index);
            heap.set(index,heap.get(minIndex));
            heap.set(minIndex,temp);
            index=minIndex;
            leftchildIndex=2*index+1;
            rightchildIndex=2*index+2;
            
        }
        
        return minValue;
	}

}
