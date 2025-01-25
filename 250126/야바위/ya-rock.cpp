#include <iostream>

using namespace std;

int N;
int a[100], b[100], c[100];

int main() {
    cin >> N;

    //N번에 걸쳐 a번 종이컵, b번 종이컵 교환, c번 종이컵을 열어 그 안에 조약돌 있으면 점수
    //어디에 넣어야 가장 점수가 높은지 찾아라
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int maxC[3] = {};
    for(int i = 0; i < 3; i++){
        int point = 0;
        int location = i + 1; //돌있는 위치 종이컵 기준으로 세기
        for(int j = 0; j < N; j++){//포인트 세기
            if(location == a[j]){
                location = b[j];
            }
            else if(location == b[j]){
                location = a[j];
            }
            if(location == c[j]){
                point++;
            }
        }
        maxC[i] = point;
    }

    //몇번 종이컵인지 찾는 로직
    int maxN = maxC[0];
    for(int i = 1; i < 3; i++){
        if(maxN < maxC[i]){
            maxN = maxC[i];
        }
    }

    cout << maxN;

    return 0;
}