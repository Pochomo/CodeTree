#include <iostream>
using namespace std;

int digits[100];

int main() {

    int n, b;
    cin >> n >> b;
    int cnt = 0;

    while(true){
        if(n < b){
            digits[cnt++] = n % b;
            break;
        }
        digits[cnt] = n % b;
        cnt++;
        n = n / b;
    }
    for(int i = (cnt-1); i >= 0; i--){
        cout << digits[i];
    }

    return 0;
}