#include<iostream>
#include<fstream>

using namespace std;

void eraseobject(int**ar,int rowcount,int columncount , int x , int y)
{
    if(x < 0 || x >= rowcount || y < 0 || y  == columncount || ar[x][y] == 0)
    {
        return ;
    }
    ar[x][y] = 0 ;

    eraseobject(ar,rowcount,columncount,x+1,y);
    eraseobject(ar,rowcount,columncount,x-1,y);
    eraseobject(ar,rowcount,columncount,x,y+1);
    eraseobject(ar,rowcount,columncount,x,y-1);
}

int main()
 {
    ifstream inf("input_0.txt");
    if(!inf.is_open())
    {
        cout<<"Failed to open the file"<<endl;
        exit(0);
    }

    int row , col ,p_x , p_y;
    inf >> row >> col;
    inf >> p_x >> p_y;

    int ** arr = new int*[row];
    
    for(int i = 0 ; i < row ; i++)
    {
        arr[i] = new int[col];
    }

    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            inf >> arr[i][j];
        }
    }

    inf.close();

    eraseobject(arr,row,col,p_x,p_y);

    for(int i = 0; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i = 0 ; i < row ; i++)
    {
        delete [] arr[i];

    }
    delete [] arr;
return 0;

}
