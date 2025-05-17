#include<iostream>
using namespace std;

class Node
{
    int data ;
    Node * pre;
    Node * next;

    public:
   
    Node(int data , Node* pre,Node* next)
    {
        this->data = data;
        this->pre = pre;
        this->next = next;
    }
    friend class List;

};

class List
{
    Node * head;
 public:
    List()
    {
        head = nullptr;
    }

    void InsertAtFront(int data)
    {
        Node * j = new Node(data,nullptr,nullptr);
        Node * temp =  head;
        if(head == nullptr)
        {
            head = j;
        }
        else
        {
            head = j;
            temp->pre = j;
            j->next = temp;

        }

    }

    void InsertAtEnd(int data)
    {
        Node* N = new Node(data,nullptr,nullptr);
        if(head == nullptr)
        {
            head = N;
        }
        else
        {
            Node * curNode = head ;
            while(curNode->next != nullptr)
            {
                curNode = curNode->next ;              
            }
            curNode->next = N;
            N->pre  =curNode ; 
        }
    }

    void traverse()
    {
        if(head == nullptr)
        {
            cout<<"list is already empty"<<endl;
        }
        else
        {
            Node* temp = head;
            while(temp!= nullptr)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            
        }
    }


};


int main()
{
    List l1;
    
    l1.InsertAtFront(1);
    l1.InsertAtFront(2);
    l1.InsertAtFront(3);
    l1.InsertAtFront(5);

    l1.traverse();
}