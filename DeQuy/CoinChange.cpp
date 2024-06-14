#include <iostream>
#include <vector>
#include <map>
using namespace std;

int soCach(vector<int>coins, map<int, int>& ghiNho, int amount) {
    if (ghiNho.count(amount) != 0)
    {
        return 0;
    }
    
    if (amount == 0)
    {
        return 1;
    }
    if (amount < 0)
    {
        return 0;
    }
    int sum = 0;
    for (size_t i = 0; i < coins.size(); i++)
    {
        int newAmount = amount - coins[i];
        int phanHoi = soCach(coins, ghiNho, newAmount);
        sum += phanHoi;
    }
    ghiNho[amount] = sum;
    return sum;
}

int main() {
    vector<int>coins = {1, 2, 5};
    int amount = 5;
    map<int, int> ghiNho;
    cout << soCach(coins,ghiNho, amount);
}