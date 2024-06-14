#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int minimumCost(vector<int>days, vector<int>cost, map<int, int>& ghiNho, int dayIndex) {
    if (ghiNho.count(days[dayIndex]) != 0)
    {
        return ghiNho[days[dayIndex]];
    }
    
    if (dayIndex >= days.size())
    {
        return 0;
    }
    int oneDayPassPrice = minimumCost(days, cost,  ghiNho,dayIndex + 1) + cost[0];
    int i;
    for ( i = dayIndex; i < days.size(); i++)
    {
        if (days[i] >= days[dayIndex] + 7)
        {
            break;
        }
    }
    int sevenDayPass = minimumCost(days, cost, ghiNho, i) + cost[1];

    for ( i = dayIndex; i < days.size(); i++)
    {
        if (days[i] >= days[dayIndex] + 30)
        {
            break;
        }
    }
    int thirtyDaysPass = minimumCost(days, cost, ghiNho, i) + cost[2];
    int minPrice = min(oneDayPassPrice, min(sevenDayPass, thirtyDaysPass));
    ghiNho[days[dayIndex]] = minPrice;
    return minPrice;
}

int main() {
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 15};
    map<int, int> ghiNho;
    cout << minimumCost(days, cost, ghiNho, 0);
}