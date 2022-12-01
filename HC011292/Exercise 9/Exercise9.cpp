#include <map>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;

    map<string, unsigned long> phone_numbers = {
        {"Ken", 61111111},   //All the numbers are just randomly chosed and make into Macau's format 
        {"Terry", 65111111},
        {"Mark", 28111112},
        {"Bob", 28111113},
        {"Josh", 28131111},
        {"May", 28120111}
        {"Police", 999},
    };

    for (auto it = phone_numbers.begin(); it != phone_numbers.end(); ++it)
        cout << it->first << " : " << it->second << endl;

    string key{ "!@#$" };
    cout << "Input the name: ";
    cin >> key;
    auto iter = phone_numbers.find(key);
    if (iter == phone_numbers.end())
        cout <<"You don't have " << key << "'s phone number" << endl;
    else
        cout << key << "'s phone number is " << iter->second << endl;
    return 0;
}