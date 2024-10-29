#include <iostream>
using namespace std;

int calculater(int num1, char a, int num2){
    int sum;
    if(a == '+'){
        sum = num1 + num2;
    }
    else if(a == '-'){
        sum = num1 - num2;
    }
    else if(a == '/'){
        sum = num1 / num2;
    }
    else if(a == '*'){
        sum = num1 * num2;
    }
    else{
        return 0;
    }
    return sum;
}

int main() {
    int num1, num2;
    char sign;

    cin >> num1 >> sign >> num2;
    if(calculater(num1, sign, num2) == 0){
        cout << "False";
    }
    else{
        cout << num1 << " " << sign << " " << num2 << " = " << calculater(num1, sign, num2);
    }

    return 0;
}