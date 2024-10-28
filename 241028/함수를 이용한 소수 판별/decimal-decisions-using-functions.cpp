#include <iostream>
using namespace std;

int sosu(int x){
    for(int i = 2; i < x; i++){
        if((x % i) == 0)
        {
            return 0;
        }
    }
    return x;
}

int main() {
    int num1, num2;
    int sum = 0;
    cin >> num1 >> num2;
    for(int i = num1; i <= num2; i++){
        sum += sosu(i);
    }
    cout << sum;
    return 0;
}