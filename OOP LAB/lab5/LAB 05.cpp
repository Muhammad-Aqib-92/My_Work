#include "iostream"

using namespace std;

class FeetInches
{
private:
    int feet;          
    int inches;
    void simplify()
    {
        if (inches >= 12)
        {
            feet += (inches / 12);
            inches = inches % 12;
        }
        else if (inches < 0)
        {
            feet -= ((abs(inches) / 12) + 1);
            inches = 12 - (abs(inches) % 12);
        }
    }

public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // Copy constructor
    FeetInches(const FeetInches& right)
    {
        feet = right.feet;
        inches = right.inches;
        simplify();
    }

    // Mutator function to set feet
    void setFeet(int f)
    {
        feet = f;
    }

    // Mutator function to set inches
    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    // Accessor function to get feet
    int getFeet() const
    {
        return feet;
    }

    // Accessor function to get inches
    int getInches() const
    {
        return inches;
    }

    // Overloaded + operator
    FeetInches operator + (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches + right.inches;
        temp.feet = feet + right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded - operator
    FeetInches operator - (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches - right.inches;
        temp.feet = feet - right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded * operator
    FeetInches operator * (const FeetInches& right)
    {
        FeetInches temp;

        temp.inches = inches * right.inches;
        temp.feet = feet * right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded prefix ++ operator
    FeetInches operator ++ ()
    {
        ++inches;
        simplify();

        return *this;
    }

    // Overloaded postfix ++ operator
    FeetInches operator ++ (int)
    {
        FeetInches temp(feet, inches);

        inches++;
        simplify();

        return temp;
    }

    // Overloaded prefix -- operator
    FeetInches operator -- ()
    {
        --inches;
        simplify();

        return *this;
    }

    // Overloaded postfix -- operator
    FeetInches operator -- (int)
    {
        FeetInches temp(feet, inches);

        inches--;
        simplify();

        return temp;
    }

    // Overloaded > operator
    bool operator > (const FeetInches& right) const
    {
        bool status;

        if (feet > right.feet)
            status = true;
        else if (feet == right.feet && inches > right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded < operator
    bool operator < (const FeetInches& right) const
    {
        return !(*this > right);
    }

    // Overloaded >= operator
    bool operator >= (const FeetInches& right) const
    {
        bool status;

        if (feet >= right.feet)
            status = true;
        else if (feet == right.feet && inches >= right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded <= operator
    bool operator <= (const FeetInches& right) const
    {
        return !(*this >= right);
    }

    // Overloaded == operator
    bool operator == (const FeetInches& right) const
    {
        bool status;

        if (feet == right.feet && inches == right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded != operator
    bool operator != (const FeetInches& right) const
    {
        return !(*this == right);
    }

    // Friend function to overload << operator for output
    friend ostream& operator << (ostream&, const FeetInches&);

    // Friend function to overload >> operator for input
    friend istream& operator >> (istream&, FeetInches&);
};

// Overloaded << operator
ostream& operator << (ostream& out, const FeetInches& obj)
{
    out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

    return out;
}

// Overloaded >> operator
istream& operator >> (istream& in, FeetInches& obj)
{
    cout << "Enter Feet:\t";
    in >> obj.feet;

    cout << "Enter Inches:\t";
    in >> obj.inches;

    return in;
}

class RoomDimension{

    private:

    FeetInches length ,width ;

    public:

   RoomDimension(FeetInches length,FeetInches width):
   length(length),width(width){}

   void setLength(FeetInches a){
			length = a;   
                  }
	void setWidth(FeetInches b){
			width = b;
		}
    FeetInches getLength()const{
			return length;
		}
    FeetInches getWidth()const{
			return width;
		}
    int  roomArea(FeetInches length,FeetInches width){
		    int area;
			area = length.getFeet()*width.getFeet();
			return area;
		}

    void RoomDimensionInfo(){
			if(length != 0 && width != 0){
				cout<<"Length: "<<endl;
				cout<<"Feet: "<<length.getFeet()<<endl;
				cout<<"Inches: "<<length.getInches()<<endl;
				cout<<endl;
				cout<<"Width: "<<endl;
				cout<<"Feet: "<<width.getFeet()<<endl;
				cout<<"Inches: "<<width.getInches()<<endl;
			}
		}

        void putDimension(FeetInches a,FeetInches b){
			cout<<"Enter Length: ";
			cin>>a;
			cout<<"Enter Width: ";
			cin>>b;
		}

    
};


class RoomCarpet{
	private:
		RoomDimension roomSize;
		float costPerSquareFoot;
	public:
		RoomCarpet(RoomDimension a,float b):
        roomSize(a),costPerSquareFoot(b){}

	    void setRoomSize(RoomDimension a){
            	roomSize = a;
		}
		void setCostPerSquareFoot(float b){
			costPerSquareFoot = b;
		}
		RoomDimension getRoomSize()const{
			return roomSize;
		}
		float getCostPerSquareFoot()const{
			return costPerSquareFoot;
		}
		FeetInches totalCost(){
			float a;
			FeetInches cost;
			a = costPerSquareFoot;
			cost = (roomSize.getLength())*(roomSize.getWidth())*a;
			return cost;
		}
		void RoomCarpetInfo(){
			cout<<"Room Size: "<<endl;
			cout<<"Length: "<<roomSize.getLength()<<endl;
			cout<<"Width: "<<roomSize.getWidth()<<endl;
			cout<<"CostPerSquareFoot: "<<costPerSquareFoot<<endl;
		}

};


int main(){
    







    
}