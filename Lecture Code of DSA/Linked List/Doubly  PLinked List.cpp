#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* next;
    Node * pre;

    public :

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->pre = nullptr;
    }

    void show()
    {
        cout<<data<<" ";
    }
    friend class Doubly;
};

class Doubly
{
    Node * head ;

    public:

    Doubly()
    {
        this ->head = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insertatEnd(int data)
    {
        Node* A = new Node(data);
        Node * cur = head;
        Node * per =  nullptr ;
        if(head == nullptr)
        {
            head = A;
        }
        else
        {
            while(cur->next != nullptr)
            {
                per = cur;
                cur = cur->next;
            }
            cur->next = A;
            A->pre = cur;
          
        }
    }

    void Showdata()
    {
        Node * temp = head;
        while(temp != nullptr)
        {
            temp->show();
            temp = temp->next;
            
        }
    }

    void insertatfront(int data)
    {
        Node * AR = new Node(data);
        Node * temp = head;
        head = AR;
        AR->next = temp;
        temp->pre = head;
    }

};


int main()
{
    Doubly L;
    L.insertatEnd(10);
    L.insertatEnd(20);
    L.insertatEnd(30);
    L.insertatfront(55);
    L.Showdata();

}