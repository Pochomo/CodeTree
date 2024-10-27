#include <iostream>
using namespace std;

bool AllDifferent(int n) {
    return (n / 10) == 3 || (n % 10) == 3 || (n / 10) == 6 || (n % 10) == 6 || (n / 10) == 9 || (n % 10) == 9;
}

bool IsMagicNumber(int n) {
    return n % 3 == 0 || AllDifferent(n);
}

int main() {
    int cnt = 0;
    int num1, num2;
    cin >> num1 >> num2;
    for(int i = num2; i >= num1; i--){
        if(IsMagicNumber(i)){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}