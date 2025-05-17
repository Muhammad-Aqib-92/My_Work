#include<iostream>
using namespace std;

int SumOfArray(int A[], int n)
{
    if(n==0)
    {
        return 0;
    }
    return A[n-1]  + SumOfArray(A,n-1);
}

int main()
{
    int num[4] = {1,2,3,4};
    int size = 4;

   int sum = SumOfArray(num,size);
    cout<<sum;
    return 0;


}s