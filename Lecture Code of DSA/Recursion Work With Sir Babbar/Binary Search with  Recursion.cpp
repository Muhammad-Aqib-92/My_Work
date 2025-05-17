#include<iostream>
using namespace std;

void print(int Arr[],int start , int end)
{
    for(int  i = start ; i <= end ; i++)
    {
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

bool binarySearch(int Arr[],int start,int end,int key)
{
    print(Arr,start,end);
    int mid = start + (end - start)/2;
    cout<<"Value of Mid is : "<<mid<<endl;
//first base case element not found
    if(start > end)
    {
        return false;
    }
//second base case element found 

    if(Arr[mid] ==  key)
    {
        return true;
    }
    else if(Arr[mid] < key)
    {
        bool ans  = binarySearch(Arr,mid+1,end,key);
        return ans;
    }
    else
    {
        bool ans  = binarySearch(Arr,start,mid-1,key);
        return ans; 
    }



}



int main()
{
    int Arr[] ={1,2,4,6,7, 23,77,88,99,100};
    int size = sizeof(Arr)/sizeof(Arr[0]);
    int start = 0;
    int end  =  size - 1;
    int key ;
    cout<<"Enter the element you want to search :"<<endl;
    cin>>key;

    bool result = binarySearch(Arr,start,end,key);

    if(result)
    {
        cout<<"Yes this number is present in the array"<<endl;
    }
    else
    {
        cout<<"This number is not present in the array"<<endl;
    }
    
        

}