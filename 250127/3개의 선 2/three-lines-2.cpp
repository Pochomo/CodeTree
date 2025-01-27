#include <iostream>

using namespace std;

int n;
int x[20], y[20];

bool iscovered(int xline[], int yline[]) {
    for (int i = 0; i < n; i++) {
        bool covered = false;
        for (int j = 0; j <= 10; j++) {
            if (xline[j] && x[i] == j) {
                covered = true;
                break;
            }
            if (yline[j] && y[i] == j) {
                covered = true;
                break;
            }
        }
        if (!covered) return false;
    }
    return true; 
}

bool covered(){
    //x로만 커버되는지, y로만 커버되는지 아니면 x와 y 혼합해야하는지(1, 2 or 2, 1) 나눠서 체크
    for (int x1 = 0; x1 <= 10; x1++){
        for (int x2 = x1; x2 <= 10; x2++){
            for (int x3 = x2; x3 <= 10; x3++){ //직선 3개 선택
                for (int y1 = 0; y1 <= 10; y1++){
                    for (int y2 = y1; y2 <= 10; y2++){
                        for (int y3 = y2; y3 <= 10; y3++){ //직선 3개 선택
                            for(int z = 1; z <= 4; z++){
                                int xline[11] = {0};
                                int yline[11] = {0};
                                if(z == 1){ //3 0
                                    xline[x1]++;
                                    xline[x2]++;
                                    xline[x3]++;
                                }
                                else if(z == 2){ //2 1
                                    xline[x1]++;
                                    xline[x2]++;
                                    yline[y1]++;

                                }
                                else if(z == 3){ //1 2
                                    xline[x1]++;
                                    yline[y1]++;
                                    yline[y2]++;
                                }
                                else if(z == 4){ //0 3
                                    yline[y1]++;
                                    yline[y2]++;
                                    yline[y3]++;
                                }
                                if (iscovered(xline, yline)) return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    //직선 3개(x, y에 평행함)로 모든 점들 지날 수 있는지
    //x or y 겹치는 구간이 3개면 됨 3개롤 모든 점들 묶을 수 있으면 1출력 아니면 0
    //모든 경우를 다 따져서 3개가 나오는 경우가 있으면 true 아니면 false
    //직선 3개 선택해서 그 직선이 모든 점 지나는지 확인하면 될거같음

    if(covered()) cout << 1;
    else cout << 0;
    return 0;
}