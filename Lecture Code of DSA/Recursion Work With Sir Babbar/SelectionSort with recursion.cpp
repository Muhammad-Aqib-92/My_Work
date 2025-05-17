#include<iostream>
using namespace std;

void print(int Arr[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}


void selectionsort(int Arr[],int n)
{
    if(n==0||n==1)
    {
        return ;
    }
    int min = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(Arr[i]<Arr[min])
        {
            min = i;
        }
    }
    swap(Arr[0],Arr[min]);
    print(Arr,n);
    selectionsort(Arr+1,n-1);
}

int main()
{
    int Arr[] = {1,4,5,6,7,3,8};
    int size = sizeof(Arr)/sizeof(Arr[0]);
    selectionsort(Arr,size);
    for(int i = 0 ; i < size; i++)
    {
        cout<<Arr[i]<<" ";
    }
    cout<<endl;

}