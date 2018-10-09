package pkg;

public class LinearSearch{
	public static int linearSearch(int [] arr, int key) {
		int size = arr.length;
		for(int i = 0; i < size; i++) {
			if(arr[i] == key) {
				return i;
			}
		}
		return -1;
	}

	public static void main(String a[]) {
		int[] arr1 = {1, 4, 12, 435, 76};
		int searchKey = 4;
		System.out.println("Key " + searchKey + " found at index: " + linearSearch(arr1, searchKey));
	}
}
