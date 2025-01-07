#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = INT_MIN;

    for(int i = 0; i <= n - k; i++) {
        int max_val = 0;
        for(int j = i; j < i + k; j++)
            max_val += arr[j];
    
        ans = max(ans, max_val);
    }

    cout << ans;

    return 0;
}