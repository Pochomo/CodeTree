#include <iostream>
using namespace std;

int small_value(int a, int b, int c);

int main() {
    int num1, num2, num3, value;
    cin >> num1 >> num2 >> num3;
    value = small_value(num1, num2, num3);
    cout << value;
    return 0;
}

int small_value(int a, int b, int c){
    int temp = a;
    if(temp > b){
        temp = b;
    }
    if(temp > c){
        temp = c;
    }
    
    return temp;
}