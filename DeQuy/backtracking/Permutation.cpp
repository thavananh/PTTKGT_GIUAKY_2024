#include <iostream>
#include <map>
#include <vector>
using namespace std;

void backtracking(vector<int> numb, vector<bool>& lock, string rs) {
    if (rs.size() == numb.size())
    {
        cout << rs << endl;
        return;
    }
    for (size_t i = 0; i < numb.size(); i++)
    {
        if (!lock[i])
        {
            lock[i] = true;
            backtracking(numb, lock, rs + to_string(numb[i]));
            lock[i] = false;
        }  
    }
}

int main() {
    vector<int> numb = {1, 1, 2};
    vector<bool> lock(numb.size(), false);
    backtracking(numb, lock, "");
}