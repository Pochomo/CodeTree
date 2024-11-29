#include <iostream>
using namespace std;

int paperx = 8;
int papery = 8;
int result[400][400] = {0};

int main() {
    int n;
    cin >> n; //색종이 갯수
    int OFFSET = 200;

    int x1, y1; //색종이 꼭지점의 위치
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1; //색종이 꼭지점의 위치
        for(int j = x1 + OFFSET; j < x1 + paperx + OFFSET; j++){
            for(int k = y1 + OFFSET; k < y1 + papery + OFFSET; k++){
                result[j][k] = 1;
        }
    }
    }

    int cnt = 0;
    for(int i = 0; i < 400; i++){
        for(int j = 0; j < 400; j++){
            if(result[i][j] == 1){
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}