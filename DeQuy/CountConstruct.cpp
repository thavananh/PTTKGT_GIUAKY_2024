#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int countConstruct(string input, vector<string>&wordBank, map<string, int>&ghiNho) {
    if (ghiNho.count(input) != 0)
    {
        return ghiNho[input];
    }
    if (input == "")
    {
        return 1;
    }
    int sum = 0;
    for (size_t i = 0; i < wordBank.size(); i++)
    {
        if (input.find(wordBank[i]) != string::npos && input.find(wordBank[i]) == 0)
        {
            string tmp = input.substr(wordBank[i].length());
            int phanHoi = countConstruct(tmp, wordBank, ghiNho);
            sum += phanHoi;     
            ghiNho[input] = sum;
        }
    }
    ghiNho[input] = sum;
    return sum;
}

int main() {
    // string input = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    string input; cin >> input;
    string x;
    vector<string>wordBank;
    int n; cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        wordBank.push_back(x);
    }
    
    map<string, int> ghiNho;
    cout << countConstruct(input, wordBank, ghiNho);
    
}