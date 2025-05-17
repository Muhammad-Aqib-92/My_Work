#include<iostream>
using namespace std;


void ReverseArray(int A[],int start,int end)
{
    if(start < end)
    {
        swap(A[start],A[end]);
        ReverseArray(A,start++,end--);
    }
}

int main()
{
    int B[] = {1, 2, 3, 4, 5, 6};

    ReverseArray[B,0,5];

}


