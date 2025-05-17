#include<iostream>
using namespace std;

void print(int Arr[],int n)
{
    cout<<"Size : "<< n<<endl;
    cout<<"array : ";

     for(int i = 0 ; i < n ;i++)
     {
        cout<<Arr[i]<<" ";
     }
     cout<<endl;
}

bool LinearSearch (int Arr[],int size ,int key)
{
    print(Arr,size);

    if(size == 0)
    {
        return false;
    }

    if(Arr[0]==key)
    {
        return true;
    }
    else
    {
        bool ans = LinearSearch(Arr+1,size-1,key);
        return ans;
    }
}

int main()
{
    int Arr[] = {2,32,4,1,3,5,6,8};
    int size = sizeof(Arr)/sizeof(Arr[0]);
    int num;
    cout<<"Enter the number you want to search"<<endl;
    cin>>num;

    bool result = LinearSearch(Arr,size,num);

    if(result)
    {
        cout<<"Element is present in the Array"<<endl;
    }
    else
    {
        cout<<"Element is not present in the array"<<endl;
    }

}