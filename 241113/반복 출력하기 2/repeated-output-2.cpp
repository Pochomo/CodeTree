#include <iostream>
using namespace std;

void printHelloWorld(int n){
    if(n == 0){
        return;
    }
    printHelloWorld(n - 1);
    cout << "HelloWorld";
    cout << endl;
}

int main() {
    int a;
    cin >> a;
    printHelloWorld(4);
    return 0;
}