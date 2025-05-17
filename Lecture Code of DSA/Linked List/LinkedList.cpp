#include<iostream>
using namespace std;

class Node
{
    int data ;
    Node * next;
    
    public:

    Node(int data , Node* next)
    {
        this->data = data ;
        this->next = next ;
    }
    friend class List;
};

class List
{

    Node* head;
    public:
    
    List()
    {
        head = nullptr;
    }
    
    void Insert(int data)         // Insert at the end 
    {
        Node* Nn = new Node(data,nullptr);

        if(head == nullptr)
        {
            head = Nn ;
        }
        else
        {
            Node* curNode = head ;
            while(curNode->next != nullptr)
            {
                curNode = curNode->next;
            }
            curNode->next = Nn ;
        }
    }

    void transvers()
    {
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            Node* curNode = head;
            do
            {
            cout<<curNode->data<<"\t";
            curNode = curNode->next;
            }
            while(curNode != nullptr);
        }
    }

void Start(int data) // Insert at the end
{
    Node* NW = new Node(data, nullptr); 

    if (head != nullptr) 
    {
        NW->next = head;
    }
    head = NW; 
}

};

int main()
{
    List L1;
    // L1.Insert(25);
    // L1.Insert(30);
    // L1.Insert(35);
    L1.Insert(40);
    L1.Start(2);
    L1.Insert(77);
    L1.Start(6);
    

    L1.transvers();
}
