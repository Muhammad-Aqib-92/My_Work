#include<iostream>
using  namespace std;

class Node
{
    int num;
    Node * next;

    public :
    Node(int num,Node* next)
    {
        this->num = num;
        this->next = next;
    }

    void  Display()
    {
        cout<<num<<" ";
    }

    friend class Stack;
};

class Stack
{
    Node * top;
    public:
    Stack()
    {
        top = nullptr;
    }

   ~Stack()
   {
        Node* temp = top;
        while(temp!=nullptr)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    
   }


   bool isEmpty()
   {
    return top == nullptr;
   }

   void push(int num)
   {
    Node *R = new Node(num,nullptr);
    if(isEmpty())
    {
        top = R;
        top->next =nullptr;
        return;
    }
    else
    {
        Node * temp = top;
        top = R;
        top->next = temp;
        return;
    }
    
   }

   void pop()
   {
    if(isEmpty())
    {
        cout<<"Stack is already Empty"<<endl;
        return;
    
    }
    else
    {
        Node * temp = top;
        top = top->next;
        delete temp;
        temp = top;
    }

   }


   int  size()
   {
    int count = 0;
    Node* temp = top ;
    while(temp!= nullptr)
    {
        temp = temp->next;
        count++;
    }
  
    return count;
   }

   void show()
   {
    Node * temp = top;
    while(temp!= nullptr)
    {
        temp->Display();
        temp = temp->next;
    }
    return;
   }

};


int main()
{
    Stack j;
    j.push(1);
    j.push(2);
    j.push(3);
   cout << "Current Size is :"<< j.size()<<endl;
   


    

    j.show();
   


    return 0;
    

}
