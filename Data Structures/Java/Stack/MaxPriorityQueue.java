package priorityQueues;
import java.util.*;

public class MaxPriorityQueue {

	ArrayList<Integer> heap;
    MaxPriorityQueue(){
        heap=new ArrayList<>();
    }
    
    int getSize(){
        return heap.size();
    }
    
    boolean isEmpty(){
        return (heap.size()==0);
    }
    
    int getMax(){
        if(isEmpty()){
            return Integer.MIN_VALUE;
        }
        return heap.get(0);
    }
    
    void insert(int element){
		heap.add(element);
		int childIndex = heap.size() - 1;
		int parentIndex = (childIndex - 1) / 2;

		while(childIndex > 0){
			if(heap.get(childIndex) > heap.get(parentIndex)){
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
    
    int removeMax(){
        int maxValue=heap.get(0);
        int lastIndex=heap.size()-1;
        heap.set(0,heap.get(lastIndex));
        heap.remove(heap.size()-1);
        
        //down-Heapify
        int index=0;
        int maxIndex=index;
        int leftchildIndex=1;
        int rightchildIndex=2;
        while(leftchildIndex<heap.size()){

            if(heap.get(leftchildIndex)>heap.get(maxIndex)){
                maxIndex=leftchildIndex;
            }
            if(rightchildIndex<heap.size() && heap.get(rightchildIndex)>heap.get(maxIndex)){
                maxIndex=rightchildIndex;  
            }
            if(maxIndex==index){
                break;
            }
            int temp=heap.get(index);
            heap.set(index,heap.get(maxIndex));
            heap.set(maxIndex,temp);
            index=maxIndex;
            leftchildIndex=2*index+1;
            rightchildIndex=2*index+2;
            
        }
        
        return maxValue;
    }
}
