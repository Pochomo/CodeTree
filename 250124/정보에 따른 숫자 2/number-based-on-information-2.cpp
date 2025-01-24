#include <iostream>
#include <climits>

using namespace std;

int T, a, b;
char c[100];
int x[100];

int main() {
    cin >> T >> a >> b;

    //1차 수직선 상에 T개의 알파벳
    //알파벳은 S N으로만
    //특정 위치 x = k로 부터 가까운 S까지의 거리 d1이 가까운 N까지의 거리 d2 보다
    // 같거나 작은경우 특별한 위치
    
    //x = a 부터 x = b까지의 위치 중 특별한 위치의 수 구해라

    int cnt = 0;

    for (int i = 0; i < T; i++) {
        cin >> c[i] >> x[i];
    }
    //2는 S기준 d1 = 1 N기준 d2 = 3이라 거리가 작거나 같으므로 맞음
    for (int j = a; j <= b; j++) {
        int d1 = INT_MAX;
        int d2 = INT_MAX;
        for (int i = 0; i < T; i++) {
            if(c[i] == 'S') {
                d1 = min(d1, abs(x[i] - j));
            }
            else if(c[i] == 'N') {
                d2 = min(d2, abs(x[i] - j));
            }
        }
        if(d1 <= d2){
            //cout << j << " ";
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}