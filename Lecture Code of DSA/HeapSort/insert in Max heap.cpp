#include <iostream>
#include <algorithm> 
using namespace std;

const int MAX_SIZE = 10; 
int cur = 0;
int arr[MAX_SIZE];

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

void insert(int value)
{
    if (cur != MAX_SIZE)
    {
        arr[cur] = value;
        int pos = cur;
        cur++;
        cout << arr[pos] << " ";

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

int main()
{
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

    cout << "\nHeap array: ";
    for (int i = 0; i < cur; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
