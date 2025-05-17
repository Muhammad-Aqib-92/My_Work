#include<iostream>
using namespace std;


int parition(int Arr[],int start,int end)
{
    int p = start;
   while(start<end)
    {        
        while(Arr[start]<=Arr[p] && start < end )
        {
               start++;
        }
        while(Arr[end]>Arr[p] && start < end)
        {
            end--;
        }
        if(start<end)
        {
            swap(Arr[start],Arr[end]);
        }  
    }
    swap(Arr[end],Arr[p]);
    return end;
}

void quickSort(int Arr[],int start,int end)
{
    if(start<end)
    {
        int par = parition(Arr,start,end);

        quickSort(Arr,start,par-1);
        quickSort(Arr,par+1,end);
    }
    
}



int main()
{
    int Arr[] = {3,7,8,5,2,1,9};
    int size =sizeof(Arr)/sizeof(Arr[0]);
    quickSort(Arr,0,size-1);

    for(int i = 0; i < size ; i++)
    {
        cout<<Arr[i]<<" ";

    }


}
