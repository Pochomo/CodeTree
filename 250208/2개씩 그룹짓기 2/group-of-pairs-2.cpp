#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[200000];

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 2*n);
    //2개의 원소가 하나의 그룹을 이루도록 해 n 개 의 그룹, 2개의 수의 차이 중 최솟값이 최대가하도록
    //2 5 7 9 10 15
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, abs(arr[i] - arr[i + n - 1]));
    }

    cout << ans;

    return 0;
}