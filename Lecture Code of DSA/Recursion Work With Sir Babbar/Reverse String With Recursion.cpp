#include<iostream>
using namespace std;

// void print(string name ,int start,int end)
// {
//     for(int i = start;i <=  end ;i++)
//     {
//         cout<<name[i]<<" ";
//     }
//     cout<<endl;
// }



void reverse(string& name,int start , int end)
{
    // print(name,start,end);
    cout<<name<<endl;
    if(start > end)
    {
        return ;
    }

    swap(name[start],name[end]);
    start++;
    end--;
    reverse(name,start,end);

}



int main()
{
    string name = "abcde";
    int start = 0;
    int end  = name.length()-1;
    reverse(name,start,end);
    cout<<name;


}