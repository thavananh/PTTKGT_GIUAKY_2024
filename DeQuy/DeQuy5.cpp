/*
Mã:
DEQUY5
Tên:
Tính Tổng 2


Tính tổng 2
sử dụng phương pháp ĐỆ QUY tính tổng sau :

S(n) = 1 + x + x3/3! + x5/5! + .... + x2n+1/(2n+1)!

Dữ liệu input: chứa n và x (0

Dữ liệu output : Tổng S (làm tròn tới 3 chữ số thập phân)

Lưu ý : dùng hàm roundf(n * 1000) / 1000 để làm tròn n tới 3 chữ số thập phân

input :
5 2
output:
4.627
*/

#include <cmath>
#include <iostream>
using namespace  std;

long giaithua(long n) {
    if (n == 1) {
        return 1;
    }
    return n * giaithua(n-1);
}

double deQuy(double x, long n) {
    if (n == 0) {
        return x;
    }
    return deQuy(x, n-1) + pow(x, 2*n+1) / giaithua(2*n + 1);
}

int main() {
    long n; cin >> n;
    double x; cin >> x;
    cout << 1 + roundf( deQuy(x, n) * 1000) / 1000;

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
