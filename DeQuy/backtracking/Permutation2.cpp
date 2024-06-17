#include <iostream>
#include <vector>
#include <map>
using namespace std;

void perMuteUnique(map<int, int> mapCounter, string rs, int limitLength) {
    if (rs.length() == limitLength)
    {
        cout << rs << endl;
        return;
    }
    for (auto pair : mapCounter) {
        if (pair.second != 0)
        {
            map<int, int> newMap = mapCounter;
            newMap[pair.first] = newMap[pair.first] - 1;
            perMuteUnique(newMap, rs + to_string(pair.first), limitLength);
        }
    }
}

int main() {
    vector<int>numb = {1, 1, 2};
    map<int, int> mapCounter;
    for (size_t i = 0; i < numb.size(); i++)
    {
        if (mapCounter.count(numb[i]) != 0)
        {
            mapCounter[numb[i]] = mapCounter[numb[i]] + 1;
        }
        else
        {
            mapCounter[numb[i]] = 1;
        }
    }
    perMuteUnique(mapCounter, "", numb.size());
}