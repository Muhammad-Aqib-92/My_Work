#include<iostream>
using namespace std;

int squreSum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return (n * n) + squreSum(n -1);
}





int main()
{    
int num;
cout<<"Enter the number you want to enter:"<<endl;
cin>>num;

 int result =   squreSum(num);
 cout<<result;   


}