#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;
//A는 체크포인트 하나 건너 뛴다. 근데 1번이랑 N번은 건너뛰면 안됨
int n;
int x[100];
int y[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    //모든 경우의 수 다 더하고 min으로 distance 출력
    int ans = INT_MAX;
    int distance = 0;
    for (int i = 1; i < n-1; i++){
        int cnt = 0;
        for(int j = 0; j < n-1; j++){
            if(j == (i-1)){
                cnt = 1;
            }
            if(j != i){
                distance += (abs(x[j-cnt] - x[j+1+cnt]) + abs(y[j-cnt] - y[j+1+cnt]));
                cnt = 0;
            }
        }
        ans = min(distance, ans);
        distance = 0;
    }
    
    cout << ans;

    return 0;
}