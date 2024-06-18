#include <iostream>
#include <vector>
#include <map>
using namespace std;

string balo(int arr[], int n, int maxW, map<int, int>&ghiNho, vector<bool>&daChon, int soDoDangCo) {
    if (maxW == 0)
    {
        return "";
    }
    if (maxW < 0)
    {
        return "null";
    }
    string cacMonDo = "null";
    for (size_t i = 0; i < n; i++)
    {
        if (!daChon[i])
        {
            int newMaxW = maxW - arr[i];
            daChon[i] = true;
            string phanHoi = balo(arr, n, newMaxW, ghiNho, daChon, soDoDangCo + 1);
            if (phanHoi != "null")
            {
                cacMonDo =  phanHoi + to_string(i) + " " ;    
            }
            daChon[i] = false;
        }
    }
    return cacMonDo;
}

int main() {
    int n, w; cin >> n >> w;
    int arr[1000];
    vector<bool>daChon(n + 1, false);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int>ghiNho;
    cout << balo(arr, n, w, ghiNho, daChon, 0);
}