#include<iostream>

using namespace std;

template<typename T> 
class Linear
{
    private:
    T  alpha , beta ;
    public:

    Linear()
    {
        alpha =  beta = 0 ;
    }

    Linear(T al , T bet)
    {
         alpha = al;
         beta = bet ;
    }

    void getData()
    {
        cout<<"Enter the Alpha value:"<<endl;
        cin>> alpha ;
        cout<<"Enter the Beta value:"<<endl;
        cin>> beta ;
    }

void printdata()
    {
cout<<"Data members are here "<<endl<<
"Alpha:"<<alpha<<endl<<"Beta :"<<beta<<endl;

    }

friend istream& operator >>(istream& in , Linear &obj)
    {
        cout<<"Enter the value of alpha"<<endl;
        in >>obj.alpha ;
        cout<<"Enter the value of beta"<<endl;
        in >> obj.beta ;
        return in;
    }

    void print();
    template<typename t>
    friend  ostream& operator <<(ostream& out,const Linear<t> &obj);

};

template< typename T>
void Linear<T>::print()
{
    cout<<"Alpha value is :"<<alpha<<endl;
    cout<<"Beta value is  :"<<beta<endl;
}

template <typename t>
ostream& operator<<(ostream & out, const Linear <t> &obj)
{
    out <<"Alpha Value is "<<obj.alpha<<endl;
    out <<"Beta  Value is "<<obj.beta <<endl;
    return out;
}

int main()
{
    Linear<int>obj ;
    obj.getData();
    obj.printdata();  
    Linear <float> obj1(10.0,20.2);
    obj1.printdata();

}
