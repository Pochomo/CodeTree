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
    int temp;
    for(int i = 0; i < 3; i++){
        if(a > b){
            temp = b;
        }
        if(b > c){
            temp = c;
        }
        if(c > a){
            temp = a;
        }
    }
    return temp;
}