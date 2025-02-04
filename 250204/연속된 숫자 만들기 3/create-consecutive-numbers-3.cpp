#include <iostream>
#include <algorithm>

#define MAX_N 3

using namespace std;

int n = 3;
int a[MAX_N];

int main() {
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int diff1 = a[1] - a[0];
    int diff2 = a[2] - a[1];

    int ans = max(diff1, diff2) - 1;
    
    cout << ans;
    return 0;
}
