#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N, B;
int P[1000];
int S[1000];
int total[1000];
int sales_total[1000];

//N명의 학생에게 B만큼의 예산으로 선물

int main() {
    cin >> N >> B;
    //학생 i가 원하는 선물의 가격 P[i] 배송비 S[i] 하나를 정해서 반 값 할인 가능
    //선물 가능한 학생의 최대 명수를 구하라 
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> S[i];
    }


    sort(total, total + N);


    int ans = INT_MIN;
    for(int i = 0; i < N; i++) { // 할인 받을 학생
        // 현재 학생 제외하고 나머지 total 배열 만들기
        int idx = 0;
        for(int j = 0; j < N; j++) {
            if(i != j) total[idx++] = P[j] + S[j];
        } 
        sort(total, total + idx);
       
        int budget = B;
        int cnt = 0;
       
        // 할인 받는 학생 먼저 처리
        if(budget >= P[i]/2 + S[i]) {
            budget -= P[i]/2 + S[i];
            cnt++;
        }
       
        // 나머지 학생들 처리
        for(int j = 0; j < idx; j++) {
            if(budget >= total[j]) {
                budget -= total[j];
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}