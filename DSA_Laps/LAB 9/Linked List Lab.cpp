#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    friend class StudentList;

private:
    int id;   // ID of the student
    string name;  // Name of the student
    float cgpa;  // CGPA of the student
    Student* next;  // Pointer to the next node in the list

public:
    Student(int id, string name, float cgpa, Student* next = nullptr)
    {
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
        this->next = next;
    }

    void studentDetails() const
    {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student CGPA: " << cgpa << endl;
    }
};

class StudentList {
private:
    Student* head;  // Start of the list
    Student* cursor; // Current item in the list

public:
    StudentList()
    {
        head = nullptr;
        cursor = nullptr;
    }

    ~StudentList()
    {
        Student* temp = head;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void insert(const Student& newStd)
    {
        Student* newNode = new Student(newStd.id, newStd.name, newStd.cgpa);
        
        if (isEmpty()) {
            head = newNode;
            cursor = newNode;
        } else {
            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = newNode;
        }
    }

    void remove(int id)
    {
        if (isEmpty())
        {
            cout << "List is already empty" << endl;
            return;
        }

        if (head->id == id)
        {
            Student* temp = head;
            head = head->next;
            delete temp;
            cursor = head ? head : nullptr; // Update cursor if list is not empty
            return;
        }

        Student* temp = head;
        while (temp->next != nullptr && temp->next->id != id)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Student with ID " << id << " not found!" << endl;
            return;
        }

        Student* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        cursor = temp->next ? temp->next : head; // Move cursor to the next item or head
    }

    void search(float cgpa) const
    {
        if (isEmpty())
        {
            cout << "The list is empty. No students to search." << endl;
            return;
        }

        Student* temp = head;
        bool found = false;

        while (temp != nullptr)
        {
            if (temp->cgpa == cgpa)
            {
                cout << "Found student with CGPA " << cgpa << ":" << endl;
                temp->studentDetails();
                found = true;
            }
            temp = temp->next;
        }

        if (!found)
        {
            cout << "No student with CGPA " << cgpa << " found." << endl;
        }
    }

    void replace(const Student& newStd)
    {
        Student* temp = head;
        while (temp != nullptr)
        {
            if (temp->id == newStd.id)
            {
                temp->name = newStd.name;
                temp->cgpa = newStd.cgpa;
                cursor = temp; // Move cursor to the replaced student
                return;
            }
            temp = temp->next;
        }

        // If student not found, append to the end
        insert(newStd);
    }

    void gotoBeginning()
    {
        if (!isEmpty())
        {
            cursor = head;
            cout << "Moved to the first student:" << endl;
            cursor->studentDetails();
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }

    void gotoEnd()
    {
        if (!isEmpty())
        {
            cursor = head;
            while (cursor->next != nullptr)
            {
                cursor = cursor->next;
            }
            cout << "Moved to the last student:" << endl;
            cursor->studentDetails();
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }

    bool gotoNext()
    {
        if (cursor != nullptr && cursor->next != nullptr)
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    bool gotoPrior()
    {
        if (cursor == nullptr || cursor == head)
        {
            return false;
        }

        Student* temp = head;
        while (temp != nullptr && temp->next != cursor)
        {
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            cursor = temp;
            return true;
        }
        return false;
    }

    Student getCursor() const
    {
        if (cursor != nullptr)
        {
            return *cursor;  // Return the current student
        }
        throw runtime_error("Cursor is null.");
    }

    void showStructure() const
    {
        if (isEmpty())
        {
            cout << "Empty list" << endl;
            return;
        }

        Student* temp = head;
        while (temp != nullptr)
        {
            temp->studentDetails();
            temp = temp->next;
        }
    }
};

// Function to read students from a file
void loadStudentsFromFile(const string& filename, StudentList& list)
{
    ifstream file("input.txt");
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int id;
    string name;
    float cgpa;
    while (file >> id)
    {
        file.ignore();  // Ignore the newline after ID
        getline(file, name);
        file >> cgpa;
        file.ignore();  // Ignore the newline after CGPA
        Student student(id, name, cgpa);
        list.insert(student);
    }
}

int main()
{
    StudentList list;

    // Load students from input.txt
    loadStudentsFromFile("input.txt", list);

    // Test the functionality
    cout << "Showing all students:" << endl;
    list.showStructure();

    cout << "\nMoving cursor to the first student:" << endl;
    list.gotoBeginning();

    cout << "\nMoving cursor to the last student:" << endl;
    list.gotoEnd();

    cout << "\nMoving cursor to the next student:" << endl;
    list.gotoNext();
    list.getCursor().studentDetails();

    cout << "\nSearching for student with CGPA 3.2:" << endl;
    list.search(3.2);

    cout << "\nReplacing student with ID 21:" << endl;
    Student updatedStudent(21, "Muhammad Aqib", 3.5);
    list.replace(updatedStudent);
    list.showStructure();

    cout << "\nRemoving student with ID 21:" << endl;
    list.remove(21);
    list.showStructure();

    return 0;
}
