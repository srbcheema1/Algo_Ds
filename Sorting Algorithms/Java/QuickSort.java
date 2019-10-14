/**
 * Class to Peform Quick Sort on an array of integers
 */
class QuickSort 
{ 
    
	/**
	 * Partitions the given array into two partitions with respect to the last number
	 * 
	 * @param array an array of integers
	 * @param low index of left most element
	 * @param high index of right most element
	 */
    int partition(int array[], int low, int high) 
    { 
        int pivot = array[high];  
        int i = low - 1; // index of the smaller element 
        for (int j=low; j<=high-1; j++) 
        { 
            // If the current element is smaller than the pivot 
            if (array[j] < pivot) 
            { 
                i++; 
  
                // swap array[i] and array[j] 
                int temp = array[i]; 
                array[i] = array[j]; 
                array[j] = temp; 
            } 
        } 
  
        // swap array[i+1] and array[high] (or pivot) 
        int temp = array[i+1]; 
        array[i+1] = array[high]; 
        array[high] = temp; 
  
        return i+1; 
    } 
  
  
    /**
	 * Sorts the given array with quick sort
	 * 
	 * @param array an array of integers
	 * @param low index of left most element
	 * @param high index of right most element
	 */
    void sort(int array[], int low, int high) 
    { 
        if (low < high) 
        { 
            
            int pivotIndex = partition(array, low, high); //
  
            // Recursively sort elements in left and right partitions
			
            sort(array, low, pivotIndex-1); 
            sort(array, pivotIndex+1, high); 
        } 
    } 
  
    
    static void printArray(int array[]) 
    { 
        for (int i: array) {
            System.out.print(i+" "); 
        }	
        System.out.println(); 
    } 
  
    public static void main(String args[]) 
    { 
        int array[] = {10, 7, 8, 9, 1, 5}; 
        int n = array.length; 
         
        System.out.println("Performing Quick Sort");
		
        QuickSort ob = new QuickSort(); 
        ob.sort(array, 0, n-1); 
  
        System.out.println("sorted array is "); 
        printArray(array); 
    } 
} 
