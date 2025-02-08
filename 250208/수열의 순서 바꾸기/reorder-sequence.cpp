#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int blocks[MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> blocks[i];

    int idx = n - 2;
    while(idx >= 0 && blocks[idx] < blocks[idx + 1])
        idx--;

    cout << idx + 1;
    return 0;
}
