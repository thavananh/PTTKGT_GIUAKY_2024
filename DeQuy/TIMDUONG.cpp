#include <iostream>
#include <vector>
#include <map>
using namespace std;

int soLanDiChuyen(vector<vector<int>> soCanh, map<int, int>& ghiNho, int curX, int target, int boDem) {
    if (curX == target)
    {
        return boDem;
    }
    int shortest = 0;
    for (size_t i = 0; i < soCanh[curX].size(); i++)
    {
        int phanHoi = soLanDiChuyen(soCanh, ghiNho, soCanh[curX][i], target, boDem+1);
        if (phanHoi != 0)
        {
            if (shortest == 0 || phanHoi < shortest)
            {
                shortest = phanHoi;
                ghiNho[curX] = shortest;
            }
        }
    }
    ghiNho[curX] = shortest;
    return shortest; 
}

int main() {
    int nV, nE, S, T; cin >> nV >> nE >> S >> T;
    vector<vector<int>> soCanh(1000);
    map<int, int> ghiNho;
    // vector<vector<bool>> daDi(nV + 1, vector<bool>(nE + 1, false));
    for (size_t i = 0; i < nE; i++)
    {
        int x, y; cin >> x >> y;
        soCanh[x].push_back(y);
    }
    cout << soLanDiChuyen(soCanh, ghiNho, S, T, 0);
}