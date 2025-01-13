#include <iostream>
#include <climits>

using namespace std;

int n;
int x[100], y[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = INT_MAX;
    //x1, x2 ,y1, y2 구해서 넓이,
    for(int i = 0; i < n; i++) { //빼고 계산할 지점
        int x1 = INT_MAX;
        int x2 = INT_MIN;
        int y1 = INT_MAX;
        int y2 = INT_MIN;
        int area = 0;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            x1 = min(x[j], x1);
            x2 = max(x[j], x2);
            y1 = min(y[j], y1);
            y2 = max(y[j], y2);
        }
        area = ((x2 - x1) * (y2 - y1));
        ans = min(ans, area);
    }

    cout << ans;

    return 0;
}