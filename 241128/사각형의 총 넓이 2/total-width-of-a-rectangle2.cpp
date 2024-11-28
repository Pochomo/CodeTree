#include <iostream>
using namespace std;

//기존 좌표계에서 (x1, y1), (x2, y2)로 이루어진 직사각형은 
//2차원 격자 상에서는 (x1 행, y1 열) 부터 (x2 - 1 행, y2 - 1 열) 까지로 이루어지게된다.
int result[2000][2000] = {0};

int main() {
    int n;
    int x1, y1, x2, y2;
    int OFFSET = 1000;
    int cur = OFFSET;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = cur + x1; j < cur + x2; j++){
            for(int k = cur + y1; k < cur + y2; k++){
                result[j][k]++;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < 2 * OFFSET; i++){
        for(int k = 0; k < 2 * OFFSET; k++){
            if(result[i][k] >= 1){
                cnt ++;
            }
        }
    }

    cout << cnt;
    return 0;
}