#include<iostream>
using namespace std;

class Node
{
    int data ;
    Node * next;

    public :

    Node(int data ,Node * next)
    {
        this->data = data;
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
    
    void InsertAtEnd(int data)
    {
        Node* ne = new Node(data,nullptr);
        if(head == nullptr)
        {
            head = ne;
            ne->next = head;
        }
        else
        {
            Node * curNode = head;
            while(curNode->next != head)
            {
                curNode = curNode->next;
            }
            curNode->next = ne;
            ne->next = head ;
        }

    }


  void Traverse() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curNode = head;
  do
   {
        cout << curNode->data << " ";
        curNode = curNode->next;    
    } while (curNode != head); 
}

};



int main()
{
    List l1;
    l1.InsertAtEnd(10);
    l1.InsertAtEnd(20);
    l1.InsertAtEnd(30);
    l1.InsertAtEnd(40);

    l1.Traverse();
}