class BubbleSort {

    public static void main(String args[]) {
		BubbleSort bubbleSort = new BubbleSort();
        int arr[] = { 20, 40, 10, 70, 50, 60 };
        System.out.print("Array before sorting: ");
        bubbleSort.printArray(arr);
		bubbleSort.sort(arr);
		System.out.print("Sorted array: ");
		bubbleSort.printArray(arr);
    }
    
	void sort(int arr[]) {
		int n = arr.length;
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n-i-1; j++) {
				if (arr[j] > arr[j+1]) {
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
                }
            }   
        }
	}

	void printArray(int arr[]) {
        int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}
