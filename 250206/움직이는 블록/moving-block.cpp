#include <iostream>

using namespace std;

int n;
int blocks[10000];

int main() {
    cin >> n;
    int total_blocks = 0;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
        total_blocks += blocks[i];
    }
    int goal_blocks = total_blocks / n;

    //모든 위치에 놓인 블럭의 개수가 동일해지게 만들려고 한다.
    //움직여야할 최소 블럭의 수
    //모든 블럭 수 / n 해서 몇으로 맞춰야 하는지 파악
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(blocks[i] > goal_blocks) cnt += (blocks[i] - goal_blocks);
    }

    cout << cnt;

    return 0;
}