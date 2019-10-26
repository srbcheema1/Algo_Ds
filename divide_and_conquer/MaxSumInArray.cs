using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Max_Sum_in_Array
    {

        static int maxSum(int[] a, int size)
        {
            int max = a[0];
            int curr_max = a[0];

            for (int i = 1; i < size; i++)
            {
                curr_max = Math.Max(a[i], curr_max + a[i]);
                max = Math.Max(max, curr_max);
            }

            return max;
        }

        public static void Main()
        {
            int[] a = new int[10];
            Console.WriteLine("Enter 10 digits for array");

            for (int i = 0; i < 10; i++)
            {
                a[i] = Convert.ToInt32(Console.ReadLine());
            }
            int sum = maxSum(a, 10);
            Console.Write("Max sum is " + sum);

        }
    }
}
