#include<iostream>
using namespace std;

template <class T>
class Stack
{
private:

T* data;
int top = -1; 
const int MAX_SIZE; 
public:

Stack(const int max_size = 10):MAX_SIZE(max_size)
{
    data = new T[MAX_SIZE];
}

~Stack()
{
    delete []data;
    data = nullptr;
}

void push(const T newItem)
{
    if(isFull())
    {
        cout<<"Stack is already Full"<<endl;
    }
    else if(isEmpty())
    {
        data[++top] = newItem;
        cout<<"This item added successfully "<<data[top]<<endl;
    }
    else
    {
        if(top >=0){
        data[++top] = newItem;
        cout<<"This item added successfully "<<data[top]<<endl;
        }

    }
    
} 

void pop()
{
    if(isEmpty())
    {
        cout<<"Stack is already empty"<<endl;
    }
    else
    {
        cout<<"This element removed Successfully "<<data[top]<<endl;
        top--;
    }
} 
void clear()
{
    cout<<"Stack is clear now "<<endl;
    top = -1;
}

T getTop() const
{
    if(isEmpty)
    {
        return T();
    }
    else
    {
        return data[top];
    }

}

bool isEmpty() const
{
    return (top == -1);
} 

bool isFull() const
{
    return (top == MAX_SIZE - 1);

}
void showStructure()const
{
    if(isEmpty()){
    cout<<"Stack is Empty"<<endl;
    }else{
int tempoint = top;
while(tempoint >=0)
{
    cout<<data[tempoint]<<endl;
    tempoint--;
}
}
}


};



int main()
{
    cout<<"This is the start of Program"<<endl;
    Stack <int> hero(10);
   hero.push(1);
   hero. push(2);
   hero. push(3);
   hero. push(4);
   hero. push(5);
   hero.pop();
   hero.showStructure();
   hero.pop();
   hero.showStructure();
   hero.clear();
   hero.showStructure();

}