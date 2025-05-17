#include<iostream>
using namespace std;

class Node
{
    int data ;
    Node * next;

    Node(int data,Node* next)
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

    void removel()//remove from last
    {
      
        if(head == nullptr)
        {
            cout<<"List is already empty"<<endl;
        }
        else 
        if
        (head->next == nullptr)
        {
            delete head ;
            head = nullptr;
        }
        else
        {
            Node * curNode = head ;
            Node * preNode = head->next ;  
            while(preNode->next!= nullptr)
            {
                curNode = preNode;
                preNode = preNode->next;
            }
            curNode->next = nullptr;
            delete preNode;  
        }
    }

    void removef()
    {
        if(head == nullptr)
        {
            cout<<"List is already empty"<<endl;
        }
        else
        {
            Node * curNode = head;
            head = head->next;
            delete curNode;
            cout << "First node removed successfully." << endl;

            
        }

    }

    void removespecific()
    {
        int num;
        cout<<"Enter the data you want to remove node"<<endl;
        cin>>num;
        
        if(head ==nullptr)
        {
            cout<<"There is no data so no removal possible"<<endl;
            return;
        }
        if(head->data == num)
        {
            Node * ne = head;
            head = head->next;
            delete ne;
            cout<<"Node remove successfully"<<endl;
            return;
        
        }
        
            Node * preNode = head ;
            Node * curNode = preNode->next;
            bool nodeFound = false;

            while(curNode != nullptr)
            {
                if(curNode->data == num)
                {
                    preNode->next = curNode->next ;
                    delete curNode;
                    cout<<"Node deleted Successfully"<<endl;
                    nodeFound = true;
                    return;
                }

                preNode = curNode ;
                curNode = curNode->next;
        }

        if (!nodeFound) 
    {
        cout << "Node not found." << endl;
    }
       
        }
           

    


};


int main()
{
    List L1;
    L1.Insert(25);
    L1.Insert(30);
    L1.Insert(35);
    L1.Insert(40);
    // L1.removel();
    // L1.removel();
    // L1.removef();
    // L1.removef();

    L1.removespecific();
    L1.transvers();
}
