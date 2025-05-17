#include<iostream>
using namespace std;

void print(int Arr[],int start, int end)
{
    for(int i = start; i <= end;i++)
    {
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int Arr[],int start ,int end)
{
    if(start>=end)
    {
        return;
    }
    int mid = start + (end -start)/2;
   
    int sizel = mid - start +1;
    int sizer = end-mid;
    
    int *L1 = new int[sizel]; 
    int *L2 = new int[sizer];

    for(int i = 0 ; i < sizel;i++)
    {
        L1[i] = Arr[start+i];
    } 
    for(int i = 0 ; i < sizer;i++)
    {
        L2[i] = Arr[mid+1+i];
    } 

    int mainindex = start;
    int leftsub = 0,rightsub = 0;
    while(leftsub < sizel && rightsub < sizer)
    {
        if(L1[leftsub]>L2[rightsub])
        {
            Arr[mainindex++] = L2[rightsub++];
        }
        if(L2[rightsub]>L1[leftsub])
        {
            Arr[mainindex++] = L1[leftsub++];
        }   
    }

    if(leftsub<sizel)
    {
        Arr[mainindex++] =L1[leftsub++];
    }
    if(rightsub<sizer)
    {
        Arr[mainindex++] = L2[rightsub++];
    }
    
    delete[] L1;
    delete[] L2;
}


void mergeSort(int Arr[],int start,int end)
{
    if(start>=end)
    {
        return;
    }

    int mid = start + (end-start)/2;

    mergeSort(Arr,start,mid);
    print(Arr,start,mid);
    mergeSort(Arr,mid+1,end);
    print(Arr,mid+1,end);
    merge(Arr,start,end);
    print(Arr,start,end);

}


int main()
{
    int Arr[] = {5,2,1,3,4,8,7,6,0,9};
    int size = sizeof(Arr)/sizeof(Arr[0]);
    mergeSort(Arr,0,size-1);

    for(int i = 0 ;i < size ;i++)
    {
        cout<<Arr[i]<<" ";
    }

}