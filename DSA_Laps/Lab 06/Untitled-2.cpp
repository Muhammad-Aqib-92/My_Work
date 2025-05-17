#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

bool delimitersOk(const string &expression){
    stack<char> stack;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);  
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty()) return false;
            
            char top = stack.top();
            stack.pop();
   
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.empty(); 
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    int numExpressions;
    inputFile >> numExpressions;
    string expression;
    getline(inputFile, expression);     
    for (int i = 0; i < numExpressions; ++i) {
        getline(inputFile, expression);
        if (delimitersOk(expression)) {
            cout << "Valid" << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }
    
    inputFile.close();
    return 0;
}
