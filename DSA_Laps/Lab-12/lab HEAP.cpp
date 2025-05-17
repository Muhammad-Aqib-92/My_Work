#include<iostream>
using namespace std;

class Student 
{ 
friend class StudentMaxHeap; 
private: 
    int rollNo;             
    double cgpa;            
}; 

class StudentMaxHeap 
{ 
private: 
    Student* arr;      
    int curSize;       
    int maxSize;       

public: 

    StudentMaxHeap(int size)
    {
        maxSize = size;
        curSize = 0;
        arr = new Student[maxSize];
    }

    ~StudentMaxHeap()
    {
        delete [] arr;
        arr = nullptr;
    }

    bool isEmpty()
    {
        return curSize == 0;
    }               

    bool isFull()
    {
        return curSize == maxSize;
    }

    int left(int index)
    {
        return 2 * index + 1; 
    }

    int right(int index)
    {
        return 2 * index + 2; 
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void maxHeapify()
    {
        for (int i = curSize / 2 - 1; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void heapify(int index)
    {
        int leftChild = left(index);
        int rightChild = right(index);
        int largest = index;
        
        if (leftChild < curSize &&
            (arr[leftChild].cgpa > arr[largest].cgpa ||
             (arr[leftChild].cgpa == arr[largest].cgpa && arr[leftChild].rollNo < arr[largest].rollNo)))
        {
            largest = leftChild;
        }
      
        if (rightChild < curSize &&
            (arr[rightChild].cgpa > arr[largest].cgpa ||
             (arr[rightChild].cgpa == arr[largest].cgpa && arr[rightChild].rollNo < arr[largest].rollNo)))
        {
            largest = rightChild;
        }
       
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void insert(int rollNo, double cgpa) 
    {
        if (!isFull())
        {
            arr[curSize].rollNo = rollNo;
            arr[curSize].cgpa = cgpa;
            int new_pos = curSize;
            curSize++;

            while (new_pos > 0 && 
                   (arr[new_pos].cgpa > arr[parent(new_pos)].cgpa || 
                    (arr[new_pos].cgpa == arr[parent(new_pos)].cgpa && 
                     arr[new_pos].rollNo < arr[parent(new_pos)].rollNo))) 
            {
                swap(arr[new_pos], arr[parent(new_pos)]);
                new_pos = parent(new_pos);
            }
        }
        else
        {
            cout << "Array is already full" << endl;
        }
    }

    bool remove(int& rollNo, double& cgpa)
    {
        if (!isEmpty())
        {
            rollNo = arr[0].rollNo;
            cgpa = arr[0].cgpa;
            arr[0] = arr[curSize - 1];
            curSize--;
            heapify(0);
            return true;
        }
        return false;
    }

    void displayStudentList()
    {
        Student* tempHeap = new Student[curSize];
        for (int i = 0; i < curSize; i++)
        {
            tempHeap[i] = arr[i];
        }

        int tempSize = curSize;
        while (tempSize > 0) 
        {
            cout << "Roll No: " << tempHeap[0].rollNo 
                 << ", CGPA: " << tempHeap[0].cgpa << endl;
            tempHeap[0] = tempHeap[tempSize - 1];
            tempSize--;
            heapify(0);
        }

        delete[] tempHeap;
    }

    void levelOrder()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < curSize; i++)
            {
                cout << "Roll No: " << arr[i].rollNo << ", CGPA: " << arr[i].cgpa << endl;
            }
        }
        else
        {
            cout << "List is already empty" << endl;
        }
    }
};

void menu()
{
    int choice;
    StudentMaxHeap heap(10);
    while (true)
    {
        cout << "1. Insert a new student" << endl;
        cout << "2. Remove (and display) the student with the Max CGPA" << endl;
        cout << "3. Display the list of students (Descending order of CGPA)" << endl;
        cout << "4. Display the list of students (Level-order traversal)" << endl;
        cout << "5. Exit" << endl;
        cout << "Make choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int rollNo;
            double cgpa;
            cout << "Enter Roll No and CGPA: ";
            cin >> rollNo >> cgpa;
            heap.insert(rollNo, cgpa);
            break;
        }

        case 2: 
        {
            int rollNo;
            double cgpa;
            if (heap.remove(rollNo, cgpa)) 
            {
                cout << "Removed student with Roll No: " << rollNo 
                     << ", CGPA: " << cgpa << endl;
            }
            break;
        }
        case 3:
            heap.displayStudentList();
            break;
        case 4:
            heap.levelOrder();
            break;
        case 5:
            cout << "Exiting program." << endl;
            return;
        default:
            cout << "Invalid choice, please try again!" << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}
