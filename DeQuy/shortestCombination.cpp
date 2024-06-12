#include <iostream>
#include <map>
#include <cstring>
using namespace  std;

string bestSum(int target, int arr[], int n, map<long, string>& ghiNho) {
    if (ghiNho.count(target) != 0)
    {
        return ghiNho[target];
    }
    
    if (target == 0)
    {
        return "";
    }
    if (target < 0)
    {
        return "null";
    }
    string shortest = "null";
    for (size_t i = 0; i < n; i++)
    {
        int hieu = target - arr[i];
        string phanHoi = bestSum(hieu, arr, n, ghiNho);
        if (phanHoi != "null")
        {
            string attemp = to_string(arr[i]) + " " + phanHoi;
            if (shortest == "null" || attemp.length() < shortest.length())
            {
                shortest = attemp;
            }
            
        }
    }
    ghiNho[target] = shortest;
    return shortest;
}

int main() {
    int arr[] = {2, 3, 5};
    map<long, string> ghiNho;
    cout << bestSum(8, arr, 3, ghiNho);
}