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


long deQuy(long n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n%2 ==0) {
        return deQuy(n/2);
    }
    else {
        return deQuy(n/2) + deQuy(n/2 + 1);
    }
}


int main() {
    int n; cin >> n;
    int daySo[1000];
    daySo[0] = 0;
    daySo[1] = 1;
    int max = daySo[1];
    for (int i = 2; i <= n; i++) {
        daySo[i] = deQuy(i);
        if (daySo[i] > max) {
            max = daySo[i];
        }
    }
    cout << max;
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
