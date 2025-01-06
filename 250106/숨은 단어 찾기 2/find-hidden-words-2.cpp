#include <iostream>
#include <string>

using namespace std;

int N, M;
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

string arr[50];

bool inrange(int i, int j, int n, int m){
    return i < n && j < m && i >= 0 && j >= 0;
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    //int cntR = 0;
    int ans = 0;
    int nx, ny;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            int cnt = 0;
            int cntX = i;
            int cntY = j;
            if(arr[i][j] == 'L'){
                cnt = 1;
                //L 주위에 E 있나 탐색, 있으면 한번 더 E 있나 탐색 후 다시 제자리,
                for(int k = 0; k < 8; k++){
                    cnt = 1;
                    nx = cntX + dx[k];
                    ny = cntY + dy[k];
                    if(!inrange(nx, ny, N, M)){
                        cnt = 0;
                        nx = cntX;
                        ny = cntY;
                        continue;
                    }
                    if(arr[nx][ny] == 'E'){
                        //cntR++;
                        cnt ++;
                        nx += dx[k];
                        ny += dy[k];
                        //같은 방향으로 다음이 E인지 확인
                        if(inrange(nx, ny, N, M) && arr[nx][ny] == 'E'){
                            cnt ++;
                        }
                    }
                    nx = cntX;
                    ny = cntY;
                    if(cnt == 3){
                        ans++;
                        cnt = 0;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}