#include <iostream>
#include <climits>

using namespace std;

int N, K;
int num[100];

int main() {
    cin >> N >> K;
    //이상한 N개의 폭탄
    //이 이상한 폭탄은 각자에게 부여된 번호 O
    //같은 번호가 부여된 폭탄끼리 거리가 K안에 있으면 폭발함

    //폭발 할 폭탄중에 부여된 번호가 가장 큰 번호를 출력하는 프로그램
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    //터지는 폭탄이 없으면 -1

    int ans = -1;
    for (int i = 0; i < N; i++) { //같은 숫자 있나 탐색
        for (int j = i+1; j < N; j++) {
            if(num[i] == num[j] && K >= j-i){    
                ans = max(ans, num[i]);
            }
        }
    }

    cout << ans;

    return 0;
}