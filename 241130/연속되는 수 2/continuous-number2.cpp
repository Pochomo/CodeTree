#include <iostream>
using namespace std;

int arrA[1000] = { 0 };

int resultA[1000] = { 0 };

int main() {
    int n;
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        arrA[i] = input;
    }
    int cnt = 0;
    int max = cnt;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arrA[i] != arrA[i - 1]) {
            cnt = 0;
        }
        cnt++;
        if (max < cnt) {
            max = cnt;
        }
    }

    cout << max;
    return 0;
}