#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

bool canConstruct(string input, vector<string>&wordBank, map<string, bool>&ghiNho) {
    if (ghiNho.count(input) != 0)
    {
        return ghiNho[input];
    }
    if (input == "")
    {
        return true;
    }
    for (size_t i = 0; i < wordBank.size(); i++)
    {
        if (input.find(wordBank[i]) != std::string::npos && input.find(wordBank[i]) == 0)
        {
            string tmp = input.substr(wordBank[i].length());
            if (canConstruct(tmp, wordBank, ghiNho))
            {
                ghiNho[input] = true;
                return true;
            }
        }
    }
    ghiNho[input] = false;
    return false;
}

int main() {
    string input = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string>wordBank;
    wordBank.push_back("e");
    wordBank.push_back("ee");
    wordBank.push_back("eee");
    wordBank.push_back("eeee");
    wordBank.push_back("eeeee");
    wordBank.push_back("eeeeee");
    map<string, bool> ghiNho;
    if (canConstruct(input, wordBank, ghiNho))
    {
        cout << "Tao duoc chuoi voi cac tu trong wordbank";
    }
    else {
        cout << "Khong tao duoc";
    }
}