#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Renamed for clarity
int cursize = 0;         // Current size of the heap
int arr[MAX_SIZE];

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
    if (leftChild < cursize && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    // Check if right child exists and is greater than largest so far
    if (rightChild < cursize && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    // If the largest is not root, swap and recurse
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        maxHeapify(largest); // Recurse on the affected sub-tree
    }
}

// Function to insert elements into the heap
void insert(int value)
{
    if (cursize < MAX_SIZE)
    {
        arr[cursize] = value;
        int pos = cursize;
        cursize++;

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
void buildMaxHeap()
{
    // Start from the last non-leaf node and apply maxHeapify
    for (int i = cursize / 2 - 1; i >= 0; i--)
    {
        maxHeapify(i);
    }
}

int main()
{
    // Inserting elements into the max-heap
    insert(6);
    insert(8);
    insert(1);
    insert(4);
    insert(7);
    insert(3);
    insert(5);
    insert(0);
    insert(9);
    insert(2);

    // Display the array representing the heap
    cout << "Heap array after insertion: ";
    for (int i = 0; i < cursize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Build the max-heap from the array (if necessary)
    buildMaxHeap();

    cout << "Max-heap array after build: ";
    for (int i = 0; i < cursize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
