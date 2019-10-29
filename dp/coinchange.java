import java.util.Arrays;
import java.util.Scanner;

public class CoinChange {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int n = scn.nextInt();
		int m = scn.nextInt();
		int[] arr = new int[m];
		for (int i = 0; i < m; i++) {
			arr[i] = scn.nextInt();
		}
// 		int[] strg = new int[n + 1];
// 		Arrays.fill(strg, -1);
// 		System.out.println(CoinChange(arr, n, 0, 0));
// 		System.out.println(CoinChangeTD(arr, n, 0, 0, strg));
		System.out.println(CoinChangeBU(arr, n));
	}

	public static int CoinChange(int[] arr, int total, int curr, int idx) {
		if (total == curr) {
			return 1;
		}
		if (curr > total) {
			return 0;
		}

		int res = 0;
		for (int i = idx; i < arr.length; i++) {
			res += CoinChange(arr, total, curr + arr[i], i);
		}
		return res;
	}

	public static int CoinChangeTD(int[] arr, int total, int curr, int idx, int[] strg) {
		if (total == curr) {
			return 1;
		}
		if (curr > total) {
			return 0;
		}
		if (strg[curr] != -1) {
			return strg[curr];
		}

		int res = 0;
		for (int i = idx; i < arr.length; i++) {
			res += CoinChange(arr, total, curr + arr[i], i);
		}
		strg[curr] = res;
		return res;

	}

	public static int CoinChangeBU(int[] arr, int total) {
		int[] strg = new int[total + 1];
		strg[0] = 1;

		for(int i=0;i<arr.length;i++) {
			
			for(int mon = 1;mon<strg.length;mon++) {
				if(mon-arr[i]<0) {
					continue;
				}
				strg[mon]=strg[mon]+strg[mon-arr[i]];
			}
		}

		return strg[total];
	}
}
