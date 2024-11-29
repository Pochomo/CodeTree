#include <iostream>
using namespace std;

int result[2000][2000] = {0};

//result를 기준으로 a b 는 1로 m은 2로 표현해서 1만 출력
int main() {
    int x1, y1, x2, y2;
    int OFFSET = 1000;
    int cur = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 + OFFSET; i < x2 + OFFSET; i++){
        for(int j = y1 + OFFSET;  j< y2 + OFFSET; j++){
            result[i][j] = 1;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 + OFFSET; i < x2 + OFFSET; i++){
        for(int j = y1 + OFFSET;  j< y2 + OFFSET; j++){
            result[i][j] = 1;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 + OFFSET; i < x2 + OFFSET; i++){
        for(int j = y1 + OFFSET;  j< y2 + OFFSET; j++){
            result[i][j] = 2;
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < 2000; i++){
        for(int j = 0; j < 2000; j++){
            if(result[i][j] == 1){
                cnt ++;
            }
        }
    }

    cout << cnt;
    return 0;
}