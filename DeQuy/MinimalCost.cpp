#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minimumCost(vector<int>& days, vector<int>& costs) {
    // Using a map to remember the minimum cost for each day
    unordered_map<int, int> dp;
    // Base case: no days means no cost
    dp[0] = 0;

    int lastDay = days.back(); // last day of travel
    int currentDay = 1;        // current day in the year
    int index = 0;             // index for days array

    for (; currentDay <= lastDay; ++currentDay) {
        // If currentDay is not a travel day, it inherits the cost from the previous day
        if (currentDay != days[index]) {
            dp[currentDay] = dp[currentDay - 1];
        } else {
            // Calculate the cost for 1-day, 7-day, and 30-day passes
            int cost1 = dp[currentDay - 1] + costs[0];
            int cost7 = dp[max(0, currentDay - 7)] + costs[1];
            int cost30 = dp[max(0, currentDay - 30)] + costs[2];
            dp[currentDay] = min({cost1, cost7, cost30});

            // Move to the next travel day
            index++;
        }
    }

    return dp[lastDay];
}

int main() {
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout << "Minimum cost: " << minimumCost(days, costs) << endl;
    return 0;
}
