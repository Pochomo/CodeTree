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