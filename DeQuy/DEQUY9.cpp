/*
Mã:
DAYSO
Tên:
DAYSO
Cho một dãy số được cho theo quy tắc sau:

a0 ­= 0

a1 = 1



a2i = ai

a2i+1 = ai+ai+1

với i = 1, 2, 3, …



Cho một số n, hãy viết chương trình đệ quy tìm số lớn nhất trong các số a0, a1, a2, a3, …, an

Input:

o  Nhập vào một con số nguyên n (1 ≤ n ≤ 900)

Output:

o  Xuất ra giá trị lớn nhất tìm thấy.

Ví dụ:

Input

5

output

3

 */


#include <cmath>
#include <iostream>
using namespace  std;

long deQuyTongS(long n) {
    if (n == 1) {
        return 1;
    }
    return n + deQuyTongS(n-1);
}

long deQuyS(long n) {
    if (n == 1) {
        return 1;
    }
    return  deQuyTongS(n) + deQuyS(n-1);
}

long deQuyTongP(long n) {
    if (n == 1) {
        return 1;
    }
    return n * deQuyTongP(n-1);
}

long deQuyP(long n) {
    if (n == 1) {
        return 1;
    }
    return deQuyTongP(n) + deQuyP(n-1);
}

int main() {
    int n; cin >> n;
    cout << "S(" << n << ") = " <<  deQuyS(n) << endl;
    cout << "P(" << n << ") = " <<  deQuyP(n);
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
