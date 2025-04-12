#include <iostream>

#include "calculator.hpp"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const double NUM2 = -123.456;

int main(int argc, char *argv[]) {
    double num1;
    
    string filename = "";
    ifstream file(filename);
    vector<string> lines;
    string line;

    if (!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
    }

    while (getline(file, line)) {
        if (!line.empty()){
            lines.push_back(line);
        }
    }

    file.close();

    for (string line : lines){
        if(is_valid(line)){
            num1 = parse_number(line);
            cout << num1 + NUM2 << endl;
        }
        else
            cerr << "Invalid number. " << line << endl;
    }
}

bool is_valid(string expression){
    int n = expression.length();

    if (n == 0)
        return false;

    int i = 0;

    bool hasDigitsBeforeDot = false;
    bool hasDot = false;
    bool hasDigitsAfterDot = false;

    if (expression[i] == '+' || expression[i] == '-')
    {
        i++;
        if (i == n)
            return false;
    }

    for (; i < n; ++i){
        char c = expression[i];

        if (c >= '0' && c <= '9'){
            if (!hasDot)
                hasDigitsBeforeDot = true;
            else
                hasDigitsAfterDot = true;

        }
        else if (c == '.')
        {
            if(hasDot)
                return false;
            hasDot = true;
            if (i == n - 1)
                return false;
        }
        else
            return false;
    }

    if(!hasDot)
        return hasDigitsBeforeDot;
    else
        return hasDigitsAfterDot;
}