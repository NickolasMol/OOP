using System;
namespace lab1sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 128;
            int b = -14;
        }
        static void ppone(ref int x)
        {
            int m = 1;
            while (Convert.ToBoolean(x & m))
            {
                x = x ^ m;
                m <<= 1;
            }

            // flip the rightmost 0 bit  
            x = x ^ m;
        }
        static int pponer(int x)
        {
            int m = 1;
            while (Convert.ToBoolean(x & m))
            {
                x = x ^ m;
                m <<= 1;
            }

            // flip the rightmost 0 bit  
            x = x ^ m;
            return x;
        }
        static void more(ref int a, ref int b , ref int rez)
        {
            while (b != 0)
            {
                int borrow = (~a) & b;
                a = a ^ b;
                b = borrow << 1;
            }
            rez = ~(a >> 31);
        }
        static int morer( int a ,  int b)
        {
            while (b != 0)
            {
                int borrow = (~a) & b;
                a = a ^ b;
                b = borrow << 1;
            }
            int rez = ~(a >> 31);
            return rez;
        }
    }
}