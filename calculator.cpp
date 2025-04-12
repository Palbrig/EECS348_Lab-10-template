#include "calculator.hpp"

// this function should expect that `expression` has already been
// validated and thus throw no exceptions
double parse_number(const std::string &expression){
    bool isNegative = false;
    std::size_t i = 0;

    if (expression[i] == '-')
    {
        isNegative = true;
        i++;
    }
    else if (expression[i] == '+')
    {
        i++;
    }

    double intPart = 0.0;
    while( i < expression.size() && isdigit(expression[i])){
        intPart = intPart * 10 + (expression[i] - '0');
        i++;
    }

    double deciPart = 0.0;
    if (i < expression.size() && expression[i] == '.'){
        i++;
        double divisor = 10.0;

        while (i<expression.size() && isdigit(expression[i])){
            deciPart += (expression[i] - '0') / divisor;
            divisor *= 10.0;
            i++;
        }
    }

    double result = intPart + deciPart;
    return isNegative ? -result : result;
}