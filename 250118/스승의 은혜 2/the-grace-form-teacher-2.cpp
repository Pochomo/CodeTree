#include <iostream>
#include <climits>

using namespace std;

int N, B;
int P[1000];

int main() {
    cin >> N >> B;
    //N명의 학생에게 B만큼의 예산으로 선물을 주려고 한다.
    //학생 i가 원하는 선물의 가격 P(i)
    //선생님은 하나를 반값으로 할인 받을 수 있는 쿠폰이 있다.
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int ans = INT_MIN;
    int cnt; //사줄 수 있는 학생 수
    //만약 예산을 넘어가면 
    for (int i = 0; i < N; i++) { //할인 받는 선물
        int price1 = P[i] / 2;
        for (int j = 0; j < N; j++) {
            cnt = 0;
            int budget = B;
            for (int k = j; k < N; k++) { //몇번부터 몇번까지 살 수 있는지 도는 loop
                if(k == i){
                    if(budget >= price1){
                        cnt ++;
                        budget -= price1;
                    }
                }
                else if(budget >= P[k]){
                    cnt ++;
                    budget -= P[k];
                }
                else{
                    break;
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}