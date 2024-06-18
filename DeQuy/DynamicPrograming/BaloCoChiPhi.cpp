#include <iostream>
#include <vector>
#include <map>
using namespace std;

long deQuy(vector<int>& giaTriToiDa, vector<int>& weight, int maxWeight, int indexMonDo, map<pair<int, int>, int>& ghiNho) {
    if (ghiNho.count({maxWeight, indexMonDo}) != 0)
    {
        return ghiNho[{maxWeight, indexMonDo}];
    }
    
    if (indexMonDo == weight.size())
    {
        return 0;
    }
    if (maxWeight == 0)
    {
        return 0;
    }
    int max = 0;
    for (size_t i = indexMonDo; i < weight.size(); i++)
    {
        int sum = 0;
        int newMaxWeight = maxWeight - weight[i];
        int phanHoi = deQuy(giaTriToiDa, weight, newMaxWeight, i + 1, ghiNho);
        sum = phanHoi + giaTriToiDa[i];
        if (sum > max)
        {
            max = sum;
        }
    }
    ghiNho[{maxWeight, indexMonDo}] = max;
    return max;
}

int main() {
    vector<int> giaTriToiDa = {6, 10, 12};
    vector<int> weight = {4, 2, 2};
    int maxWeight = 6;
    map<pair<int, int>, int> ghiNho;
    cout << deQuy(giaTriToiDa, weight, maxWeight, 0, ghiNho);
}