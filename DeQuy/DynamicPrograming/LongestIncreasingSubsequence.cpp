#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;


int main() {
    vector<int> number = {20, 5, 4, 12, 25, 40, 35, 50};
    vector<int> L(number.size(), 1);
    map<int, int> ghiNho;
    int max = 1;
    for (size_t i = 1; i < number.size(); i++)
    {
        int tmp = L[i];
        for (size_t j = 0; j <  i; j++)
        {
            if (number[i] > number[j] && L[i] + L[j] > tmp)
            {
                tmp = L[i];
                tmp += L[j];
                if (tmp > max)
                {
                    max = tmp;
                }
            }
        }
        L[i] = tmp;
    }
    cout << max;
}