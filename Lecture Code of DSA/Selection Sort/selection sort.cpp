#include<iostream>

using namespace std;

int main()
{
    int size = 5;
    int a[size]= {29,10,14,37,13};

    for(int i = 0 ;  i < size ; i++)
    {
        int min = i ;
        for(int j = i + 1 ; j < size ; j++ )
        {
            if(a[min]>a[j])
            min = j ;
        }
        swap(a[min],a[i]);
    }

    for(int i = 0 ; i < size ; i++)
    {
        cout<<a[i]<<" ";
    }

} 