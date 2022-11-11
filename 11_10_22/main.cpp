#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_set>
#include <ctime>
#include <string>
#include <cmath>

int hashFunc(int key);
void setup();

int main()
{
    //setup();
    
    int ht[30000];
    int collisions = 0;
    int count = 0;

    for(int i = 0; i < 30000; i++)
    {
        ht[i] = -1;
    }

    std::ifstream nums("exp.txt");
    while(!nums.eof() && count < 10000)
    {
        int x;
        nums >> x;
        if(ht[hashFunc(x)] == -1)
        {
            std::cout << x << " inserted at " << hashFunc(x) << std::endl;
            ht[hashFunc(x)] = x;
            count++;
        }
        else if (ht[hashFunc(x)] != x)
        {
            std::cout << x << " collided with " << ht[hashFunc(x)] << std::endl;
            collisions++;
        }

    }
    std::cout << "There were " << collisions << " collisions." << std::endl;
    std::cout << "There were " << count << " items inserted." << std::endl;

    return 0;
}


int hashFunc(int key)
{
    /*
    std::string keyStr = std::to_string(key);
    int digits = keyStr.size();
    int charPerSeg = digits / 3;
    int sum = 0;
    for(int i = 0; i < keyStr.size(); i++)
    {
        sum += static_cast<int>(keyStr[i]);
    }


    return abs(sum % 2000000); */
    std::hash<int> intHash;
    return intHash(key) % 30000;
}

void setup()
{
    srand(time(0));
    std::ofstream out("exp.txt");

    std::unordered_set<int> x;
    while(x.size() < 1000000)
    {
        x.insert(rand());
    }
    for(int i : x)
    {
        out << i << std::endl;
    }
}