#include <iostream>
#include <climits>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    //하나의 선분을 제거해서 나머지 n-1개의 선분을 포함할 수 있는 가장 짧은 선분의 길이를 최소로 하는 프로그램

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int max_x = INT_MIN;
        int min_x = INT_MAX;
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            max_x = max(max_x, x2[j]);
            min_x = min(min_x, x1[j]);
        }
        ans = min(ans, max_x - min_x);
    }

    cout << ans;

    return 0;
}