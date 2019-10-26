using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class possible_strings
    {

        public void Permute(string[] list, int f, int l)
        {
            int i;
            if (f == l)
            {
                for (i = 0; i <= l; i++)
                    Console.Write("{0}", list[i]);
                Console.Write(" ");
            }
            else
                for (i = f; i <= l; i++)
                {
                    swap(ref list[f], ref list[i]);
                    Permute(list, f + 1, l);
                    swap(ref list[f], ref list[i]);
                }
        }

        public void swap(ref string a, ref string b)
        {
            string temp = a;
            a = b;
            b = temp;
        }

        public static void Main()
        {
            int i;

            string[] a = new string[3];

            possible_strings obj = new possible_strings();

            Console.Write(" Enter 3 alphabets/numbers to :");

            for (i = 0; i < 3; i++)
            {
                a[i] = Console.ReadLine();
            }

            Console.WriteLine("The Permutations are:");
            obj.Permute(a, 0, 2);
            Console.Write("\n\n");

        }

    }
}
