/*
Mã:
LASTNUM
Tên:
Số cuối cùng

* Một LASTNUM được xác định là tổng các chữ số của số đó, sau đó lại tiếp tục tính tổng các chữ số của số mới tạo ra cho đến khi chỉ còn 1 chữ số duy nhất.

Nhờ bạn hãy giúp tìm ra số cuối cùng đó nhé!

Yêu cầu: Cho số N, bạn hãy tìm LASTNUM của số đó.
Dữ liệu nhập:

  Gồm 1 số nguyên N duy nhất (1 ≤ N ≤ 101000000).

Dữ liệu xuất:

  Gồm 1 số nguyên duy nhất là LASTNUM tìm được.

Ví dụ
input
79
output
7
Các số được tạo ra lần lượt là 79 ➔ 16 ➔  7
 */


#include <iostream>
using namespace std;

long deQuy(long n) {
    if (n < 10) {
        return n;
    }
    long rs = 0;
    while (n != 0) {
        rs = rs + n%10;
        n = n/10;
    }
    return deQuy(rs);
}

int main() {
    long n; cin >> n;
    cout << deQuy(n) << endl;
    return 0;
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
