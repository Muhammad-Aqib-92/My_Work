#include<iostream>
using namespace std;

bool checkSum(int A[], int start, int end, int k)
{
    if(A[start] + A[end] == k)
    {
        return true;
    }

if(start<end)
{
    return checkSum(A,start,end-1,k)||checkSum(A,start+1,end,k) ;
}

return false;

}

int main()
{
    int a[] = {8, 5, 3, 7, 2};

    cout<<checkSum(a,0,5,9);

}