#include <iostream>
#include <string>
using namespace std;

bool IsMagicNumber(int n) {
    string x = to_string(n);
    int num1 = 0;
    int num;
    for(int i = 0; i < 2; i++){
        num = x[i] - '0';
        num1 = num1 + num;
    }
    return n % 2 == 0 && num1 % 5 == 0;
}

int main() {
    int num;
    cin >> num;
    if(IsMagicNumber(num) == true){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}