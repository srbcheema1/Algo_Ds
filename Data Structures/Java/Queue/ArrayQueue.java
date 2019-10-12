
public class ArrayQueue {
	int arr[];
	int front,rear;
	int MAXSIZE;
	ArrayQueue(int k){
		arr=new int[k];
		MAXSIZE=k;
		front=-1;
		rear=-1;
	}
	void enaq(int key) {
		if((rear+1)%MAXSIZE==front) {
			System.out.println("Queue is full");
		}
		else if (front==-1 && rear==-1) {
			front =0;
			rear=0;
			arr[rear]=key;
		}
		else {
			rear=(rear+1)%MAXSIZE;
			arr[rear]=key;
		}
	}
	int deaq() {
		if(front==-1 && rear==-1) {
			return Integer.MAX_VALUE;
		}
		else if(front==rear) {
			int val=arr[rear];
			front=-1;
			rear=-1;
			return val;
		}
		else {
			int val=arr[front];
			front=(front+1)%MAXSIZE;
			return val;
		}
	}
	void arqprint() {
		for(int i=front;i<=rear;i++) {
			System.out.println(arr[i]);
		}
	}
}
