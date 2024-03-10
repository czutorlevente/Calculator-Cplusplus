#include <stdexcept>
#include <cmath>
using namespace std;

class Calculator 
{
    public:

    //Add numbers up.
    double add_up(double a, double b)
    {
        return a + b;
    }

    //Substract two numbers from each other.
    double substract(double a, double b)
    {
        return a - b;
    }

    //Multiply two numbers with each other.
    double multiply(double a, double b)
    {
        return a * b;
    }

    //Divide a number by another.
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

    //Perform exponentation. Lift "a" to the power of "b".
    double power(double a, double b)
    {
        return pow(a, b);
    }
};