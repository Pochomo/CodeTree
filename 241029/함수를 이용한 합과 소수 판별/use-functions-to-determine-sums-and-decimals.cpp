#include <iostream>
using namespace std;

bool sosu(int x){
    int sum = 0;
    if (x == 1){
        return false;
    }
    for(int i = 2; i < x; i++){
        if((x % i) == 0)
        {
            return false;
        }
    }
    sum = (x % 10) + (x / 10 % 10);
    if(sum % 2 == 0){
        return true;
    }
    else{
    return false;
    }
}

int main() {
    int num1, num2;
    int sum = 0;
    cin >> num1 >> num2;
    for(int i = num1; i <= num2; i++){
        if(sosu(i)){
           sum++; 
        };
    }
    cout << sum;
    return 0;
}