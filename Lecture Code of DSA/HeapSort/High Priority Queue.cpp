#include <iostream>
#include <algorithm> // Include only if using std::swap
using namespace std;

const int MAX_SIZE = 10; // Renamed to avoid conflict
int cur = MAX_SIZE;
int arr[MAX_SIZE] = {2, 4, 3, 7, 6, 1, 5, 0, 9, 8};

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
        maxHeapify(largest); // Recurse on the affected sub-tree
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

// Function to get the maximum element and rebuild the heap
int getMax()
{
    if (cur <= 0)
    {
        throw runtime_error("Heap underflow");
    }

    int max = arr[0];
    arr[0] = arr[--cur];
    maxHeapify(0);
    return max;
}

int main()
{
    // Build the max heap from the unsorted array
    buildMaxHeap(arr);

    cout << "\nMax-heap: ";
    for (int i = 0; i < cur; i++)
    {
        cout << arr[i] << " ";
    }

    // Extract the maximum element
    cout << "\nMaximum element: " << getMax() << endl;

    cout << "Heap after extracting max: ";
    for (int i = 0; i < cur; i++) // Use cur instead of MAX_SIZE
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
