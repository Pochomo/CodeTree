#include <iostream>
using namespace std;

int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

int arrA[100][100] = {0};

bool inRange(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}
//색칠한 직후 편안한 상태 놓여있는지 확인 인접한 4개의 칸 중 격자를 벗어나지 않는 칸에 색칠돼있는 칸이 3개인경우
//편안이면 1 아니면 0
int main() {
    int n, m;
    cin >> n >> m;
    int r, c; //r행 c열
    int x = 0, y = 0;
    int nx = 0, ny = 0;
    int cnt = 0; //인접한 칸 갯수
    for(int i = 0; i < m; i++){
        cin >> r >> c; //동일한 칸에 2번이상 색칠하는 경우는 없다.
        x = r - 1;
        y = c - 1;
        arrA[x][y] = 1;
        if(inRange(x + dx[0], y + dy[0], n) && arrA[x + dx[0]][y + dy[0]] == 1){
            cnt ++;
        }
        if(inRange(x + dx[1], y + dy[1], n) && arrA[x + dx[1]][y + dy[1]] == 1){
            cnt ++;
        }
        if(inRange(x + dx[2], y + dy[2], n) && arrA[x + dx[2]][y + dy[2]] == 1){
            cnt ++;
        }
        if(inRange(x + dx[3], y + dy[3], n) && arrA[x + dx[3]][y + dy[3]] == 1){
            cnt ++;
        }
        if(cnt == 3){
            cout << 1;
            cout << endl;
        }
        else{
            cout << 0;
            cout << endl;
        }
        cnt = 0;
    }

    return 0;
}