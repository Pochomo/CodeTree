#include <iostream>

using namespace std;

int X;

int main() {
    cin >> X;

    //Xm 만큼 달리기를 진행, 1m/s로 시작하되, 1초에 한 번씩 속도를 유지할지, 증가할지 감소할지 결정
    //도착지에 도달하는 순간 속력은 무조건 '1'
    //최단 시간구하는 프로그램 도중 0이 되서는 x
    //최소로 할라면 증가 감소가 일정해야됨 6이면 2 3 증가 3 2 감소 1 2 3 2 1 1
    //11 이면 1 2 3 2 2 1
    //실제 이동거리가 X 이상이면 중간에 알아서 감소해서 갈 수 있다는 뜻
    int times = 0;
    bool clear = false;
    for(int i = 1; i <= 10000; i++){ //가능한 시간 범위 일정하게 유지해서 쭉 진행했을 때 i = sec임
        int speed = 1;
        int distance = 1;
        for (int j = 1; j <= i; j++) {
            if (j <= (i + 1) / 2) {
                speed = j;
            } else {
                speed = i + 1 - j;
            }
            distance += speed;
        }
        if(distance == X && speed == 1) {
            clear = true;
            times = i + 1;
            break;
        }
    }

    if(clear) cout << times;

    return 0;
}