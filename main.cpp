/*
#include <iostream>
#include <map>
using namespace std;

long fibo(long n, map<long, long>& ghiNho) {
    if (ghiNho.count(n) != 0) {
        return ghiNho[n];
    }
    if (n <= 2) {
        return 1;
    }
    ghiNho[n] = fibo(n-1, ghiNho) + fibo(n-2, ghiNho);
    return ghiNho[n];
}

int main() {
    int n;
    cin >> n;
    map<long, long> ghiNho;
    cout << fibo(n, ghiNho);
}

Tìm đường đi không trùng

#include <iostream>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

long gridTravel(long n, long m, map<string, long>& ghiNho) {
    string key1 = to_string(n) + "," + to_string(m);
    string key2 = to_string(m) + "," + to_string(n);
    if (ghiNho.count(key1) != 0 || ghiNho.count(key2) != 0) {
    return ghiNho[key1];
    }
    // if (ghiNho.count(key1) != 0) {
    //     return ghiNho[key1];
    // }
    if (n == 1 && m == 1) {
        return 1;
    }
    if (n == 0 || m == 0) {
        return 0;
    }
    ghiNho[key1] = gridTravel(n - 1, m, ghiNho) + gridTravel(n, m - 1, ghiNho);
    ghiNho[key2] = ghiNho[key1];
    return ghiNho[key1];
}

int main() {
    // n là số hàng
    // m là số cột
    long n, m;
    cin >> n >> m;
    map<string, long> ghiNho;

    // Lấy thời gian trước khi chạy hàm
    auto start = high_resolution_clock::now();

    cout << gridTravel(n, m, ghiNho) << endl;

    // Lấy thời gian sau khi chạy hàm
    auto end = high_resolution_clock::now();

    // Tính thời gian chạy
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Thời gian chạy: " << duration.count()*1.0 / 1000000 << " s" << endl;
}

#include <iostream>
#include <map>
using namespace  std;

bool canSum(int target, int arr[], int n, map<long, bool>&ghiNho) {
    if (ghiNho.count(target) != 0) {
        return ghiNho[target];
    }
    if (target == 0) {
        return true;
    }
    if (target < 0) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        int conLai = target - arr[i];
        if (canSum(conLai, arr, n, ghiNho)) {
            ghiNho[target] = true;
            return true;
        }
    }
    ghiNho[target] = false;
    return false;
}

int main() {
    int arr[] = {9, 9};
    map<long, bool> ghiNho;
    if(canSum(300, arr, 2, ghiNho)) {
        cout << "Co the";
    }
    else {
        cout << "Khong the";
    }
}*/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

string howConstruct(string input, vector<string>&wordBank, map<string, string>&ghiNho) {
    if (ghiNho.count(input) != 0)
    {
        return ghiNho[input];
    }
    
    if (input == "")
    {
        return "";
    }

    string ketHop = "null";
    
    for (size_t i = 0; i < wordBank.size(); i++)
    {
        if (input.find(wordBank[i]) != string::npos && input.find(wordBank[i]) == 0)
        {
            string tmp = input.substr(wordBank[i].length());
            string phanHoi = howConstruct(tmp, wordBank, ghiNho);
            if (phanHoi != "null")
            {
                ketHop = wordBank[i] + " " + phanHoi;
                ghiNho[input] = ketHop;
                return ketHop;
            }
        }
    }
    ghiNho[input] = ketHop;
    return ketHop;
}

int main() {
    string input; cin >> input;
    string x;
    vector<string>wordBank;
    int n; cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        wordBank.push_back(x);
    }
    
    map<string, string> ghiNho;
    cout << howConstruct(input, wordBank, ghiNho);
    
}

// #include <iostream>
// #include <map>
// using namespace std;
//
// int main() {
//     map<string, string> mp;
//     mp["quachuoi"] = "1";
//     cout << mp.count("quachuoi");
//     cout << mp.count("1");
// }