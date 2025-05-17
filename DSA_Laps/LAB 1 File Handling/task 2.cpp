#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream red("student.txt");
    char c;
    while (red.get(c)) {
        cout << c;
    }
    red.close(); 
    return 0;
}
