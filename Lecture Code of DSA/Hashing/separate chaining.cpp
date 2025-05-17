#include <iostream>
using namespace std;

class node {
private:
    int data;
    node* next;

public:
    node() : data(0), next(nullptr) {}

    node(int data) : data(data), next(nullptr) {}

    friend class handler;
};

class handler {
private:
    node** table; 
    int size;     


    int hashFunction(int key) {
        return key % size;
    }

public:
 
    handler(int size) : size(size) {
        table = new node*[size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr; 
        }
    }

  
    void insert(int key) {
        int index = hashFunction(key); 

       
        node* newNode = new node(key);

        newNode->next = table[index];
        table[index] = newNode;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            node* current = table[i];
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }
    void search(int data)
    {
        int index = hashFunction(data);
        node * temp = table[index];

        while(temp!= nullptr)
        {
            if(data == temp->data)
            {
                cout<<"found data:"<<endl;
                cout<<temp->data<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"such data doesn't exist"<<endl;
    }

    ~handler() {
        for (int i = 0; i < size; i++) {
            node* current = table[i];
            while (current != nullptr) {
                node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] table;
    }
};

int main() {
    int tableSize = 7; 
    handler h(tableSize);

    
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(7);
    h.insert(14);
    h.insert(3);
    h.insert(1);

    h.search(23);

   
    // h.display();

    return 0;
}
