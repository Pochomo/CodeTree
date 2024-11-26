#include <iostream>
using namespace std;

int digits[100];

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while(n > 0){
        digits[cnt] = (n % 10);
        n /= 10;
        cnt++;
    }
    int sum = 0;
    for(int i = cnt-1; i >= 0; i--){
        sum = sum * 2 + digits[i];
    }
    cout << sum;
    return 0;
}


//int 변환 후 
// #include <iostream>

// using namespace std;

// int main() {
//     // 변수 선언 및 입력
//     string binary;
//     cin >> binary;
    
//     // 십진수로 변환합니다.
//     int num = 0;
//     for(int i = 0; i < (int) binary.size(); i++)
//         num = num * 2 + (binary[i] - '0'); //'0' 하는 이유는 char를 숫자로 변경할때
//      '0'을 뺴줘야함
    
//     // 출력
//     cout << num;
//     return 0;
// }