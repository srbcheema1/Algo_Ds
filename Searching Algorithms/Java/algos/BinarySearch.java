package asset;

public class BinarySearch{
	public static int binarySearch(int [] arr, int key, int low, int high) {
		int index = Integer.MAX_VALUE;
		
		while (low <= high) {
			int mid = (low + high) / 2;
			if(arr[mid] < key) {
				low = mid + 1;
			}
			else if (arr[mid] > key) {
				high = mid - 1;
			}
			else if (arr[mid] == key) {
				index = mid;
				break;
			}
			else
				return -1;
		}
		return index;
	}
}
