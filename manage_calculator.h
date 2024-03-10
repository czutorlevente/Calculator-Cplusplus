#include <stdexcept>
#include <iostream>
#include "calculator.h"
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

class Manager
{

public:
    void Play()
    {
        
        bool stop = false;
        Calculator *cal = new Calculator();
        ofstream memoryFile("memory.txt", std::ios::app);

        Greeting();
        cout << "Welcome to the Calculator app!" << endl;

        while (!stop)
        {
            
            cout << "\n1 - add numbers up\n2 - substract\n3 - multiply\n4 - division\n5 - exponentation\n6 - exit app" << endl;
            cout << "What do you choose? " << endl;

            bool invalidChoice = true;
            int choice;

            while (invalidChoice == true)
            {
                cin >> choice;
                if (cin.fail()) 
                {
                    cerr << "Error: Invalid input" << endl;
                    cin.clear(); // Clear the fail state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } 
                else if (choice < 1 || choice > 6) 
                {
                    cerr << "Error: Invalid choice. Please enter a number between 1 and 6." << endl;
                } 
                else
                {
                invalidChoice = false;
                }

            } 

            if (choice == 1)
            {
                bool stop_add = false;
                double a;
                double b;
                cout << "Keep adding numbers and then 'add' 0 if you want to see the result!\nWhat is you first number? ";
                cin >> a;
                cout << " \n" << endl;
                string add_history = to_string(a);
                string final_add_history = "";
                while (!stop_add)
                {
                    add_history = add_history + " + ";
                    cout << "\033[1A" << "\r" << add_history << flush;

                    cin >> b;
                    if (b != 0)
                    {
                        a = cal->add_up(a, b);
                        add_history = add_history + to_string(b);
                        final_add_history = add_history;

                    }

                    else
                    {
                        stop_add = true;
                        final_add_history = final_add_history + " = " + to_string(a);
                        cout << "\033[1A" << "\r" << final_add_history << flush << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        memoryFile << final_add_history << endl;
                    }

                }
                
            }

            else if (choice == 2)
            {
                bool stop_s = false;
                double a;
                double b;
                cout << "Keep substracting numbers and then 'substract' 0 if you want to see the result!\nWhat is you first number? ";
                cin >> a;
                cout << " \n" << endl;
                string add_history = to_string(a);
                string final_add_history = "";
                while (!stop_s)
                {
                    add_history = add_history + " - ";
                    cout << "\033[1A" << "\r" << add_history << flush;

                    cin >> b;
                    if (b != 0)
                    {
                        a = cal->substract(a, b);
                        add_history = add_history + to_string(b);
                        final_add_history = add_history;

                    }

                    else
                    {
                        stop_s = true;
                        final_add_history = final_add_history + " = " + to_string(a);
                        cout << "\033[1A" << "\r" << final_add_history << flush << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        memoryFile << final_add_history << endl;
                    }

                }
                
            }

            else if (choice == 3)
            {
                bool stop_mult = false;
                double a;
                double b;
                cout << "Keep adding numbers to multipy and then 'multiply' with 0 if you want to see the result!\nWhat is you first number? ";
                cin >> a;
                if (cin.fail()) 
                {
                    cerr << "Error: Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                cout << " \n" << endl;
                string add_history = to_string(a);
                string final_add_history = "";
                while (!stop_mult)
                {
                    add_history = add_history + " * ";
                    cout << "\033[1A" << "\r" << add_history << flush;

                    cin >> b;
                    if (b != 0)
                    {
                        a = cal->multiply(a, b);
                        add_history = add_history + to_string(b);
                        final_add_history = add_history;

                    }

                    else
                    {
                        stop_mult = true;
                        final_add_history = final_add_history + " = " + to_string(a);
                        cout << "\033[1A" << "\r" << final_add_history << flush << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        memoryFile << final_add_history << endl;
                    }

                }
            }

            else if (choice == 4)
            {
                double a;
                double b;
                cout << "What is the number you want to divide? ";
                cin >> a;
                if (cin.fail()) 
                {
                    cerr << "Error: Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                cout << " \n" << endl;
                string add_history = to_string(a);

                add_history = add_history + " / ";
                cout << "\033[1A" << "\r" << add_history << flush;
                cin >> b;
                double c = cal->divide(a, b);

                
                string final_div_history = to_string(a) + " / " + to_string(b) + " = " + to_string(c);
                cout << "\033[1A" << "\r" << final_div_history << flush << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                memoryFile << final_div_history << endl;
                
                
            }

            else if (choice == 5)
            {
                double a;
                double b;
                cout << "Enter the base number: ";
                cin >> a;
                if (cin.fail()) 
                {
                    cerr << "Error: Invalid input" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                cout << " \n" << endl;
                string add_history = to_string(a);
                add_history = add_history + "^";
                cout << "\033[1A" << "\r" << add_history << flush;
                cin >> b;
                double c = cal->power(a, b);

                
                string final_exp_history = to_string(a) + "^" + to_string(b) + " = " + to_string(c);
                cout << "\033[1A" << "\r" << final_exp_history << flush << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                memoryFile << final_exp_history << endl;
            }

            else if (choice == 6)
            {
                stop = true;
            }

        }


    }

    void Greeting()
    {
        time_t currentTime = time(nullptr);
        int currentHour = localtime(&currentTime)->tm_hour;

        if (currentHour >= 3 && currentHour < 7)
        {
            cout << "Good (early) morning!" << endl;
        }

        else if (currentHour >= 7 && currentHour < 12)
        {
            cout << "Good morning!" << endl;
        }

        else if (currentHour >= 12 && currentHour < 18)
        {
            cout << "Good afternoon!" << endl;
        }

        else if (currentHour >= 18 && currentHour < 22)
        {
            cout << "Good evening!" << endl;
        }

        else
        {
            cout << "Good night!" << endl;
        }

    }


};