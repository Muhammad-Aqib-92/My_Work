#include<iostream>
using namespace std;

void bubblesort(int Arr[],int n)
{
    if( n == 0|| n == 1)
    {
        return;
    }
    for(int i = 0; i< n-1;i++)
    {
        if(Arr[i]>Arr[i+1]){
        swap(Arr[i],Arr[i+1]);
        }
    }
    bubblesort(Arr,n-1);
}


int main()
{
    int arr[] = {2,1,3,4,6,23};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,size);

    for(int i = 0 ; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}