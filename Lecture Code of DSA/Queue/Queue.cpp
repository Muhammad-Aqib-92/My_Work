#include<iostream>

using namespace std;

const int size = 5 ;
int front = -1;
int rear = -1;
int arr[size] ;

bool isEmpty()
{
    return(front == -1 && rear == -1);
    
}

bool isFull()
{
    return ((rear  + 1) % size == front);

}

void enqueue(int n )
{
    if(isEmpty())
    {
        rear = front = 0;
        arr[rear] = n;
    }
    else if(isFull())
    {
        cout<<"Queue is already filled so new element cann't be added"<<endl;
        return;
    }
    else
    {rear = (rear+1)%size;
    arr[rear]= n;
    }
    cout<<"New element added succesfully: "<<arr[rear]<<endl;
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is already empty"<<endl;
        return ;
    }
    else if(front == rear )
    {
        cout<<"DeQueued successfully"<<arr[front]<<endl;
        front = rear = -1;
    
    }else
    {
        cout<<"dequeued Successfully "<<arr[front]<<endl;
        front = (front + 1) %  size;
        
    }

}

void display()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
cout<<"Elements of the Queue are :"<<endl;
int i = front;
while(i != rear)
{
    cout<<arr[i]<<" ";
    i = (i +1) % size;
}
cout<<arr[rear]<<endl;
}   


int main()
{
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();

    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();



}


