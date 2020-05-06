#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class stackarr
{
    T *stk;
    int stackCapacity;
    int top;

public:
    stackarr(int sizee = 10)         ///Constructor
    {
        if(sizee<1) cout<<"Out Of Bounds";     ///throw oob();
        stackCapacity = sizee;
        stk = new T[stackCapacity];
        top=-1;
    }
    ~stackarr(){delete []stk;}                ///Destructor
    bool isempty();             ///Checks for empty stack
    int sizeofstk();            ///Returns size of stack
    stackarr<T>& pop(T x);              ///POP
    stackarr<T>& push(const T& x);       ///PUSH
    T& showtop();               ///Returns value at TOS
    void disp();
};

template <class T>
bool stackarr<T> :: isempty()
{
    return top==-1;
}

template <class T>
int stackarr<T> :: sizeofstk()
{
    if(isempty()){}///throw empty
    if (!isempty())
            return top+1;

}

template <class T>
T& stackarr<T>::showtop()
{
    return stk[top];
}

template <class T>
stackarr<T>& stackarr<T>::pop(T x)
{
    x = stk[top--];
//    cout<<x<<" Popped out of Stack"<<endl;
    return *this;
}

template <class T>
stackarr<T>& stackarr<T>::push(const T& x)
{
    stk[++top] = x;
//    cout<<x<<" Pushed onto Stack"<<endl;
    return *this;
}

template <class T>
void stackarr<T>::disp()
{
    if(!isempty())
        for(int i=0; i<top; i++)
            cout<<"("<<stk[i].x<<", "<<stk[i].y<<")"<<"-->";
        cout<<"("<<stk[top].x<<", "<<stk[top].y<<")"<<endl;
}




#endif // STACK_H_INCLUDED
