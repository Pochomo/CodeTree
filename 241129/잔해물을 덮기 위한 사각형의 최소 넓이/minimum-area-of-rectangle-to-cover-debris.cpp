#include <iostream>
using namespace std;

int x1A[2] = {0};
int x2A[2] = {0};
int y1A[2] = {0};
int y2A[2] = {0};

int result1[4000][4000] = {0};
//직사각형 하나 2로 나머지 하나 1로 함 그리고 만약 2를 수정할때는 3으로 바꾸고
//좌표로 계산 min, max 값 받아서 각각 x1, x2 처럼 계산

int main() {
    int OFFSET = 1000;
    int x1, x2, y1, y2;

    for(int i  = 0 ; i < 2; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += OFFSET;
        x2 += OFFSET;
        y1 += OFFSET;
        y2 += OFFSET;

        x1A[i] = x1;
        x2A[i] = x2;
        y1A[i] = y1;
        y2A[i] = y2;

    }

    for(int i = x1A[0]; i < x2A[0]; i++){
        for(int j = y1A[0]; j < y2A[0]; j++){
            result1[i][j] = 1;
        }
    }

    for(int i = x1A[1]; i < x2A[1]; i++){
        for(int j = y1A[1]; j < y2A[1]; j++){
                result1[i][j] = 2;
            }
        }

    int minx;
    int maxx;
    int miny;
    int maxy;
    int cnt = 0;
    for(int i = 0; i < 4000; i++){
        for(int j = 0; j < 4000; j++){
            if(result1[i][j] == 1){
                if(cnt == 0){
                    minx = i;
                    miny = j;
                    maxx = i;
                    maxy = j;
                    cnt++;
                }
                if(minx > i){
                    minx = i;
                }
                if(maxx < i){
                    maxx = i;
                }
                if(miny > j){
                    miny = j;
                }
                if(maxy < j){
                    maxy = j;
                }
            }
        }
    }

    cnt = 0;
    bool nsame = true;
    if(minx == maxx && miny == maxy){
        nsame = false;
    }

    if(nsame){
        for(int i = minx; i <= maxx; i++){
            for(int j = miny; j <= maxy; j++){
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}