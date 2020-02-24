// lab1++.cpp : 
#include <iostream>
using namespace std;

void ppone(int& x) {
    int m = 1;
    while (x & m)
    {
        x = x ^ m;
        m <<= 1;
    }
    x = x ^ m;
}

int ppprone(int& x) {
    int m = 1;  
    while (x & m)
    {
        x = x ^ m;
        m <<= 1;
    }
    x = x ^ m;
    return x;
}

void more(int a, int b , bool& rez) {
    while (b != 0)
    {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    rez = ~(a >> sizeof(a));
}
bool morer(int a, int b ) {
    while (b != 0)  
    {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    bool rez = ~(a >> );
    return rez;
}
int main()
{   
    bool sw;
    int n = -128;
    int a = -13;
    int b = 124;
    more(a , b , sw);
    //ppone(n);
    cout<<ppprone(n);
}

