#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
int arr[1000];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //최댓값과 최솟값의 차가 K이하가 되도록한다. 뽑을 수 있는 최대 숫자의 개수구하라
    //정렬하고 최대 최소 차가 K 이하인 숫자들 갯수가 가장 많은 거 뽑기
    int ans = INT_MIN;
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if(arr[j] - arr[i] <= K){
                ans = max(ans, j - i + 1);
            }else {
                break;
            }
        }
    }
    
    cout << ans;

    return 0;
}