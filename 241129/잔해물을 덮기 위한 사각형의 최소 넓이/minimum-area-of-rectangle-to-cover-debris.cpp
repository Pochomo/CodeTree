#include <iostream>
using namespace std;

int x1A[2] = {0};
int x2A[2] = {0};
int y1A[2] = {0};
int y2A[2] = {0};

int result[4000][4000] = {0};
//직사각형 하나 2로 나머지 하나 1로 함 그리고 만약 2를 수정할때는 3으로 바꾸고
//3이나 2인경우를 숫자 세면 됨
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
            result[i][j] = 1;
        }
    }
    for(int i = x1A[1]; i < x2A[1]; i++){
        for(int j = y1A[1]; j < y2A[1]; j++){
            if(result[i][j] == 1){
                result[i][j] = 3;
            }
            else{
                result[i][j] = 2;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < 4000; i++){
        for(int j = 0; j < 4000; j++){
        if(result[i][j] == 1 || result[i][j] == 3 ){
            cnt++;
        }
        }
    }

    cout << cnt;
    return 0;
}