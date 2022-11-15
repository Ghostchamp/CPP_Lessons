#include <iostream>

using namespace std;

class cStackInt
{
private:
    int *arr;
    int top;
    int count;

public:
    void push(int val);
    int pop();
    bool pos(int val);
    void hm_elem();
    void sawTop();

    cStackInt();
    cStackInt(int size);
    cStackInt(const cStackInt & src_stack);
    ~cStackInt();
};

bool cStackInt::pos(int val){
    if (val > 0)
    {
        return true;
    }
    return false;
}


cStackInt::cStackInt(){
    arr = new int[10];
    top = 0;
    count = 10;
}

cStackInt::~cStackInt(){
    delete[] arr;
}

cStackInt::cStackInt(int size){
    if (pos(size))
    {
        arr = new int[size];
        top = -1;
        count = size;
    }
    else
    {
        cout << "Input number < 0 or 0\n";
    }
}

void cStackInt::push(int val){
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

int cStackInt::pop(){
    if (top != -1)
    {
        int buf = arr[top];
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

void cStackInt::hm_elem(){
    cout << "Items left: " << count << endl;
}
void cStackInt::sawTop(){
    cout << "Top Element: " << arr[top] << endl;
}
