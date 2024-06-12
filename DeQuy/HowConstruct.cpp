#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

string howConstruct(string input, vector<string>&wordBank, map<string, string>&ghiNho) {
    if (ghiNho.count(input) != 0)
    {
        return ghiNho[input];
    }
    
    if (input == "")
    {
        return "";
    }

    string ketHop = "null";
    
    for (size_t i = 0; i < wordBank.size(); i++)
    {
        if (input.find(wordBank[i]) != string::npos && input.find(wordBank[i]) == 0)
        {
            string tmp = input.substr(wordBank[i].length());
            string phanHoi = howConstruct(tmp, wordBank, ghiNho);
            if (phanHoi != "null")
            {
                ketHop = wordBank[i] + " " + phanHoi;
                ghiNho[input] = ketHop;
                return ketHop;
            }
        }
    }
    ghiNho[input] = ketHop;
    return ketHop;
}

int main() {
    string input; cin >> input;
    string x;
    vector<string>wordBank;
    int n; cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        wordBank.push_back(x);
    }
    
    map<string, string> ghiNho;
    cout << howConstruct(input, wordBank, ghiNho);
    
}
