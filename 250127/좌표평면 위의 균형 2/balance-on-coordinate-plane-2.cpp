#include <iostream>
#include <climits>
using namespace std;

int n;
int x[100], y[100];

int main() {
    cin >> n;

    //x축과 y축에 평행한 직선을 정확히 1개씩 그어 4분할
    //4군데 중 "가장 많은 점의 수가 최소"

    //x y는 항상 짝수
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int cnt1, cnt2, cnt3, cnt4; //각각 1 2 3 4 분면
    int ans = INT_MAX;
    for (int x1 = 0; x1 <= 100; x1 += 2) {
        for (int y1 = 0; y1 <= 100; y1 += 2) {
            //각각 1 2 3 4 분면
            int cnt1 = 0;
            int cnt2 = 0;
            int cnt3 = 0;
            int cnt4 = 0;
            int maxcnt = 0;
            for (int i = 0; i < n; i++) {
                if(x[i] > x1 && y[i] > y1){
                    cnt1++;
                }
                else if(x[i] < x1 && y[i] > y1){
                    cnt2++;
                }
                else if(x[i] < x1 && y[i] < y1){
                    cnt3++;
                }
                else if(x[i] > x1 && y[i] < y1){
                    cnt4++;
                }
            }
            maxcnt =  max(max(cnt1, cnt2), max(cnt3, cnt4));
            ans = min(ans, maxcnt);
        }
    }

    cout << ans;


    return 0;
}