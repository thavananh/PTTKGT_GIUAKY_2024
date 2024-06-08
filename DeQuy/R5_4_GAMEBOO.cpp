/*
Mã:
R5.4:GAMEBOO
Tên:
Trò chơi Boo

Sinh viên Sư Phạm đang chuẩn bị chơi trò “Boo”. Mọi người đứng trên một hàng dài, trong đó mỗi người trong hàng sẽ nói to một chữ cái nhanh nhất có thể. Ai nói sai đầu tiên thì sẽ bị xử thua.

Dãy các kí tự “Boo” có thể kéo dài liên tục và không giới hạn. Chúng sẽ bắt đầu như sau:
b o o b o o o b o o b o o o o b o o b o o o b o o b o o o o

Dãy kí tự trên được diễn tả như sau:
Gọi S(0) là dãy ba kí tự “b o o”.
Sau đó dãy kí tự S(k) sẽ bằng dãy S(k-1) và thêm vào “b o … o” với k+2 chữ o, và sau đó cộng thêm một lần nữa dãy S(k-1).
Ví dụ:
S(0) = "b o o"
S(1) = "b o o b o o o b o o"
S(2) = "b o o b o o o b o o b o o o o b o o b o o o b o o"
Với cách này sẽ tạo được dãy kí tự rất dài, và dãy này sẽ dùng cho game "Boo".

Tèo là 1 trong số các sinh viên tham gia trò chơi "Boo". Tèo rất thông minh nên sẽ tính trước được kí tự thứ N của dãy này là chữ “b” hay chữ “o”. Tèo đố bạn đáp số là gì?

Input:
Dòng 1: số nguyên dương T - số lượng test (T <= 10)
T dòng tiếp theo, mỗi dòng gồm một số nguyên N (1 <= N <= 10^9).
Output:
T dòng, mỗi dòng chứa duy nhất kí tự “b” hoặc “o” (đáp số của từng câu hỏi mà Tèo đưa ra)

Ví dụ:
Input
2
11
24
Output:
b
o
Giải thích: Ký tự thứ 11 trong dãy trên là b và ký tự thứ 24 trong dãy là o
*/


#include <iostream>
using namespace  std;

string taoChuoiBoo() {
    string rs = "boo";
    for (int i = 1; i < 10; i++) {
        string tmp = rs;
        rs = rs + "b";
        for (int j = 1; j <= i+2; j++) {
            rs = rs + "o";
        }
        rs = rs + tmp;
    }
    return rs;
}

int main() {
    int t; cin >> t;
    int a[100];
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }
    string chuoiBoo = taoChuoiBoo();
    for (int i = 0; i < t; i++) {
        cout << chuoiBoo[a[i]-1] << endl;
    }
}

/*
Được 6 test, vì bài giới hạn thời gian nên chịu vô thi thì ok :))
 */

/*
_____ _            _____    _ _                   _     _
|_   _| |__   ___  |  ___|__| | | _____      _____| |__ (_)_ __
  | | | '_ \ / _ \ | |_ / _ \ | |/ _ \ \ /\ / / __| '_ \| | '_ \
  | | | | | |  __/ |  _|  __/ | | (_) \ V  V /\__ \ | | | | |_) |
  |_| |_| |_|\___| |_|  \___|_|_|\___/ \_/\_/ |___/_| |_|_| .__/
                                                          |_|
*/
