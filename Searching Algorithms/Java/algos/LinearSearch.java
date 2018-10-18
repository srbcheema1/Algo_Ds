package asset;

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
}
