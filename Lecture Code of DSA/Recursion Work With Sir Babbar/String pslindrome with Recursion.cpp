#include<iostream>
using namespace std;


bool palindrome(string String,int start,int end)
{
    if(start>end)
    {
        return true;
    }

    if(String[start] != String[end])
    {
        return false;
    }
    else
    {
        palindrome(String,start+1,end-1);

    }
}

int main()
{
    string  name = "aqib";
    bool ans = palindrome(name,0,name.length()-1);
    if(ans)
    {
        cout<<"String is palindrome"<<endl;
    }
    else
    {
        cout<<"String is not palindrome"<<endl;
    }

}
