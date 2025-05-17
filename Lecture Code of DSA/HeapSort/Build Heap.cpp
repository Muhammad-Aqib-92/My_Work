#include <iostream>
#include <algorithm> // Include only if using std::swap
using namespace std;

const int MAX_SIZE = 10; // Renamed to avoid conflict
int cur = MAX_SIZE;
int arr[MAX_SIZE]={2,4,3,7,6,1,5,0,9,8};

// Returns the index of the left child
int left(int index)
{
    return 2 * index + 1;
}

// Returns the index of the right child
int right(int index)
{
    return 2 * index + 2;
}

// Returns the index of the parent
int parent(int index)
{
    return (index - 1) / 2;
}

// Max-heapify function to maintain heap property
void maxHeapify(int index)
{
    int leftChild = left(index);
    int rightChild = right(index);
    int largest = index;

    // Check if left child exists and is greater than root
    if (leftChild < cur && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    // Check if right child exists and is greater than largest so far
    if (rightChild < cur && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    // If the largest is not root, swap and recurse
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        maxHeapify(largest);  // Recurse on the affected sub-tree
    }
}


// Function to insert elements into the heap
void insert(int value)
{
    if (cur != MAX_SIZE)
    {
        arr[cur] = value;
        int pos = cur;
        cur++;
        cout << arr[pos] << " ";

        // Move the value up to maintain the max-heap property
        while (pos != 0 && arr[pos] > arr[parent(pos)])
        {
            swap(arr[pos], arr[parent(pos)]);
            pos = parent(pos);
        }
    }
    else
    {
        cout << "Heap is full. Cannot insert " << value << "." << endl;
    }
}

// Function to build the max-heap from an unsorted array
void buildMaxHeap(int arr[])
{
       // Start from the last non-leaf node and apply maxHeapify
    for (int i = MAX_SIZE / 2 - 1; i >= 0; i--)
    {
        maxHeapify(i);
    }

}


 


int main()
{
    // Inserting elements into the max-heap
    // insert(6);
    // insert(8);
    // insert(1);
    // insert(4);
    // insert(7);
    // insert(3);
    // insert(5);
    // insert(0);
    // insert(9);
    // insert(2);

    // // Display the array representing the heap
    // cout << "\nHeap array: ";
    // for (int i = 0; i < cur; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // Now, let's build the max heap from an unsorted array (if necessary)
      // Size of the heap array
    buildMaxHeap(arr);

    cout << "\nMax-heap array after build: ";
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
