// c_and_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>


#include <iostream>
#include<algorithm>
#include <fstream>
#include <string>
#include <stack>
#include<vector>

using namespace std;
//12.1 last K lines

void last_klines(int k) {


    stack<string> my_stack;
    ifstream infile("thefile.txt");
    string line;
    while (getline(infile, line))
        my_stack.push(line);
    if (my_stack.size() < k)
         cout << "line number is bigger than file!" << endl;
    else
        while (k != 0) { cout << my_stack.top() << endl;; my_stack.pop(); k--; }
}

//12.2 reverse string
// uising algorithm library
void reverseV1(char* str,int size) {
    reverse(str, str+size);
    for (int i = 0; i < size; i++)
        cout << *(str + i);
}
//reversing using stack data structure.
void reverseV2(char* str, int size) {
   
    stack<char>my_c_stack;
    for (size_t i = 0; i < size; i++)
        my_c_stack.push(*(str + i));

    while (!my_c_stack.empty())
    {
        cout<<my_c_stack.top();
        my_c_stack.pop();
    }

}


//12.4 how do virtual functions work in c++?
/*
For each concrete implementation of a class, there is a table of function pointers to all the virtual methods. 
A pointer to this table (called the virtual table) exists as a data member in all the objects. 
When one calls a virtual method, we lookup the object's v-table and call the appropriate derived class method.
*/


//12.5 Shallow vs. Deep Copy?

/*
Depending upon the resources like dynamic memory held by the object,
either we need to perform Shallow Copy or Deep Copy in order to create a replica of the object

Shallow Copy:
In shallow copy, an object is created by simply copying the data of all variables of the original object. 
This works well if none of the variables of the object are defined in the heap section of memory. 
If some variables are dynamically allocated memory from heap section, then copied object variable will also reference then same memory location.
This will create ambiguity and run-time errors dangling pointer.

Deep Copy:
In Deep copy, an object is created by copying data of all variables and it also allocates similar memory resources with the same value to the object. 
In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well if required.
Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.

*/


//12.6 what is the significance of the keyword VOLATILE in C/C++?

/*
TO TELL COMPILE THAT DOONT OPTIMIZE MY CODE!!
int some_int = 100;

while(some_int == 100)
{
   //your code
}
When this program gets compiled, the compiler may optimize this code, if it finds that the program never ever makes any attempt to change the value of some_int, 
so it may be tempted to optimize the while loop by changing it from while(some_int == 100) to something which is equivalent to while(true) so that the execution could be fast 
(since the condition in while loop appears to be true always). 
(if the compiler doesn't optimize it, then it has to fetch the value of some_int and compare it with 100, in each iteration which obviously is a little bit slow.)

However, sometimes, optimization (of some parts of your program) may be undesirable, 
because it may be that someone else is changing the value of some_int from outside the program which compiler is not aware of, 
since it can't see it; but it's how you've designed it. In that case, compiler's optimization would not produce the desired result!

So, to ensure the desired result, you need to somehow stop the compiler from optimizing the while loop.
That is where the volatile keyword plays its role. All you need to do is this,



*/


//12.7 why do base virtual class need  virtual destructor?
/*
Virtual DestructorsPermalink
By now it should also be clear why it is always a good idea to make destructors of base classes virtual. Since derived classes are often handled via base class references, 
declaring a non-virtual destructor will be dispatched statically, obfuscating the destructor of the derived class:

#include <iostream>

class Base
{
public:
  ~Base()
  {
    std::cout << "Destroying base" << std::endl;
  }
};

class Derived : public Base
{
public:
  Derived(int number)
  {
    some_resource_ = new int(number);
  }

  ~Derived()
  {
    std::cout << "Destroying derived" << std::endl;
    delete some_resource_;
  }

private:
  int* some_resource_;
};

int main()
{
  Base* p = new Derived(5);
  delete p;
}
This will output:

> Destroying base
Making Base’s destructor virtual will result in the expected behavior:

> Destroying derived
> Destroying base
*/

//12.9 create your own smartpointer_class
struct ref_counter
{
    int counter;
    ref_counter():counter(0){}
};

template <typename T>
class my_smartPointer {
    
private:
    T* private_pointer;
    ref_counter* counter;
public:
     my_smartPointer(T* val=nullptr) {
        counter = new ref_counter;
        private_pointer = val;
        counter->counter++;
    }
public:
    my_smartPointer(my_smartPointer<T>& sp)
    {
        private_pointer = sp.private_pointer;
        counter = sp.counter;
        counter->counter++;
    }

    T& operator*() { return *private_pointer; }
    T* operator->() { return private_pointer; }

    int GetRefCount() { return counter->counter;}


    ~my_smartPointer() {

        counter->counter--;
        if (counter->counter <= 0) {
            delete private_pointer;
            delete counter;
        }
           
    }

};


int main()
{
    {
        my_smartPointer<int> m_s_p;
        cout << m_s_p.GetRefCount() << endl;
        {
            my_smartPointer<int> m_s_p_1 = m_s_p;
            cout << m_s_p.GetRefCount() << endl;
        }
        cout << m_s_p.GetRefCount() << endl;
    }




    //char* arr = { 'a'};
    //vector<char> numbers(begin(arr), end(arr));
 /*   last_klines(15);*/

    char mystr[] = { 'b','a','t',NULL,'h','a','n' };
    /*reverseV1(mystr, 7);*/
    cout << endl;
    reverseV2(mystr, 7);

    _CrtDumpMemoryLeaks();
}

