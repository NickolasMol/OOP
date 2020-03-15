using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace MyString_Text
{
    public class MyString
    {
        private char[] str;
        public char[] Str
        {
            get
            {
                return str;
            }
        }
        public int Length
        {
            get
            {
                return str.Length;
            }
            set
            {
                if(value > str.Length)
                {
                    char[] temp = str;
                    str = new char[value];
                    for (int i = 0; i < temp.Length; i++)
                        str[i] = temp[i];
                }
            }
        }

        public char this[int index]
        {
            get
            {
                return str[index];
            }
            set
            {
                str[index] = value;
            }
        }

        public static MyString operator +(MyString s1, MyString s2)
        {
            int L = s1.str.Length + s2.str.Length;

            var sumstr = new MyString(L);

            for (int i = 0; i < s1.str.Length; i++)
            {
                sumstr[i] = s1[i];
            }
            for (int i = 0; i < s2.str.Length; i++)
            {
                sumstr[s1.str.Length + i] = s2[i];
            }
            return sumstr;
        }
        public static MyString operator +(MyString s1,char s)
        {
            int L = s1.str.Length + 1;

            var sumstr = new MyString(L);

            for (int i = 0; i < L-1; i++)
            {
                sumstr[i] = s1[i];
            }
            sumstr[L-1] = s;
            return sumstr;
        }

        public static bool operator ==(MyString s1, MyString s2)
        {
            if (s1 == s2)
            {
                return true;
            }
            if (s1.str.Length != s2.str.Length)
            {
                return false;
            }
            for (int i = 0; i < s1.str.Length; i++)
            {
                if (s1[i] != s2[i])
                {
                    return false;
                }
            }
            return true;
        }

        public static bool operator !=(MyString s1, MyString s2)
        {
            return !(s1 == s2);
        }
        public bool is_alpha(char a)
        {
            if ((a == '1') || (a == '2') || (a == '3') || (a == '4') || (a == '5') || (a == '6') || (a == '7') || (a == '8') || (a == '9') || (a == '0'))
                return true;
            else
                return false;
        }

        public static explicit operator String(MyString MyStr)
        {
            return new String(ToArray(MyStr));
        }

        public static explicit operator MyString(String Str)
        {
            return new MyString(ToMyString(Str.ToCharArray()));
        }

        public static char[] ToArray(MyString MyStr)
        {
            char[] res = new char[MyStr.Length];
            for (int i = 0; i < MyStr.Length; i++)
            {
                res[i] = MyStr.str[i];
            }
            return res;
        }

        public static MyString ToMyString(char[] arr)
        {
            MyString res = new MyString(arr.Length);
            for (int i = 0; i < arr.Length; i++)
            {
                res.str[i] = arr[i];
            }
            return res;
        }
        public MyString(MyString previousMyString)
        {
            if (this == previousMyString)
            {
                throw new ArgumentException("Нельзя копировать строку саму в себя!");
            }
            str = new char[previousMyString.str.Length];
            for (int i = 0; i < previousMyString.str.Length; i++)
            {
                str[i] = previousMyString.str[i];
            }
        }

        public MyString()
        {
            str = null;
        }

        public MyString(int init_size)
        {
            str = new char[init_size];
        }
        public MyString(String StdStr)
        {
            str = new char[StdStr.ToCharArray().Length];
            str = StdStr.ToCharArray();
        }
        public MyString(char[] arr)
        {
            str = new char[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                str[i] = arr[i];
            }
        }

    }
    public class Text
    {
        private MyString[] text;
        public Text()
        {
            text = null;
        }
        public Text(int size)
        {
            text = new MyString [size];
        }
        public MyString this[int index]
        {
            get
            {
                return text[index];
            }
            set
            {
                text[index] = value;
            }
        }
        public int Size
        {
            get
            {
                return text.Length;
            }
            set
            {
                if(value > text.Length)
                {
                    MyString[] temp = text;
                    text = new MyString[value];
                    for(int i = 0; i < temp.Length; i++)
                    {
                        for(int j = 0; j < temp[i].Length; j++)
                        {
                            text[i][j] = temp[i][j];
                        }
                    }
                }
            }
        }
        public void Errase()
        {
            text = null;
        }
        public void Replace(int index , char[] line)
        {
            text[index] = new MyString(line);
        }
        public void add_row(MyString row)
        {
            int size = text.Length;
            MyString[] temp = new MyString[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = text[i];
            }
            text = new MyString[size + 1];
            for (int i = 0; i < size; i++)
            {
                text[i] = temp[i];
            }
            text[size] = row;
        }
        public void delete_row(int index)
        {
            int size = text.Length;
            for (int i = index; i < size - 1; i++)
            {
                text[i] = text[i + 1];
            }
            MyString[] temp = new MyString[size];
            for (int i = 0; i < size - 1; i++)
            {
                temp[i] = text[i];
            }
            text = new MyString[--size];
            for (int i = 0; i < size; i++)
            {
                text[i] = temp[i];
            }
        }
        public MyString find_all_numbers()
        {
            int size = text.Length;
            MyString numeric = new MyString("");
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < text[i].Length; j++)
                {
                    if (text[i].is_alpha(text[i][j]))
                    {
                        numeric = numeric + text[i][j];
                    }
                }
            }
            return numeric;
        }

    } 
}
