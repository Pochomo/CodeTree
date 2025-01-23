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

    for (int i = 0; i < N; i++) {
        total[i] = P[i] + S[i];
    }

    for (int i = 0; i < N; i++) {
        sales_total[i] = P[i] / 2 + S[i];
    }

    sort(total, total + N);
    sort(sales_total, sales_total + N);


    int ans = INT_MIN;
    for (int i = 0; i < N; i++) { //할인 받을 학생 선물
        for (int j = 0; j < N; j++) {
            int budget = B;
            int cnt = 0;
            for (int k = 0; k < N; k++) {
                if(i == k) {
                    int price = sales_total[i];
                    if(budget >= (price)) {
                        budget -= (price);
                        cnt++;
                    }
                } 
                else {
                    if(budget >= (total[k])) {
                        budget -= (total[k]);
                        cnt++;
                    }
                }
            }
            ans = max(ans, cnt);
    }
}

    cout << ans;

    return 0;
}