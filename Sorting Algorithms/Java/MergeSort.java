package test;

public class test {

	public static void main(String[] args) {

		String[] nums = { "AB", "DD", "CC", "BB", "CA", "AA" };

		mergeSort(nums, 0, nums.length - 1);

		System.out.println("Sorted character strings : ");
		for (String i : nums) {
			System.out.println(i);
		}
	}

	public static void mergeSort(String[] a, int low, int high) {
		int mid;
		if (low < high) {
			mid = (low + high) / 2;
			mergeSort(a, low, mid);
			mergeSort(a, mid + 1, high);
			merge(a, low, mid, high);
		}
	}

	public static void merge(String[] a, int low, int mid, int high) {

		int i, l, r, k;
		String[] temp = new String[a.length];
		i = low;
		l = low;
		r = mid + 1;

		while (l <= mid && r <= high) {
			int letter = 0;
			boolean elementAdded = false;
			while (letter < a[l].length() && letter < a[r].length()) {
				if (a[l].charAt(letter) < a[r].charAt(letter)) {
					temp[i] = a[l];
					elementAdded = true;
					l++;
					break;
				}

				else if (a[l].charAt(letter) > a[r].charAt(letter)) {
					temp[i] = a[r];
					elementAdded = true;
					r++;
					break;
				}
				letter++;
			}

			if (!elementAdded) {
				if (a[l].length() < a[r].length()) {
					temp[i] = a[l];
					l++;
				} else {
					temp[i] = a[r];
					r++;
				}
			}

			i++;
		}

		if (l > mid) {
			for (k = r; k <= high; k++) {
				temp[i] = a[k];
				i++;
			}
		}

		else {
			for (k = l; k <= mid; k++) {
				temp[i] = a[k];
				i++;
			}
		}

		for (k = low; k <= high; k++) {
			a[k] = temp[k];
		}
	}
}
