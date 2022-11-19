#include <iostream>

using namespace std;

template<typename T> class cStack 
{
private:
    T *arr;
    int top;
    int count;

public:
    void push(T val);
    T pop();
    bool pos(int val);
    void hm_elem();
    void sawTop();

    cStack();
    cStack(int size);
    cStack(const cStack & src_stack);
    ~cStack();
};

bool pos(int val){
    if (val > 0)
    {
        return true;
    }
    return false;
}


template<typename T> cStack<T>::cStack(){
    arr = new T[10];
    top = 0;
    count = 10;
}

template<typename T> cStack<T>::~cStack(){
    delete[] arr;
}

template<typename T> cStack<T>::cStack(int size){
        if (pos(size))
        {
            arr = new T[size];
            top = -1;
            count = size;
        }
        else
        {
            cout << "Size of Stack 0 or < 0" << endl;
        }
}

template<typename T> void cStack<T>::push(T val){
    if (count)
    {
        top++;
        arr[top] = val;
        count--;
    }
    else
    {
        cout << "Stack is Full\n";
    }
}

template<typename T>T cStack<T>::pop(){
    if (top != -1)
    {
        T buf = arr[top];
        count++;
        top--;
        return buf;
    }
    else
    {
        cout << "Stack is Empty\n";
        exit(EXIT_FAILURE);
    }
}

template<typename T> void cStack<T>::hm_elem(){
    cout << "Items left: " << count << endl;
}
template<typename T> void cStack<T>::sawTop(){
    cout << "Top Element: " << arr[top] << endl;
}


int main()
{
    cStack<float> stack_of_int(10);
    stack_of_int.push(1.214);
    stack_of_int.push(1.215);
    stack_of_int.push(1.216);
    stack_of_int.push(1.217);
    stack_of_int.push(1.214);
    

    stack_of_int.sawTop();
    stack_of_int.pop();
    stack_of_int.sawTop();
    
    return 0;
}