#include <iostream>

using namespace std;

void two_integer(int &a, int &b){
    if(a > b){
        a *= 2;
        b += 10;
    }
    else if(a < b) {
        b *= 2;
        a += 10;
    }   
}

int main() {
    int a, b;
    cin >> a >> b;

    two_integer(a, b);

    cout << a << " " << b;

    return 0;
}