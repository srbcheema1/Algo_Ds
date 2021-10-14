import java.util.Arrays;

public class QuickSort {
    public static void main(String[] args) {
        int[] arr = {5,75,3,65,2,1,3,4,4,88};
        System.out.println(Arrays.toString(arr));
        quickSort(arr, 0, arr.length-1);
        System.out.println(Arrays.toString(arr));
    }

    public static void quickSort(int[] arr, int leftStart, int rightEnd){
        if(leftStart < rightEnd){
            int partition = partition(arr, leftStart, rightEnd);
            quickSort(arr, leftStart, partition - 1);
            quickSort(arr, partition+1, rightEnd);
        }
    }

    public static int partition(int[] arr, int low, int high){

        // improved performance when the array is already sorted
        int mid = low + (high - low) / 2;
        swap(arr, mid, high);

        // choosing the high as the pivot
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++){
            if(arr[j] <= pivot){
                i++;
                swap(arr, j, i);
            }
        }

        swap(arr, high, i+1);

        return i+1;
    }

    public static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
