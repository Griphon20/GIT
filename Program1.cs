using System;
using System.Linq;
using System.Collections;


namespace lab1
{
    class Program
    {
        public static void Main()
        {
            Console.WriteLine(HW1.QueueTime(new int[] { 5, 3, 4 }, 1) == 12);
            Console.WriteLine(HW1.QueueTime(new int[] { 10, 2, 3, 3 }, 2) == 10);
            Console.WriteLine(HW1.QueueTime(new int[] { 2, 3, 10 }, 2) == 12);


        }
    }
    public class HW1
    {
        public static long QueueTime(int[] customers, int n)
        {
            int theTime = 0;
            while (customers.Length > 0)
            {
                int cassazan = n > customers.Length ? customers.Length : n;
                for (int x = 0; x < cassazan; x++)
                {
                    customers[x]--;
                }
                customers = Array.FindAll(customers, y => y != 0);

                theTime++;
            }
            return theTime;
        }
    }
}