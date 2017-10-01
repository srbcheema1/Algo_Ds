public class countsort 
{
    public static void sort (char arr[]) 
    {
        int n = arr.length;

        char output[] = new char[n];

        int count[] = new int[256];
        for (int i = 0; i < n; ++i)
            count[i] = 0;

        for (int i = 0 ; i < n; ++i)
            ++count[arr[i]];

        for (int i = 1; i <= 255; ++i)
            count[1] += count[i - 1];

        for (int i = 0; i < n; ++i)
        {
            output[count[arr[i]] - 1] = arr[i];
            --count[arr[i]];
        }

        for (int i = 0; i < n; ++i)
            arr[i] = output[i];
    }

    public static void main(String args[])
    {
        char arr[] = {'h','a','c','t','o','b',
        'e','r','f','e','s','t'};

        sort(arr);

        System.out.print("Sorted character array is: ");
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i]);
    }
}