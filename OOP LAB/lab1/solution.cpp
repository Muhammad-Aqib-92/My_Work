#include <iostream>
#include <string>

using namespace std;

class fac {
    int id;
    string fn, ln, qua;
    float sal;

public:
    // Mutators
    void setid(int id) {
        id <= 1065 && id >= 1001 ? this->id = id : this->id = 0;
    }

    void setfn(string fn) {
        this->fn = fn;
    }

    void setln(string ln) {
        this->ln = ln;
    }

    void setqua(string qua) {
        this->qua = qua;
    }

    void setsal(float sal) {
        sal <= 100000.00 && sal >= 20000.00 ? this->sal = sal : this->sal = -1;
    }

    // Accessors
    int getid() {
        return id;
    }

    string getfn() {
        return fn;
    }

    string getln() {
        return ln;
    }

    string getqua() {
        return qua;
    }

    float getsal() {
        return sal;
    }

    // Constructors
    fac(int id, string fn, string ln, string qua) : id(id), fn(fn), ln(ln), qua(qua), sal(-1) {}

    fac(int id, string fn, string qua) : id(id), fn(fn), ln(" "), qua(qua), sal(-1) {}

    fac(int id, string fn, string ln, string qua, float sal) : id(id), fn(fn), ln(ln), qua(qua), sal(sal) {}

    fac(const fac &obj) {
        id = obj.id;
        fn = obj.fn;
        ln = obj.ln;
        qua = obj.qua;
        sal = obj.sal;
    }

    ~fac() {
        cout << "Destructor.....executed" << endl;
    }

    // Other member functions
    void setinfo(int id, string fn, string ln, string qua, float sal) {
        id <= 1065 && id >= 1001 ? this->id = id : this->id = 0;
        this->fn = fn;
        this->ln = ln;
        this->qua = qua;
        sal <= 100000.00 && sal >= 20000.00 ? this->sal = sal : this->sal = -1;
    }

    void read() {
        int id;
        cout << "Enter id:" << endl;
        cin >> id;
        id <= 1065 && id >= 1001 ? this->id = id : this->id = 0;
        cin.ignore();
        cout << "ENTER First name:" << endl;
        getline(cin, fn);
        cout << "ENTER Last name:" << endl;
        getline(cin, ln);
        cout << "ENTER Qualification:" << endl;
        getline(cin, qua);
        float sal;
        cout << "Enter sal:" << endl;
        cin >> sal;
        sal <= 100000.00 && sal >= 20000.00 ? this->sal = sal : this->sal = -1;
    }

    void display() {
        cout << "Id: " << id << endl;
        cout << "First name: " << fn << endl;
        cout << "Last name: " << ln << endl;
        cout << "Qualification: " << qua << endl;
        cout << "Salary: " << sal << endl;
    }

    bool ispG() {
        return (qua == "Phd" || qua == "MS");
    }

    float Homesal() {
        float Hsal;
        float tax = sal * 0.07;
        sal >= 20000.00 ? Hsal = sal - tax : Hsal = -1;
        return Hsal;
    }

    bool isJ() {
        return (sal >= 20000.00);
    }
};

int main() {
    // Create an object of the class `fac`
    fac o1(1001, "John", "Doe", "Phd", 30000.00);  // Initialize with sample values
    o1.read();
    o1.display();
    return 0;
}
