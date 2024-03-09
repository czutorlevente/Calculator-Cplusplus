#include <stdexcept>
#include <cmath>
using namespace std;

class Calculator 
{
    public:

    double add_up(double a, double b)
    {
        return a + b;
    }

    double substract(double a, double b)
    {
        return a - b;
    }

    double multiply(double a, double b)
    {
        return a * b;
    }

    double divide(double a, double b)
    {
        if (b)
        {
            return a / b;
        }
        
        else
        {
            throw invalid_argument("Division by zero is not possible");
        }
    }

    double power(double a, double b)
    {
        return pow(a, b);
    }
};