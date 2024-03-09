#include <stdexcept>
#include <iostream>
#include "calculator.h"
#include <ctime>
using namespace std;

class Manager
{

public:
    void Play()
    {
        
        bool stop = false;
        Calculator *cal = new Calculator();

        Greeting();
        cout << "Welcome to the Calculator app!" << endl;

        while (!stop)
        {
            
            cout << "\n1 - add numbers up\n2 - substract\n3 - multiply\n4 - division\n5 - exponentation\n6 - exit app" << endl;
            cout << "What do you choose? " << endl;

            int choice;
            cin >> choice;

            if (choice == 1)
            {
                bool stop_add = false;
                int a;
                int b;
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
                    }

                }
                
            }

            else if (choice == 2)
            {
                bool stop_s = false;
                int a;
                int b;
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
                    }

                }
                
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