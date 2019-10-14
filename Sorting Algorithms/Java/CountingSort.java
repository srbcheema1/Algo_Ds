/**
 * Perfoms counting sort on array of characters
 */
class CountingSort 
{ 
    /**
	 * Perfoms counting sort on array of characters
	 * 
	 * @param arr an array of characters
	 */
	void sort(char arr[]) 
    { 
        int n = arr.length; 
  
        // The result character array that will have sorted arr 
        char result[] = new char[n]; 
  
        // Create a count array to store count of inidividul 
        // characters and initialize count array as 0 
        int count[] = new int[256]; 
        for (int i=0; i<256; ++i) 
            count[i] = 0; 
  
        // store count of each character 
        for (int i=0; i<n; ++i) 
            ++count[arr[i]]; 
  
        // Change count[i] so that count[i] now contains actual 
        // position of this character in result array 
        for (int i=1; i<=255; ++i) 
            count[i] += count[i-1]; 
  
        // Build the result character array 
        // To make it stable we are operating in reverse order. 
        for (int i = n-1; i>=0; i--) 
        { 
            result[count[arr[i]]-1] = arr[i]; 
            --count[arr[i]]; 
        } 
  
        // Copy the result array to arr, so that arr now 
        // contains sorted characters 
        for (int i = 0; i<n; ++i) 
            arr[i] = result[i]; 
    } 
  
    /**
	 * Driver method to trigger call counting sort
	 */
    public static void main(String args[]) 
    { 
        CountingSort coutingSort = new CountingSort(); 
        char arr[] = {'a', 'c', 'k', 'l', 's', 'm', 'd', 
                    't', 'h', 'f', 'e', 'a', 'w'
                    }; 
  
        coutingSort.sort(arr); 
  
        System.out.println("Sorted array is "); 
        for (int i=0; i<arr.length; ++i) 
            System.out.print(arr[i]); 
    } 
} 