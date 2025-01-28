#include <iostream>
#include <climits>

using namespace std;

int n, m;
int arr[100];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    //m번의 움직임 반복
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) { //1번부터 움직임시작
        int moving = 0;
        int index = i;
        for(int j = 0; j < m; j++) { //움직임
            moving += arr[index];
            index = arr[index];
        }
        ans = max(moving, ans);
    }

    cout << ans;

    return 0;
}