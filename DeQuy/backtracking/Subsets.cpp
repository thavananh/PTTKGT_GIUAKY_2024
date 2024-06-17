//Còn có thể gọi là tổ hợp (combination)
//Input = {1,2,3}
//Output = {{}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void subsets_rec(vector<int>& nums, int idx, vector<vector<int>>& result) {
    if (idx == nums.size()-1)
    {
        result.push_back({});
        result.push_back({nums[idx]});
    }
    else {
        subsets_rec(nums, idx + 1, result);
        int n = result.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> r = result[i];
            r.push_back(nums[idx]);
            result.push_back(r);
        }
        
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) 
    {
        return {{}};
    }
    vector<vector<int>> result;
    subsets_rec(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums  = {1, 2, 3};
    vector<vector<int>> rs = subsets(nums);
    
}