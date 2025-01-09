#include <iostream>
#include <climits>

using namespace std;

int N, K;
int candy[100];
int pos[100] = {0}; 
int totalCandy[100] = {0};

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> candy[i] >> pos[i];
    }

    
    //N개의 바구니, 중심점 c를 잡아 c-k c+k의 사탕 수가 최대가 되도록, 사탕수, 바구니 번호로 입력
    //같은 위치에 여러 바구니가 놓여 있는것이 가능하다.
    //예외처리 고려 c의 시작을 K부터 하면 괜찮음.

    //중복 해결 위한 바구니 번호에 따른 총 사탕 갯수 배열 정리
    int index = 0;
    for (int i = 0; i < N; i++){
        totalCandy[pos[i]] += candy[index];
        index++; 
    }
    
    // c = 3 K = 3 일때  
    int c = K; ///중심점
    int ans = INT_MIN;
    for (int i = c-K; i <= 100-2*K; i++){
        int sum = 0;
        for (int j = i; j <= c+K; j++){
            sum += totalCandy[j];
        }
        c++;
        ans = max(sum, ans);
    }

    cout << ans;

    return 0;
}