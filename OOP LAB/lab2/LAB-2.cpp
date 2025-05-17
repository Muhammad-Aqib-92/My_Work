#include <iostream>
#include <string>
using namespace std;

class Ball {
private:
    int id;
    string name;
    int quantity;
    float price;

public:

    Ball(int id, string name, int quantity, float price) {
        this->id = id > 0 ? id : 0;
        this->name = name;
        this->quantity = quantity > 0 ? quantity : 0;
        this->price = price > 0 ? price : 0;
    }

    Ball(int id, string name, int quantity) {
        this->id = id > 0 ? id : 0;
        this->name = name;
        this->quantity = quantity > 0 ? quantity : 0;
        this->price = 0;
    }

    Ball(int id, string name, float price) {
        this->id = id > 0 ? id : 0;
        this->name = name;
        this->quantity = 0;
        this->price = price > 0 ? price : 0;
    }

    // Copy constructor
    Ball(const Ball& obj) {
        this->id = obj.id;
        this->name = obj.name;
        this->quantity = obj.quantity;
        this->price = obj.price;
    }

    // Destructor
    ~Ball() {
        cout << endl;
    }

    // Mutators (setters)
    void setId(int id) {
        this->id = id > 0 ? id : 0;
    }

    void setName(string name) {
        this->name = name;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity > 0 ? quantity : 0;
    }

    void setPrice(float price) {
        this->price = price > 0 ? price : 0;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    float getPrice() const {
        return price;
    }

    void setBall(int id, string name, int quantity, float price) {
        setId(id);
        setName(name);
        setQuantity(quantity);
        setPrice(price);
    }

    void getBall() {
        cout << "Enter Ball ID: ";
        cin >> id;
        cout << "Enter Ball Name: ";
        cin >> name;
        cout << "Enter Ball Quantity: ";
        cin >> quantity;
        cout << "Enter Ball Price: ";
        cin >> price;

        setBall(id, name, quantity, price);
    }

    void putBall() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Quantity: " << quantity << ", Price: " << price << endl;
    }

    float getTotalPrice() const {
        return quantity >= 1 ? price * quantity : 0;
    }

    bool isSame(const Ball &obj) const {
        return id == obj.id && name == obj.name && quantity == obj.quantity && price == obj.price;
    }

    void updateName(Ball arr[], int size) {
        for (int i = 0; i < size; ++i) {
            if (id == arr[i].getId()) {
                arr[i].setName(name);
            }
        }
    }

    static Ball getMaximumPriceBall(Ball arr[], int size) {
        Ball maxBall = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i].getPrice() > maxBall.getPrice()) {
                maxBall = arr[i];
            }
        }
        return maxBall;
    }

    void getAveragePrice(Ball arr[], int size) {
        float sum = 0;
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i].getPrice() <= 50) {
                sum += arr[i].getPrice();
                ++count;
            }
        }
        if (count > 0) {
            price = sum / count;
        } else {
            price = 0;
        }
    }
};

int main() {
    Ball o1(21, "Aqib", 5, 10.5);
    o1.putBall();

    Ball o2(22, "BrandX", 3);
    o2.putBall();

    Ball o3(23, "BrandY", static_cast<float>(15.5));
    o3.putBall();

    Ball o4(o1);
    o4.putBall();

    Ball balls[] = {o1, o2, o3, o4};
    int size = sizeof(balls) / sizeof(balls[0]);

    cout << "Total Price of o1: " << o1.getTotalPrice() << endl;

    cout << "Is o1 same as o4? " << (o1.isSame(o4) ? "Yes" : "No") << endl;

    o1.updateName(balls, size);
    for (int i = 0; i < size; ++i) {
        balls[i].putBall();
    }

    Ball maxPriceBall = Ball::getMaximumPriceBall(balls, size);
    cout << "Ball with maximum price: ";
    maxPriceBall.putBall();

    Ball avgPriceBall(0, "Average", 0);
    avgPriceBall.getAveragePrice(balls, size);
    cout << "Average price of balls with price <= 50: " << avgPriceBall.getPrice() << endl;

    return 0;
}
