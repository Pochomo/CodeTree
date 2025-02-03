#include <iostream>
#include <climits>

using namespace std;

int X;

int main() {
    cin >> X;

    //Xm 만큼 달리기를 진행, 1m/s로 시작하되, 1초에 한 번씩 속도를 유지할지, 증가할지 감소할지 결정
    //도착지에 도달하는 순간 속력은 무조건 '1'
    //최단 시간구하는 프로그램 도중 0이 되서는 x
    //최소로 할라면 증가 감소가 일정해야됨 6이면 2 3 증가 3 2 감소 1 2 3 2 1 1
    //11 이면 1 2 3 2 2 1
    //12 면 1 2 3 3 2 1
    //13 이면 1 2 3 2 2 2 1
    int ans = INT_MAX;
    for (int k = 1; k <= X; k++) { //최대속도
        for (int p = 0; p <= X; p++) { //유지시간
            int time = 2 * k - 1 + p;
            int distance = k * k + p * k;
            if (distance >= X) {
                ans = min(ans, time);
                break;
            }
        }
    }

    cout << ans;

    return 0;
}