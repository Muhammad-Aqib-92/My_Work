#include<iostream>

using namespace std;

int main()
{
    int size = 6 ;
int a[size] ={6,5,4,3,2,1};


for(int i = 0 ; i < size - 1 ; i++)
{
    for(int j = 0 ; j < size - i - 1 ; j++)
    {
        if(a[j]<a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }
    
    }


for(int i = 0 ; i < size ; i++)
{
    cout<<a[i]<<" ";
}

}


