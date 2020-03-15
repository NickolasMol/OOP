#include<iostream>
using namespace std;

class MyString
{
public:

    //конструктор без параметров
    MyString()
    {
        str = nullptr;
        length = 0;
    }

    //конструктор с параметрами, при создании объекта класса необходимо перелать строку которую он будет хранить

    MyString(const char* str)
    {

        length = strlen(str);// функция strlen получает количество символов в строке которую мы передаём в объект

        // выделяем память для динамического массива где будет храниться наша строка
        // +1 символ так как нужно место в массиве под терминирующий 0
        this->str = new char[length + 1];

        // копируем символы строки в массив нашего класса
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }

        //закрываем строку терминирующим нулём
        this->str[length] = '\0';

    }
    // деструктор, отвечает за освобождение ресурвов занятых объектом, вызывается при уничтожении объекта класса
    ~MyString()
    {
        delete[] this->str;
    }

    // конструктор копировании, необходим для создании точной копи объекта класса но в другой области памяти
    MyString(const MyString& other)
    {
        this->str = new char[1];
        length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[length] = '\0';
    }

    MyString& operator =(const MyString& other)
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }

        length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[length] = '\0';

        return *this;

    }
    MyString& operator =(const char* other)
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }

        length = strlen(other);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = other[i];
        }

        this->str[length] = '\0';

        return *this;

    }

    MyString operator+(const MyString& other)
    {
        //создаём новый пустой объект где будим хранить результат конкатенации строк и который будет результатом работы
        // перегруженного оператора +
        MyString newStr;
        // получаем количество символов в обеих строках для конкатенации

        int thisLength = strlen(this->str);
        int otherLength = strlen(other.str);

        newStr.length = thisLength + otherLength;

        // выделяем место в динамической памяти под новую строку
        newStr.str = new char[thisLength + otherLength + 1];

        //копируем данные из 2х конкатенируемых строк в новую строку
        int i = 0;
        for (; i < thisLength; i++)
        {
            newStr.str[i] = this->str[i];
        }

        for (int j = 0; j < otherLength; j++, i++)
        {
            newStr.str[i] = other.str[j];
        }

        newStr.str[thisLength + otherLength] = '\0';
            // возвращаем результат конкатенации
        return newStr;
    }

    MyString operator+(const char other)
    {
        //создаём новый пустой объект где будим хранить результат конкатенации строк и который будет результатом работы
        // перегруженного оператора +
        MyString newStr;
        // получаем количество символов в обеих строках для конкатенации

        int thisLength = strlen(this->str);
        int otherLength = 1;

        newStr.length = thisLength + otherLength;

        // выделяем место в динамической памяти под новую строку
        newStr.str = new char[thisLength + otherLength + 1];

        //копируем данные из 2х конкатенируемых строк в новую строку
        for (int i = 0; i < thisLength; i++)
        {
            newStr.str[i] = this->str[i];
        }
        newStr.str[thisLength] = other;
        newStr.str[thisLength + otherLength] = '\0';
        // возвращаем результат конкатенации
        return newStr;
    }
    // выводит строку в консоль, в идеале для этого необходима перегрузка оператора «
    void Print()
    {
        cout << str;
    }

    int Length()
    {
        return length;
    }

    bool operator ==(const MyString& other)
    {
        if (this->length != other.length)
        {
            return false;
        }

        for (int i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator !=(const MyString& other)
    {
        return !(this->operator==(other));
    }

    char& operator [](int index)
    {
        return this->str[index];
    }

    bool is_alpha(char a)
    {
        if ((a == '1') || (a == '2') || (a == '3') || (a == '4') || (a == '5') || (a == '6') || (a == '7') || (a == '8') || (a == '9') || (a == '0'))
            return true;
        else
            return false;
    }

    MyString(MyString &&other )
    {
        this->length = other.length;
        this->str = other.str;
        other.str = nullptr;

    }

private:
    char* str;

    int length;
};


class Text
{
public:
    Text() {
        size = 0;
        rows = nullptr;
    }

    Text(int size) {
        this->size = size;
        rows = new MyString[size];
    }

    ~Text() {
        delete[] rows;
        rows = nullptr;
        size = 0;
    }

    void Errase() {
        size = 0;
        rows = nullptr;
    }
    
    MyString& operator [](int index)
    {
        return this->rows[index];
    }

    void addRow(MyString row) {
        MyString* temp = new MyString[size];
        for (int i = 0; i < size; i++) {
            temp[i] = rows[i];
        }
        delete[] rows;
        rows = new MyString[size + 1];
        for (int i = 0; i < size; i++) {
            rows[i] = temp[i];
        }
        rows[size] = row;
        size++;
        delete[] temp;
    }

    void delete_row(int index) {
        for (int i = index; i < size-1; i++) {
            rows[i] = rows[i + 1];
        }
        MyString* temp = new MyString[size];
        for (int i = 0; i < size-1; i++) {
            temp[i] = rows[i];
        }
        delete[] rows; size--;
        rows = new MyString[size];
        for (int i = 0; i < size; i++) {
            rows[i] = temp[i];
        }
        delete[] temp;
    }

    MyString numeric_stroke() {
        MyString numeric = MyString("");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < rows[i].Length(); j++) {
                if (rows[i].is_alpha(rows[i][j])) {
                    numeric = numeric + rows[i][j];
                }
            }
        }
        return numeric;
    }

    int get_size() { return size; }

private:
    int size = 1;
    MyString* rows;
};

int main()
{
    Text txt = Text(3);
    txt[0] = "Dear1!";
    txt[1] = "He2llo";
    txt[2] = "Priv5et";
    cout << endl << "Size of text is ->";
    cout << txt.get_size() << endl;
    txt.delete_row(2);
    txt.addRow("Kolya");
    txt[2].Print();
    cout<<endl<< "CIFRI ->";
    MyString s = txt.numeric_stroke();
    s.Print();
    //cout<<txt.get_size();
    MyString str("Hello ");
    MyString str2("World!");
    MyString result;
    result = str + str2;
    return 0;
}