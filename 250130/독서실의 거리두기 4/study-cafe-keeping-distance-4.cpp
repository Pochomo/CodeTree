#include <iostream>
#include <string>

using namespace std;

int n;
string seat;

int MinDist() {
    int min_dist = n;
    //둘 다 1인 곳에 대해
    //모든 쌍을 조사하여, 그 중 가장 가까운 거리를 구합니다.
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(seat[i] == '1' && seat[j] == '1')
                min_dist = min(min_dist, j - i);
    
    return min_dist;
}

int main() {
    cin >> n;
    cin >> seat;

    //새로 두명을 더 받는다. 최대한 거리 두면서 자리 배치
    //두명을 집어넣었을 때 가장 가까운 두 사람의 거리 최대
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(seat[i] == '0') {
            seat[i] = '1';
            for(int j = i+1; j < n; j++) {
                if(seat[j] == '0') {
                    seat[j] = '1';
                    ans = max(ans, MinDist());
                    seat[j] = '0';
                }
            }
            seat[i] = '0';
        }
    }

    cout << ans;

    return 0;
}