#include<iostream>
using namespace std;

const int size = 5;
int arr[size]={-1,-1,-1,-1,-1};

int hashing(int key)
{
    return key % size ;
}

int rehashing(int index)
{
    return (index + 1) % size;
}

void quadratic(int key)
{
    int i = 0;
    int index = hashing(key);
    int originalindex = index;
   if(arr[index]!=-1){
    while(arr[index]!=-1)
    {
        index = ((originalindex + i*i) % size);  
        i++; 
        if(originalindex == index)
        {
            cout<<"Array is already filled so no more filling possible "<<endl;
            return;
        }  
    }
    }
    else
    {
        arr[index] = key;
    }

}

void insert(int num)
{
    int index = hashing(num);
    int originalindex = index;
    
    if(arr[index] != 0){
    while(arr[index] != 0)
    {
        index = rehashing(index);
        if(index == originalindex)
        {
            cout<<"array is already filled so new entry not allowed"<<endl;
            return ;
        }
    }
    }
    else
    {
        arr[index] = num; 
    }
    

}


int main()
{
    cout<<"enter 5 numbers"<<endl;

    int number;

    for(int i = 0 ; i < size ; i++)
    {
         cin>>number;
         quadratic(number);
    }

    for(int i = 0; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}