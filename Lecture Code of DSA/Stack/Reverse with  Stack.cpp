#include<iostream>
using namespace std;

const int size = 4;
int arr[size];
int point = -1;  

bool isEmpty()
{
    return (point == -1);
}

bool isFull()
{
    return (point == size - 1);
}

void push(int n)
{
    if (isFull())
    {
        cout << "Oh Sorry, Stack is full" << endl;
    }
    else
    {
        arr[++point] = n;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "Oh Sorry, Stack is already empty" << endl;
        return;
    }
    else
    {
        cout << arr[point] << " ";  // Print element as it's popped (reversed order)
        point--;
    }
}

void displayOriginalStack()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Stack elements: ";
    for (int i = 0; i <= point; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayReversedStack()
{
    cout << "Reversed Stack elements: ";
    while (!isEmpty())
    {
        pop();  // Pop and print elements (they will be printed in reverse order)
    }
    cout << endl;
}

int main()
{
    // Push elements into the original stack
    push(1);
    push(2);
    push(3);
    push(4);

    // Display original stack
    cout << "Original Stack: " << endl;
    displayOriginalStack();

    // Display reversed stack
    displayReversedStack();  // This will print elements in reverse order

    return 0;
}
