#include<iostream>
#include<cmath>
using namespace std;


int power(int b,int p)
{
  if(p==0)
  {
     return 1;
  }
  return  b * power(b,p--);
}

int main()
{

 int base,pow;
 cout<<"Enter base number:"<<endl;
 cin>>base;
cout<<"Enter power number:"<<endl;
 cin>>pow;

 double result =  power(base,pow);
 cout<<result;


}