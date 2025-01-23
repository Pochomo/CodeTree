#include <iostream>
#include <climits>

using namespace std;

int N, B;
int P[1000];
int S[1000];

//N명의 학생에게 B만큼의 예산으로 선물
int main() {
    cin >> N >> B;
    //학생 i가 원하는 선물의 가격 P[i] 배송비 S[i] 하나를 정해서 반 값 할인 가능
    //선물 가능한 학생의 최대 명수를 구하라 
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> S[i];
    }

    int ans = INT_MIN;
    for (int i = 0; i < N; i++) { //반 값 할인 할 선물
        for (int j = 0; j < N; j++) { //시작점
            int budget = B;
            int cnt = 0;
            for (int k = j; k < N; k++) { //가격 넘으면 continue로 해서 모든 경우 다 셀 수 잇도록
                int price = P[i] / 2;
                if(i == k){
                    if(budget >= (price + S[k])){
                        budget -= (price + S[k]);
                        cnt++; 
                    }
                    else{
                        continue;
                    }
                }
                else{
                    if(budget >= (P[k] + S[k])){
                        budget -= (P[k] + S[k]);
                        cnt++;
                    }
                    else{
                        continue;
                    }
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}