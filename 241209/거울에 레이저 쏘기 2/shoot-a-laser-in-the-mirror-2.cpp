#include <iostream>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

char arrA[1000][1000];

bool inRange(int x, int y, int n) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    int n, k;
    cin >> n;
    string mirror;
    //거울 구성
    for(int i = 0; i < n; i++){
        cin >> mirror;
        for(int j = 0; j < (int)mirror.size(); j++){
            if(mirror[j] == '\\'){
                arrA[i][j] = '\\';
            }
            else if(mirror[j] == '/'){
                arrA[i][j] = '/';
            }
        }
    }

    cin >> k;
    //빛 쏘는 시작점 잡기 , 0, 0도 같은 0, 0이 아니므로 그 방향도 잡아야함 -dx 로 돌때마다 시계
    int x = 0, y = 0;
    int nx = 0, ny = 0;
    int direction = 0;
    int shoot_dic = 1;
    for(int i = 1; i <= 4 * n; i++){
        if(i == k){
            break;
        }
        nx = x + dx[direction];
        ny = y + dy[direction];
        if(i < 4 * n && i % n == 0){
            shoot_dic = (shoot_dic + 1) % 4;
        }
        if(!inRange(nx, ny, n)){
            direction = (direction + 1) % 4;
            continue;
        }
        x = nx;
        y = ny;
    }
    //몇번 팅기는지 카운팅
    int cnt = 0;
    nx = 0, ny = 0;
    while(inRange(x, y, n)){
        if((shoot_dic == 1 || shoot_dic == 3) && arrA[x][y] == '\\'){ // 반사후 왼쪽
            cnt++;
            shoot_dic = (shoot_dic + 3) % 4;
            nx = x + dx[shoot_dic];
            ny = y + dy[shoot_dic];
        }
        else if((shoot_dic == 2 || shoot_dic == 0) && arrA[x][y] == '\\'){
            cnt++;
            shoot_dic = (shoot_dic + 1) % 4;
            nx = x + dx[shoot_dic];
            ny = y + dy[shoot_dic];
        }
        else if((shoot_dic == 1 || shoot_dic == 3) && arrA[x][y] == '/'){ // 반사후 오른쪽
            cnt++;
            shoot_dic = (shoot_dic + 1) % 4;
            nx = x + dx[shoot_dic];
            ny = y + dy[shoot_dic];
        }
        else if((shoot_dic == 2 || shoot_dic == 0) && arrA[x][y] == '/'){
            cnt++;
            shoot_dic = (shoot_dic + 3) % 4;
            nx = x + dx[shoot_dic];
            ny = y + dy[shoot_dic];
        }
        x = nx;
        y = ny;
    }

    cout << cnt;

    return 0;
}