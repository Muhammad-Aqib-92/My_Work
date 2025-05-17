#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    friend class StudentBST;
private:
    int id;
    string name;
    float fee;
    Student* left;
    Student* right;

public:
    Student(int id, const string& name, float fee)
        : id(id), name(name), fee(fee), left(nullptr), right(nullptr) {}
};

class StudentBST {
private:
    Student* root;

    void inOrder(Student* stree) {
        if (stree != nullptr) {
            inOrder(stree->left);
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
            inOrder(stree->right);
        }
    }

    void preOrder(Student* stree) {
        if (stree != nullptr) {
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
            preOrder(stree->left);
            preOrder(stree->right);
        }
    }

    void postOrder(Student* stree) {
        if (stree != nullptr) {
            postOrder(stree->left);
            postOrder(stree->right);
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
        }
    }

    void destroy(Student* stree) {
        if (stree != nullptr) {
            destroy(stree->left);
            destroy(stree->right);
            delete stree;
        }
    }

    void deleteNodeHelper(Student*& root, int id) {
        if (root == nullptr) {
            return; // Node not found
        }

        if (id < root->id) {
            deleteNodeHelper(root->left, id); // Go to the left subtree
        } else if (id > root->id) {
            deleteNodeHelper(root->right, id); // Go to the right subtree
        } else {
            // Node found, delete it
            if (root->left == nullptr && root->right == nullptr) { // Case 1: Leaf node
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) { // Case 2: One child (right)
                Student* temp = root->right;
                delete root;
                root = temp;
            } else if (root->right == nullptr) { // Case 2: One child (left)
                Student* temp = root->left;
                delete root;
                root = temp;
            } else { // Case 3: Two children
                Student* temp = findMin(root->right);
                root->id = temp->id;
                root->name = temp->name;
                root->fee = temp->fee;
                deleteNodeHelper(root->right, temp->id);
            }
        }
    }

    Student* findMin(Student* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

public:
    StudentBST() : root(nullptr) {}

    ~StudentBST() {
        destroy(root);
    }

    void insert(int id, const string& name, float fee) {
        Student* newNode = new Student(id, name, fee);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Student* cur = root;
        Student* parent = nullptr;

        while (cur != nullptr) {
            parent = cur;
            if (id < cur->id) {
                cur = cur->left;
            } else if (id > cur->id) {
                cur = cur->right;
            } else {
                cout << "Student with ID " << id << " already exists." << endl;
                delete newNode;
                return;
            }
        }

        if (id < parent->id) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void search(int id) {
        Student* cur = root;
        while (cur != nullptr) {
            if (id == cur->id) {
                cout << "ID: " << cur->id << ", Name: " << cur->name << ", Fee: " << cur->fee << endl;
                return;
            } else if (id < cur->id) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

    void deleteNode(int id) {
        deleteNodeHelper(root, id);
    }

    void inOrder() {
        inOrder(root);
    }

    void preOrder() {
        preOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }
};

int main() {
    StudentBST bst;
    ifstream infile("input.txt");

    if (!infile) {
        cerr << "Error: Unable to open input.txt" << endl;
        return 1;
    }

    int id;
    string name;
    float fee;

    while (infile >> id >> name >> fee) {
        bst.insert(id, name, fee);
    }

    infile.close();

    cout << "In-Order Traversal:" << endl;
    bst.inOrder();

    cout << "\nPre-Order Traversal:" << endl;
    bst.preOrder();

    cout << "\nPost-Order Traversal:" << endl;
    bst.postOrder();

    cout << "\nSearch for ID 101:" << endl;
    bst.search(101);

    cout << "\nDeleting ID 101:" << endl;
    bst.deleteNode(101);

    cout << "\nIn-Order Traversal after deletion:" << endl;
    bst.inOrder();

    return 0;
}
