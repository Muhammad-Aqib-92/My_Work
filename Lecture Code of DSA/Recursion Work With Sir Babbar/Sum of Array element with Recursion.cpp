#include<iostream>
using namespace std;

int ArraySum(int Arr[],int n)
{
    if(n == 1)
    {
        return Arr[0];
    }
    else
    {
        int sum = 0;
        sum = Arr[0] + ArraySum(Arr+1,n-1);
        return sum;
    }  
}

int main()
{
    int Arr[] = {3,2,5,1,7};
    int size = sizeof(Arr)/sizeof(Arr[0]);

    int result = ArraySum(Arr,size);

    cout<<"Here is the sum of the elements of the array: "<<result;

}