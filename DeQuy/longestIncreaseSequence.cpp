#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int soCach(vector<int>number, map<int, int> ghiNho, int currIndex, int boDem) {
    if (currIndex == number.size() - 1)
    {
        return boDem;
    }
    
    int max = 0;
    for (size_t i = currIndex; i < number.size() - 1; i++)
    {
        if (number[i] < number[i+1])
        {
            int phanHoi = soCach(number, ghiNho, currIndex, boDem + 1);
            sum += phanHoi;
        }
    }
    return boDem;
}

int main() {

}