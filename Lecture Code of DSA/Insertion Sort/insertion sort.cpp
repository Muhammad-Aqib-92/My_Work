#include<iostream>

using namespace std;

int main()
{
    int size = 7 ;
    int a[size] = {45, 29, 87, 65, 12, 98, 35};

    for(int i = 1 ; i < size ; i++)
    {
        int j = i ;
    while( j > 0 &&  a[j] < a[j - 1])
    {
        swap(a[j],a[j-1]);
        j--;
    }
}
for(int i = 0  ; i < size ;i++)
    {
        cout << a[i]<<" ";
    }

}