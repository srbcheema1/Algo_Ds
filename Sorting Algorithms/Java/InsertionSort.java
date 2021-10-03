//Insertion sort using Java
/*The concept behind Insertion Sort divides the range into subarrays that are sorted and unsorted. 
The classified portion is at the start of duration 1 and matches the first (left side) component in the array.
We move through the array and expand the classified part of the array by one component during every iteration. When we expand
, we position the fresh element in the sorted sub-array. We do this by moving all the elements to the right until we find that 
we don’t have to change the first component. 
*/
public class InsertionSort{
  
public static void insertionSort(int[] arr) {
       for (int x = 1; x < arr.length; x++) {
       int current = arr[x];
        int y = x - 1;
        while(y >= 0 && current < arr[y]) {
        arr[y+1] = arr[y];
        y--;
}
arr[y+1] = current;
}
}
  
public static void main(String a[]){
int[] arr1 = {3,5,7,8,4,2,1,9,6};
 //printing before sorting
System.out.println("Before Sorting");
for(int x:arr1){
System.out.print(x+" ");
}
System.out.println();
insertionSort(arr1);//sorting array using insertion sort
 //printing after sorting 
System.out.println("After Insertion Sorting");
for(int x:arr1){
System.out.print(x+" ");
}
}
}
