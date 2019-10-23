using System;

class LinearSearch
{
    public static int search(int[] arr, int x)
    {
        int n = arr.Length;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                return i;
        }
        return -1;
    }

    public static void Main()
    {
        int[] arr = { 7,9,8,11,15,243};
        int x = 11;

        int result = search(arr, x);
        if (result == -1)
            Console.WriteLine("Element is not present in array");
        else
            Console.WriteLine("Element is present at index " + result);
    }
}