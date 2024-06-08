/*
Mã:
DEQUY6
Tên:
Tính Tổng 3

dùng phương pháp ĐỆ QUY để tính tổng sau :

S(n) = x - x^3/3! + x^5/5! + .... + ((-1)^n)*(x^(2n+1)/(2n+1)!)

dữ liệu input: n và x

dữ liệu ra output : Tổng S (làm tròn đến 3 chữ số thập phân)

lưu ý : dùng hàm roundf(n * 1000) / 1000 để làm tròn n tới 3 chữ số thập phân

input :
5 2
output:
0.909

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
    return deQuy(x, n-1) + pow((-1), n) * pow(x, 2*n+1) / giaithua(2*n + 1);
}

int main() {
    long n; cin >> n;
    double x; cin >> x;
    cout << roundf( deQuy(x, n) * 1000) / 1000;

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
