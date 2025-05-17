#include<iostream>
using namespace std;

template <class T>
class Queue
{
  private:

T* data; 
int front = -1;
int rear =  -1; 
const int MAX_SIZE;


public:
// Constructor
Queue(const int max_size = 10):MAX_SIZE(max_size)
{
    data = new T[MAX_SIZE];
}
// Destructor
~Queue()
{
    delete [] data;
    data = nullptr;
}
// Queue manipulation operations
void enQueue(const T newItem)
{
    if(isFull())
    {
    cout<<"Queue is already filled"<<endl;
    }else if(isEmpty())
    {
        front = rear = 0;
        data[rear] = newItem;
    }else
    {
     rear = (rear + 1) % MAX_SIZE;
     data[rear] = newItem;
    }
    cout<<"Element added : "<<data[rear]<<endl;
}
void deQueue()
{
    if(isEmpty())
    {
        cout<<"Queue is already empty"<<endl;
    }
    else if(front == rear)
    {
        cout<<"this element removed Successfully :"<<data[front];
        front = rear =  -1;

    }
    else
    {
        cout<<"this element removed Successfully :"<<data[front];
        front = (front+1)% MAX_SIZE;
    }

}
void clear()
{
    cout<<"Queue is cleared Successfully"<<endl;
    front = rear = -1;
}
// Queue accessors
T getFront() const
{
    if(isEmpty())
    {
        cout<<"Queue is Already Empty"<<endl;
        return T();
    }
    else
    {
        return data[front];
    }
}

T getRear() const
{
    if(isEmpty())
    {
        return T();
    }
    else
    {
        return data[rear];
    }
}
bool isEmpty() const
{
   return (front == -1 && rear == -1);
}
bool isFull() const
{
    return ((rear + 1) % MAX_SIZE == front);
}

void showStructure() const
{
     if (isEmpty())  
    {
        cout << "Queue is empty." << endl;
        return;
    }
    int i = front ;
    cout<<"Elements of the Queue"<<endl;
    while (i != rear)
    {
        cout<<data[i]<<" ";
        i = (i +1) % MAX_SIZE;
    }
    cout << data[rear] << endl;
}
};

int main()
{
    cout<<"Start of the Program"<<endl;

    Queue <int> hero(10);
    hero.enQueue(1);
    hero.enQueue(2);
    hero.enQueue(3);
    hero.enQueue(4);
    hero.showStructure();
    hero.deQueue();
    hero.deQueue();
    hero.showStructure();
    hero.enQueue(34);
    hero.enQueue(42);
    hero.showStructure();


}