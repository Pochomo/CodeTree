#include <iostream>
#include <climits>

using namespace std;

int N;
int pos[100];
char alpha[100];
char GorH[100];

int main() {
    cin >> N;

    int maxA;

    for (int i = 0; i < N; i++) {
        cin >> pos[i] >> alpha[i];
        GorH[pos[i]] = alpha[i];
        maxA = max(pos[i], maxA);
    }
    

    //N명의 사람이 G or H 팻말을 들고있다.
    //오로지 G or H로만 혹은 G와 H가 같은 갯수로 나올 수 있도록 하는 최대 사진의 크기를 찾자
    //거리가 사진의 크기, 사람 1명이면 크기 0 -> 크기 = 사람 -1
    int ans = 0;
    for(int i = 0; i <= maxA; i++){
        for(int j = i+1; j <= maxA; j++){
            int Gcnt = 0;
            int Hcnt = 0;
            int Sindex = 0;
            int Eindex = 0;
            int distance = 0;
            int correct = true;
            //영역의 g, h 갯수 확인
            for(int k = i; k <= j; k++){
                if(GorH[k] == 'H'){
                    if(correct) Sindex = k;
                    correct = false;
                    Hcnt++;
                    Eindex = k;
                }
                else if(GorH[k] == 'G'){
                    if(correct) Sindex = k;
                    correct = false;
                    Gcnt++;
                    Eindex = k;
                }
                distance = (Eindex - Sindex);
            }
            if((Gcnt == Hcnt) || Gcnt == 0 || Hcnt == 0){
                ans = max(ans, distance);
            }
        }
    }
    
    cout << ans;

    return 0;
}

//답지는 사람이 없는 위치는 빠르게 건너뛰어 불필요한 연산 감소해서 