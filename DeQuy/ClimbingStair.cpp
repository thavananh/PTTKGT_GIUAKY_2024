#include <iostream>
#include <map>
using namespace std;

int soCachLeoThang(int n, map<int, int> &ghiNho) {
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int soCach = 0;
    for (size_t i = 1; i <= 2; i++)
    {
        int soBacThangConLai = n - i;
        int phanHoi = soCachLeoThang(soBacThangConLai, ghiNho);
        soCach += phanHoi;
        ghiNho[n] = soCach;
    }
    ghiNho[n] = soCach;
    return soCach;
}

int main() {
    int n; cin >> n;
    map<int, int> ghiNho;
    cout << soCachLeoThang(n, ghiNho);
}