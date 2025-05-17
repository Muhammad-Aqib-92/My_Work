#include <iostream>
#include <cmath> 

using namespace std;

class Time {

private:
    int second, hour, minute;

public:
  
    Time() : second(0), minute(0), hour(0) {}

    Time(int sec, int min, int ho) :
        second((sec >= 0 && sec <= 59) ? sec : 0),
        minute((min >= 0 && min <= 59) ? min : 0),
        hour((ho >= 0 && ho <= 23) ? ho : 0) {}

    Time(int min, int ho) :
        minute((min >= 0 && min <= 59) ? min : 0),
        hour((ho >= 0 && ho <= 23) ? ho : 0),
        second(0) {}

    void Setsec(int a) {
        second = (a >= 0 && a <= 59) ? a : 0;
    }

    void Setmin(int m) {
        minute = (m >= 0 && m <= 59) ? m : 0;
    }

    void Setho(int n) {
        hour = (n >= 0 && n <= 23) ? n : 0;
    }

    int getsec() const {
        return second;
    }

    int getmin() const {
        return minute;
    }

    int getho() const {
        return hour;
    }

    void Setful(int min, int sec, int ho) {
        minute = (min >= 0 && min <= 59) ? min : 0;
        second = (sec >= 0 && sec <= 59) ? sec : 0;
        hour = (ho >= 0 && ho <= 23) ? ho : 0;
    }

    friend ostream& operator<<(ostream& os, const Time& obj) {
        os << obj.hour << ":" << obj.minute << ":" << obj.second;
        return os;
    }

    friend istream& operator>>(istream& in, Time& obj) {
        cout << "Enter time in format HH:MM:SS" << endl;
        in >> obj.hour >> obj.minute >> obj.second;
        return in;
    }

    // Pre-increment
    Time& operator++() {
        second++;
        if (second >= 60) {
            second = 0;
            ++minute;
        }
        if (minute >= 60) {
            minute = 0;
            ++hour;
        }
        if (hour >= 24) {
            hour = 0;
        }
        return *this;
    }

    
    Time& operator--() {
        second--;
        if (second < 0) {
            second = 59;
            minute--;
        }
        if (minute < 0) {
            minute = 59;
            hour--;
        }
        if (hour < 0) {
            hour = 23;
        }
        return *this;
    }

    
    Time operator++(int) {
        Time obj(*this);
        ++(*this); 
        return obj;
    }

    
    Time operator--(int) {
        Time temp(*this);
        --(*this); 
        return temp;
    }

    int operator-(const Time& obj) const {
        int total = hour * 3600 + minute * 60 + second;
        int stotal = obj.hour * 3600 + obj.minute * 60 + obj.second;
        return abs(total - stotal);
    }

    bool operator+() const {
        int crt = hour * 3600 + minute * 60 + second;
        int wst = 9 * 3600;  
        int wet = 17 * 3600; 
        return (crt >= wst && crt <= wet);
    }
};

int main() {
    Time o1(45, 59, 12); 
    cout << "Initial Time: " << o1 << endl;

    o1++;
    cout << "After Increment: " << o1 << endl;

    --o1;
    cout << "After Decrement: " << o1 << endl;

    Time o2(30, 59, 11);
    int difference = o1 - o2;
    cout << "Difference in seconds: " << difference << endl;

    bool withinShift = +o1;
    cout << "Is time within work shift? " << (withinShift ? "Yes" : "No") << endl;

    return 0;
}
