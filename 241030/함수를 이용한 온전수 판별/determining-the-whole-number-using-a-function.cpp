#include <iostream>
using namespace std;

bool count_num(num1){
    if(num1 % 2 == 0){
        return false;
    }
    if(num1 % 10 = 5){
        return false;
    }
    if(num1 % 3 == 0 && num1 % != 0){
        return false;
    }
    return true;
}

int main() {
    int num1, num2;
    int sum = 0;
    for(int i = num1; i <= num2; i++){
        if(count_num(i)){
            sum++;
        }
    }
    cout << sum;
    return 0;
}