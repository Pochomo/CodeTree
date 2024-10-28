#include <iostream>
using namespace std;


int square(int num1, int num2){
    int sum = 1;
    for(int i = 0; i < num2; i++){
        sum *= num1;    
    }
    return sum;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << square(num1, num2);
    return 0;
}