#include<iostream>
using namespace std;

class Node
{
   int num;
   Node * next ;

   public:

   Node(int num , Node* next)
   {
    this->num = num;
    this->next = nullptr;
   }

   void show()
   {
    cout<<num<<" ";
   }
   
   friend class Queue;
};

class Queue
{
    Node * front ;
    Node * rear ;

    public:

    Queue()
    {
        front =nullptr; 
        rear =nullptr; 
    }

    bool isEmpty()
    {
        return front == nullptr &&  rear == nullptr;
    }

    void enqueue(int num)
    {
        Node * Nn = new Node(num,nullptr);
        if(isEmpty())
        {
            front = Nn;
            rear = Nn;
        }
        else
        {
            rear->next = Nn;
            rear = Nn;
                      
        }

    }
    void dequeue()
    {
        if(!isEmpty())
        {
        Node * temp = front ;
        front = front->next;
        delete temp;
        }
        else
        {
            cout<<"Dear Linked List is already empty"<<endl;

        }

    }

    void showdata()
    {
        Node * temp = front;
        while(temp != nullptr)
        {
            temp->show();
            temp = temp->next;
        }
    }

};


int main()
{
    Queue j;

    j.enqueue(1);
    j.enqueue(2);
    j.enqueue(3);
    j.enqueue(4);
    j.showdata();
    cout<<endl;
    j.dequeue();
    j.showdata();

}