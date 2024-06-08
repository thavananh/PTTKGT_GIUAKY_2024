/*
Mã:
[LTNC]Final01
Tên:
Đệ quy
Hãy sử dụng kĩ thuật đệ quy để tính giá trị sin và cos (độ chính xác 0.0001) của một giá trị số thực x (radian) theo công thức sau:

sin(x) = x – x^3/3! + x^5/5! + … + (-1)^n(x^2n+1/(2n+1)!)

cos(x) = 1 – x^2/2! + x^4/4! + … + (-1)^n(x^2n/(2n)!)

Lưu ý:

chương trình phải sử dụng kĩ thuật đệ quy
không dùng các hàm toán học sin, cos trong thư viện để tính toán


Input: Giá trị số thực x

Output: dòng đầu tiên là giá trị sin(x), làm tròn 2 số lẻ; dòng thứ hai là giá trị cos(x), làm tròn 2 số lẻ



Vd:

Input:

1

Ouput

0.84

0.54



Hướng dẫn cách làm tròn:

Ví dụ: làm tròn n tới 3 chữ số thập phân ==> dùng hàm roundf(n * 1000) / 1000


 */

#include <iostream>
#include <cmath>
using namespace  std;
const double eps = 0.0001;

long giaiThua(long n) {
    if (n==0) {
        return 1;
    }
    return n * giaiThua(n-1);
}

double deQuySin(double x, long n=0) {
    double val = pow((-1), n) * pow(x, 2 *n + 1) / giaiThua(2 * n + 1);
    if (fabs(val) <= eps) {
        return 0;
    }
    else {
        return val + deQuySin(x, n+1);
    }
}

double deQuyCos(double x, long n=0) {
    double val = pow((-1), n) * pow(x, 2 *n) / giaiThua(2 * n);
    if (fabs(val) <= eps) {
        return 0;
    }
    else {
        return val + deQuyCos(x, n+1);
    }
}

int main() {
    double x; cin >> x;
    double sin = deQuySin(x);
    double cos = deQuyCos(x);
    cout << roundf(sin * 100)/100 << endl;
    cout << roundf(cos * 100)/100;
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

