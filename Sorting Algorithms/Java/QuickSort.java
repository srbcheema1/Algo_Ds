import java.util.Arrays;
// The best case time complexity is O(logN)
// we are moving to quick sort over merge sort because of space complexity here space complexity is O(1)
public class QuickSort {
    public static void main(String[] args) {
        int[] arr={4,1,3,2};
        int low=0;
        int high=arr.length-1;
        quick(arr,low,high);
        System.out.println(Arrays.toString(arr));
    }
    static void quick(int[] arr,int low,int high){
        if(low>=high){
            return;
        }
        int s=low;
        int e=high;
        int mid=s+(e-s)/2;
        int pivot =arr[mid];// middle element as pivot
        while(s<=e){
            while(arr[s]<pivot){
                s++;
            }
            while(arr[e]>pivot){
                e--;
            }
            if(s<=e){
                int t=arr[s];
                arr[s]=arr[e];
                arr[e]=t;
                s++;
                e--;
            }

        }
        quick(arr,low,e);
        quick(arr,s,high);

    }
}
