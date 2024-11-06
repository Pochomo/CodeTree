#include <iostream>
using namespace std;

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b;
}

int main() {
    int n, m;
    cin >> n >> m;
    swap(n, m);
    return 0;
}