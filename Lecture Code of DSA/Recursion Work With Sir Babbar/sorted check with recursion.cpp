#include<iostream>
using namespace std;


bool isSorted(int Arr[],int size)
{
    if(size == 0 || size == 1)
    {
        return true;
    }
    
    if(Arr[0]>Arr[1])
    {
        return false;
    }
    else
    {
        bool ans = isSorted(Arr+1,size-1);
        return ans;
    }
}


int main()
{
    int Arr[] ={1,2,3,4,5,6};
    int size = sizeof(Arr)/sizeof(Arr[0]);

    bool res = isSorted(Arr,size);

    if(res)
    {
        cout<<"Array is Sorted "<<endl;
    }
    else
    {
        cout<<"Array is not sorted"<<endl;
    }


}