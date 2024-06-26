#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;

long deQuy(vector<int>& L, vector<int>& P, int input, map<int, int>& ghiNho) {
    if (ghiNho.count(input) != 0)
    {
        return ghiNho[input];
    }
    
    if (input == 0)
    {
        return 0;
    }
    if (input < 0)
    {
        return -1;
    }
    int max = -1;
    for (size_t i = 0; i < L.size(); i++)
    {
        int newInput = input - L[i];
        int phanHoi = deQuy(L, P, newInput, ghiNho);
        int sum = 0;
        if (phanHoi != -1)
        {
            sum = P[i] + phanHoi;
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    ghiNho[input] = max;
    return max;
}

int main() {
    vector<int> L = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> P = {1, 3, 7, 8, 12, 15, 16, 17};
    int input = 8;
    map<int, int> ghiNho;
    cout << deQuy(L, P, input, ghiNho);
}