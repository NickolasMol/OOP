using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyString_Text;
namespace lab2sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] ins = { 'd', 's', 'a', 'm' , 'a' , 'l' , };
            Text Letter = new Text(3);
            Letter[0] = new MyString("Hello 123");
            Letter[1] = new MyString("Dear 456");
            Letter[2] = new MyString("How are you 789");
            int result = Letter.Size;
            Console.Out.WriteLine(result);
            Letter.Replace(1, ins);
            Console.Out.WriteLine(Letter[1].Str);
            Console.Out.WriteLine(Letter.find_all_numbers().Str);

            Letter.Errase();
            MyString additionstr = new MyString("Kolya mega men");
            Letter.add_row(additionstr);
            for(int i=0;i<Letter.Size;i++)
                Console.Out.WriteLine(Letter[i].Str);
            result = Letter.Size;
            Console.Out.WriteLine(result);
            Console.ReadLine();
        }
    }
}
