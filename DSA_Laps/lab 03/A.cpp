#include<iostream>

using namespace std;

class Matrix
{
    private:
    int *ptr;
    int row , col;

    public:
    Matrix(int r , int c) : row(r), col(c)
    {
        ptr = new int[row * col]();
    }

    // Copy constructor
    Matrix(const Matrix &other)
    {
        row = other.row;
        col = other.col;
        ptr = new int[row * col];
        for (int i = 0; i < row * col; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }

    // Copy assignment operator
    Matrix& operator=(const Matrix &other)
    {
        if (this != &other)
        {
            delete[] ptr;
            row = other.row;
            col = other.col;
            ptr = new int[row * col];
            for (int i = 0; i < row * col; i++)
            {
                ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }

    int get(int r , int c)
    {
        if(r < 0 || r >= row || c < 0  || c >= col)
        {
            cout <<"Index out of bound"<<endl;
        }
        return ptr[r * col + c ];
    }

    void set(int r , int c, int num)
    {
        if(r < 0 || r >= row || c < 0 || c >= col)
        {
            cout <<"Index out of  bound"<<endl;
        }
        ptr[r * col + c] = num;
    }

    void print()
    {
        for (int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                cout << ptr[ i * col + j] <<" ";
            }
            cout << endl;
        }
    }

    void transpose()
    {
        for(int i = 0 ; i <  row ; i++)
        {
            for(int j = i+ 1 ; j < col ; j++)
            {
                swap(ptr[i * col + j],ptr[j * col + i]);
            }
        }
    }

    void printsubmatrix(int r1 , int r2 , int c1 ,int c2)
    {
        if (r1 < 0 || r2 >= row || c1 < 0 || c2 >= col || r1 > r2 || c1 > c2) 
        {
            cout<<"Invalid Index"<<endl;
        }

        for(int i = r1 ; i <= r2 ; i++)
        {
            for(int j = c1 ; j <= c2 ;j++)
            {
                cout << ptr[i * col + j]<<" ";
            }
            cout << endl;
        }
    }

    void makeEmpty(int n) 
    {
        for (int i = 0; i < n && i < row; i++) 
        {
            for (int j = 0; j < n && j < col; j++) 
            {
                ptr[i * col + j] = 0;  
            }
        }
    }

    void addmatrix(const Matrix &a, const Matrix &b)
    {
        if(a.row != row || a.col != col || b.row != row || b.col != col)
        {
            cout<<"As Order of Matrix is not Same so addition is not possible"<<endl;
        }
        else
        {
            for(int i = 0 ; i < row ; i++)
            {
                for(int j = 0 ; j < col ; j++)
                {
                    ptr[i * col + j] = a.ptr[i * col + j] + b.ptr[i * col + j];
                }
            }
        }
    }

    ~Matrix()
    {
        delete[] ptr;
        ptr = nullptr;
    }
};

int main()
{
    Matrix a(2,2);
    a.set(0,0,1);
    a.set(0,1,2);
    a.set(1,0,3);
    a.set(1,1,4);

    cout<<"Matrix A:"<<endl;
    a.print();

    Matrix b(2,2);
    b.set(0,0,5);
    b.set(0,1,6);
    b.set(1,0,7);
    b.set(1,1,8);

    cout <<"Matrix B:"<<endl;
    b.print();

    Matrix c(2,2);
    c.addmatrix(a,b);

    cout<<"Addition Result of Two Matrixes:"<<endl;
    c.print();

    cout<<"MakeEmpty(1):"<<endl;
    c.makeEmpty(1);
    c.print();

    cout<< "Here Is Submatrix:"<<endl;
    a.printsubmatrix(0,1,0,1);

    cout<<"Transpose of Matrix A:"<<endl;
    a.transpose();
    a.print();

    return 0;
}
