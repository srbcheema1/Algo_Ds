public class JumpSearch 
{ 
    public static int search(int[] array, int target) 
    { 
        int n = array.length; 
  
        /
        int step = (int)Math.floor(Math.sqrt(n));  // Finding block size to be jumped 
  
        // Finding the block where element is present (if it is present) 
		
        int prev = 0; 
        while (array[Math.min(step, n)-1] < target) 
        { 
            prev = step; 
            step += (int)Math.floor(Math.sqrt(n)); 
            if (prev >= n) 
                return -1; 
        } 
  
        // Doing a linear search for target in block beginning with prev.
 
        while (array[prev] < target) 
        { 
            prev++; 
  
            // If we reached next block or end of 
            // array, element is not present. 
            if (prev == Math.min(step, n)) 
                return -1; 
        } 
  
        // If element is found 
        if (array[prev] == target) 
            return prev; 
  
        return -1; 
    } 
  
    /**
	 * Driver method to test the program 
	 */ 
    public static void main(String[] args) 
    { 
        int array[] = { 0, 1, 1, 2, 3, 5, 8, 15, 21, 
                    34, 64, 98, 154, 243, 388,465}; 
        int target = 64; 
  
        // Find the index of 'target' using Jump Search 
        int index = search(array, target); 
  
        // Print the index where 'target' is located 
		if(index != -1) {
           System.out.println("\nNumber " + target + " is at index " + index); 
		}
        else {
           System.out.println(" "+target+" is not found in the given array");
        }		
    } 
} 