#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    // regex r{"\\d{4}\\/(?:0?2\\/(?:0?[1-9]|1[0-9]|2[0-8])|(?:0?[469]|11)\\/(?:0?[1-9]|[1-2][0-9]|30)|(?:0?[13578]|1[02])\\/(?:0?[1-9]|[1-2][0-9]|3[0-1]))"};
    regex r{"(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])"};
    while (true)
    {
        cout << "Enter a date (year/month/day) (q=quit): ";
        string str;
        if (!getline(cin, str) || str == "q")
        {
            break;
        }
        if (smatch m; regex_match(str, m, r))
        {
            int year{stoi(m[1])};
            int month{stoi(m[2])};
            int day{stoi(m[3])};
            bool leap = false;
            if(year % 4 == 0)
            {
                if(year % 100 == 0)
                    if(year % 400 == 0)
                        leap = true;
                    else
                        leap = false;
                else
                    leap = true;
            }
            else 
                leap = false;
            if (month == 2 && day > 28)
            {
                if((leap && day > 29) || !leap)
                    cout << " Invalid date!" << endl;
                else if(leap)
                    cout << "Valid date: Year=" << year << ", month=" << month << ", day=" << day << endl;
            }
            else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
                cout << " Invalid date!" << endl;
            else
                cout << "Valid date: Year=" << year << ", month=" << month << ", day=" << day << endl;
        }
        else
        {
            cout << " Invalid date!" << endl;
        }
    }
    return 0;
}