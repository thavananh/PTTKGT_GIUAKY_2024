#include <iostream>
#include <vector>
#include <map>
using namespace std;

int soCach(vector<int>coins, map<int, int>& ghiNho, int amount, vector<bool> lock) {
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
        if (!lock[i])
        {
            int newAmount = amount - coins[i];
            int phanHoi = soCach(coins, ghiNho, newAmount, lock);
            sum += phanHoi;
            lock[i] = true;
        }       
    }
    return sum;
}

int main() {
    vector<int>coins = {10};
    int amount = 10;
    map<int, int> ghiNho;
    vector<bool>lock(coins.size() + 1, false);
    cout << soCach(coins,ghiNho, amount, lock);
}