/*
Mã:
DEQUY4
Tên:
Tính tổng

Tính tổng
tính tổng theo công thức sau bằng phương pháp ĐỆ QUY:

S(n) = 1 + x + x^2 + x^3 + ..... + x^n

dữ liệu nhập: số n và x

dữ liệu xuất: tổng S

input:
5 2
output
63

*/

#include <cmath>
#include <iostream>
using namespace  std;

long deQuy(long x, long n) {
    if (n == 1) {
        return x;
    }
    return pow(x,n) + deQuy(x, n-1);
}

int main() {
    long n; cin >> n;
    long x; cin >> x;
    cout << 1+ deQuy(x, n);
}

/*Đã test*/
/*
_____ _            _____    _ _                   _     _
|_   _| |__   ___  |  ___|__| | | _____      _____| |__ (_)_ __
  | | | '_ \ / _ \ | |_ / _ \ | |/ _ \ \ /\ / / __| '_ \| | '_ \
  | | | | | |  __/ |  _|  __/ | | (_) \ V  V /\__ \ | | | | |_) |
  |_| |_| |_|\___| |_|  \___|_|_|\___/ \_/\_/ |___/_| |_|_| .__/
                                                          |_|
*/
