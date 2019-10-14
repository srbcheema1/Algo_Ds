import java.io.*; 
import java.util.*; 

/**
 * Peforms Radix Sort
 */ 
class RadixSort { 
  
    /**
     * Gets Maximum value in an array
	 *
     * @param arr an array of integers
	 * @param n length of the array
     */	 
    static int getMaximum(int arr[], int n) 
    { 
        int max = arr[0]; 
        for (int i = 1; i < n; i++) 
            if (arr[i] > max) 
                max = arr[i]; 
        return max; 
    } 
  
    /**
     * Performs counting sort on the given array
	 *
     * @param arr an array of integers
	 * @param n length of the array
	 * @param exp the radix based on which array need to be sorted
     */	 
    static void countSort(int arr[], int n, int exp) 
    { 
        int output[] = new int[n]; // output array 
        int i; 
        int count[] = new int[10]; 
        Arrays.fill(count,0); 
  
        // Store count of occurrences in count[] 
        for (i = 0; i < n; i++) 
            count[ (arr[i]/exp)%10 ]++; 
  
        // Change count[i] so that count[i] now contains 
        // actual position of this digit in output[] 
        for (i = 1; i < 10; i++) 
            count[i] += count[i - 1]; 
  
        // Build the output array 
        for (i = n - 1; i >= 0; i--) 
        { 
            output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
            count[ (arr[i]/exp)%10 ]--; 
        } 
  
        // Copy the output array to arr[], so that arr[] now 
        // contains sorted numbers according to curent digit 
        for (i = 0; i < n; i++) 
            arr[i] = output[i]; 
    } 
  
    /**
	 * Performs radix sort on the given array 
	 *
	 * @param arr an array of integers
	 * @param n length of the array
	 */
    static void radixsort(int arr[], int n) 
    { 
        // Find the maximum number to know number of digits 
        int m = getMaximum(arr, n); 
  
        // Do counting sort for every digit. Note that instead 
        // of passing digit number, exp is passed. exp is 10^i 
        // where i is current digit number 
        for (int exp = 1; m/exp > 0; exp *= 10) 
            countSort(arr, n, exp); 
    } 
  
    /**
	 * An utility function to print an array
	 *
	 * @param array an array of integers
	 * @param n length of the array
	 */
    static void printArray(int array[]) 
    { 
        for (int i: array) {
            System.out.print(i+" "); 
        }	
        System.out.println(); 
    } 
  
  
    
    public static void main (String[] args) 
    { 
        int arr[] = {780, 45, 58, 78, 458, 478, 12, 94}; 
        int n = arr.length; 
        radixsort(arr, n); 
		System.out.println("the sorted array is ");
        printArray(arr, n); 
    } 
}