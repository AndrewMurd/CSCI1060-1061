bool gt(int a, int b)
{
    return a > b;
}

bool (*l)(int a, int b);
//l = gt;

#include <iostream>

int square(int x)
{
        return x*x;
}

int neg(int x)
{
    return -x;
}

int do_some_process(int (*fn)(int), int x)
{
    return fn(x);
}

int main()
{
    int x = 5;

    //cout << do_some_process(square, x) << endl;
    //cout << do_some_process(neg, x) << endl;

    return 0;
}

#include <iostream>

using std::cout; 
using std::endl;

class Square {
    public:
    
    int operator()(int x) { 
        return x*x; 
    } 
};

class Neg { 
    public:
    
    int operator()(int x) { 
        return -x; 
    } 
};

int timestwo(int x)
{
    return 2*x;
}

template<typename T> 
int do_some_process(T process, int x)
{
    return process(x);
}

int main() 
{
    Square a;
    Neg b;
    int x = 9;

    cout << do_some_process(a, x) << endl;
    cout << do_some_process(b, x) << endl;
    cout << do_some_process(timestwo, x) << endl;
    
    return 0; 
}

#include <iostream>
using std::cout; 
using std::endl;

int main() 
{
    int val = 11;
    cout << [](int x){ return x*x; }(val) << endl;
    
    return 0; 
}

#include <iostream>
using std::cout; 
using std::endl;

int main() 
{
    auto func = [](int x)->int{ return x*x; };
    
    int x = 11;
    cout << func(x) << endl;
    
    return 0; 
}