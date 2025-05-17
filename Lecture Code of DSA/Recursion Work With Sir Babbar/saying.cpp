#include<iostream>
using namespace std;



void say(int nu,string Arr[])
{
    if(nu == 0)
    {
        return ;
    }
    int digit = nu % 10 ;
    nu = nu /10;

    say(nu,Arr);

    cout<<Arr[digit]<<" ";
}


int main()
{
    int num;

    string Arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

    cout<<"Enter the number:"<<endl;
    cin>>num;

    say(num,Arr);
    
}