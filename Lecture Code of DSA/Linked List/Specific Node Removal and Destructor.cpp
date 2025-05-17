#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    friend class List; 
};

class List {
    Node* head;

public:
    List() : head(nullptr) {}

    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;  
            current = current->next; 
            delete temp;           
        }
        head = nullptr; 
        cout << "\nLinked list destroyed and memory freed!" << endl; 
    }

    void transvers() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node* curNode = head;
            while (curNode != nullptr) {
                cout << curNode->data << "\t";
                curNode = curNode->next;
            }
            cout << endl; 
        }
    }

    void Insert(int data)//insert at the end 
     { 
        Node* newNode = new Node(data, nullptr);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curNode = head;
            while (curNode->next != nullptr) {
                curNode = curNode->next;
            }
            curNode->next = newNode;
        }
    }

    void removel() { // Remove from the last
        if (head == nullptr) {
            cout << "List is already empty" << endl;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* curNode = head;
            while (curNode->next->next != nullptr) {
                curNode = curNode->next;
            }
            delete curNode->next; 
            curNode->next = nullptr;
        }
    }

    void removef() { // Remove from the front
        if (head == nullptr) {
            cout << "List is already empty" << endl;
        } else {
            Node* curNode = head;
            head = head->next;
            delete curNode;
            cout << "First node removed successfully." << endl;
        }
    }

    void removespecific() { //Specific node removal
        int num;
        cout << "Enter the data you want to remove from the node: ";
        cin >> num;

        if (head == nullptr) {
            cout << "There is no data, so no removal is possible." << endl;
            return;
        }

        if (head->data == num) {
            Node* ne = head;
            head = head->next;
            delete ne;
            cout << "Node removed successfully." << endl;
            return;
        }

        Node* preNode = head;
        Node* curNode = preNode->next;

        while (curNode != nullptr) {
            if (curNode->data == num) {
                preNode->next = curNode->next;
                delete curNode;
                cout << "Node deleted successfully." << endl;
                return;
            }
            preNode = curNode;
            curNode = curNode->next;
        }
        cout << "Node not found." << endl;
    }
};

int main() {
    List L1;
    L1.Insert(25);
    L1.Insert(30);
    L1.Insert(35);
    L1.Insert(40);

    cout << "Before deletion:" << endl;
    L1.transvers();

    // Uncomment to test deletions
    // L1.removel();
    // L1.removef();
    // L1.removespecific();

    cout << "After deletion:" << endl;
    L1.transvers();
}
