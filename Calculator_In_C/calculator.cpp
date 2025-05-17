#include<iostream>
using namespace std;

int main()
{
    int operation ;
    while(true){
    cout<<"enter the operation you want to perform ?"<<endl;
    cout<<"You want to perform addition operation enter 1"<<endl;
    cout<<"You want to perform substraction operation enter 2"<<endl;
    cout<<"You want to perform multiplication operation enter 3"<<endl;
    cout<<"You want to perform Division operation enter 4"<<endl;
    cout<<"You do not want to perform any operation enter 5 for exit"<<endl;
    cin>>operation;
    int first,second;

    switch(operation)
    {
        case 1:
        cout<<"Enter first number"<<endl;
        cin>>first;
        cout<<"Enter second  number"<<endl;
        cin>>second;
        cout<<"Sum of these two numbers is :"<<first + second <<endl;
        break;

        case 2:
        cout<<"Enter first number"<<endl;
        cin>>first;
        cout<<"Enter second  number"<<endl;
        cin>>second;
        cout<<"substraction of these two numbers is :"<<first - second <<endl;
        break;

        case 3:
        cout<<"Enter first number"<<endl;
        cin>>first;
        cout<<"Enter second  number"<<endl;
        cin>>second;
        cout<<"Multiplication of these two numbers is :"<<first * second <<endl;
        break;
        
        
        case 4:
        cout<<"Enter first number"<<endl;
        cin>>first;
        cout<<"Enter second  number"<<endl;
        cin>>second;
        if(second != 0)
        {
        cout<<"Division of these two numbers is :"<<(float)first/second <<endl;
        break;
        }else
        {
            cout<<"divison with zero is not possible"<<endl;
            break;
        }
        
        case 5:
        exit(0);

        default:
        cout<<"Invalid choice make sure you choose exact number "<<endl;
        break;

    }
    }
    return 0;
}