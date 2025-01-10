#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a1, b1, c1;
int a2, b2, c2;

int getDistance(int x, int y){
    int direct = abs(x - y);
    int circul = min(x + N - y, y + N - x);
    return min(direct, circul);
}

//1부터 N까지 숫자를 이용해 총 3자리를 만들어야하는 3단 다이얼
//숫자 1과 N이 인접한 원형으로 된 자물쇠가 하나 주어짐
//모든 자리에 대해 조합과 거리가 2 이내면 열림
//N 이 10일 때 9 10 1 2 3 가능 11 -> 1, 0 -> 10, N을 초과하면 1됨

int main() {
    cin >> N;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                bool match1 = (getDistance(i, a1) <= 2) &&
                             (getDistance(j, b1) <= 2) &&
                             (getDistance(k, c1) <= 2);
                bool match2 = (getDistance(i, a2) <= 2) &&
                             (getDistance(j, b2) <= 2) &&
                             (getDistance(k, c2) <= 2);
                if(match1 || match2) cnt++;
            }
        }
    }
    
    cout << cnt;
    return 0;
}