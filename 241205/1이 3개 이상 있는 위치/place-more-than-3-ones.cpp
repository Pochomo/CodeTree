#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int arr[100][100];

bool inrange(int x, int y, int n){
    return (0 <= x && x < n && 0 <= y && y < n);
}
//상하 좌우에 1이 있는지 판단은 dx, dy를 더해줌으로써 판단 1, 0 -1이 알맞게 더해짐 행 열에 따라
int main() {
    int n;
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            arr[i][j] = num;
        }
    }
    int x;
    int y;
    int cnt = 0;
    int fin_cnt = 0;
    for(int dir_y = 0; dir_y < n; dir_y++){
        x = 0, y = 0;
        for(int dir_x = 0; dir_x < n; dir_x++){
            x = dir_x + dx[dir_x], y = dir_y + dy[dir_y];
            if((inrange(x, y, n)) && arr[x][y] == 1){
                cnt++;
            }
        }
        if(cnt > 2){
            fin_cnt++;
        }
        cnt = 0;
    }

    cout << fin_cnt;

    return 0;
}