#include<iostream>
using namespace std;

class Node{
    int data ;
    Node * left;
    Node * right;

    public:

    Node(int data)
    {
        this->data = data ;
        this->left = nullptr;
        this->right = nullptr;
    }
    friend class Tree;
};

class Tree
{
    Node * root;
    
    public:

    Tree()
    {
        root = nullptr;
    }

    bool isEmpty()
    {
        return !root;
    }

    void insert(int data)
    {
        Node * curNode = root;
        Node * preNode = root;

        Node * Nnode = new Node(data);

        while(curNode != nullptr)
        {
            preNode = curNode;
            if(data < curNode->data)
            {
                curNode = curNode->left;
            }
            else 
            {
                curNode = curNode->right;
            }
        }

        if(preNode == nullptr)
        {
            root = Nnode;
        }
        else if(data < preNode->data)
        {
            preNode->left = Nnode;
        }
        else
        {
            preNode->right = Nnode;
        }
    }

};

int main()
{
    Tree A;
    cout<<A.isEmpty()<<endl;
    A.insert(6);
    A.insert(2);
    A.insert(3);
    cout<<A.isEmpty();

}