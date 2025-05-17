#include<iostream>
using  namespace std;

int powercheck(int base,int power)
{
    if(power == 0 )
    {
        return 1;
    }
    else
    {
        return base * powercheck(base,power-1); 
    }
}

int main()
{
    int base , power;
    cout<<"Enter the base :"<<endl;
    cin>>base;
    cout<<"Enter the power"<<endl;
    cin>>power;
    int result = powercheck(base,power);

    cout<<"Here is the result: "<<result;

}

