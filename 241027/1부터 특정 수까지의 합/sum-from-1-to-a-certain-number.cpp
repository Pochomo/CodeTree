#include <iostream>
using namespace std;

int sunprint(int num);
int main() {
    int num1;
    cin >> num1;
    int sumofdivide = sunprint(num1);
    cout << sumofdivide;
    return 0;
}

int sunprint(int num){
    int sum = 0;
    int divide;
    for(int i = 1; i <= num; i++){
        sum = sum + i;
    }
    divide = sum / 10;
    return divide;
}