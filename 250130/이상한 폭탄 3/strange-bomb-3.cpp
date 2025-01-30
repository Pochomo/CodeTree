#include <iostream>
#include <climits>

using namespace std;

int N, K;
int num[100];

int main() {
    cin >> N >> K;

    //같은 정수가 부여된 폭탄끼리 k안에있으면 폭발한다.
    //폭탄의 개수 n, 특정 거리인 K, 부여된 정수순으로 주어짐, 폭발한 폭탄 중 가장많이 터진 폭탄의 정수는?
    int count[1000000] = {};
    bool checked[1000000] = {};
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        count[num[i]]++; //ex 2가 몇번 등장했는지
    }

    int maxExplodes = 0;
    int maxNumber = 0;

    //count가 2 이상인 경우만 체크(index가 그 정수의 번호임) 
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        if(count[num[i]] <= 2) continue;
        if(checked[num[i]] == true) continue;
        for (int j = 0; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                if(num[j] == num[i] && num[k] == num[i]){
                    if(k - j <= K){
                        cnt++;
                        break;
                    }
                }
            }
        }

        checked[num[i]] = true;

        if(cnt > maxExplodes) {
            maxExplodes = cnt;
            maxNumber = num[i];
        }
    }

    if(maxExplodes == 0) cout << maxExplodes;
    else cout << maxNumber;

    return 0;
}