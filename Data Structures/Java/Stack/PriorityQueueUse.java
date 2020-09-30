package priorityQueues;

public class PriorityQueueUse {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		MaxPriorityQueue maxpq=new MaxPriorityQueue();
		int arr[]= {5,6,9,10,83,65,1};
		for(int i=0;i<arr.length;i++) {
			maxpq.insert(arr[i]);
		}
		
		while(!maxpq.isEmpty()) {
			System.out.print(maxpq.removeMax()+" ");
		}
		
		System.out.println();
		
		MinPriorityQueue minpq=new MinPriorityQueue();
		int a[]= {5,6,9,10,83,65,1};
		for(int i=0;i<a.length;i++) {
			minpq.insert(a[i]);
		}
		
		while(!minpq.isEmpty()) {
			System.out.print(minpq.removeMin()+" ");
		}
	}

}
