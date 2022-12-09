#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("test.cpp");
    regex r{"(?:\\/\\/\\s*(.+)$)"};
    //|(?:\\/\\*\\s*(.+)\\s*\\*\\/$)"};
    string x;
    while (!in.eof())
    {
        string str;
        getline(in, str);
        x += str + "\n";
        const sregex_token_iterator end;
        for (sregex_token_iterator iter{cbegin(str), cend(str), r}; iter != end; ++iter)
        {
            cout << "found comment" << iter->str() << endl;
        }
    }

    return 0;
}