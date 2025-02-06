#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[100000];
int positive[100000];
int negative[100000];
int cnt_P = 0;
int cnt_N = 0;
bool zero = false;
bool compare(int i, int j){
    return j < i;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] == 0) zero = true;
        else if(arr[i] < 0) {
            negative[i] = arr[i];
            cnt_N++;
        }
        else if(arr[i] > 0){
            positive[i] = arr[i];
            cnt_P++;
        } 
    }

    sort(negative, negative + n);
    sort(positive, positive + n, compare);

    //3개 최대 수 얻는 방법, 양수 최대 3개 곱하기 
    //0 있는 경우, 없는 경우
    int ans = INT_MIN;
    int total_P = 1;
    int total_N = 1;
    if(zero){
        ans = 0;
    }

    //음수 1개 양수 2개
    if(cnt_N >=1 && cnt_P >= 2) {
        total_N *= negative[0];
        for(int i = 0; i < 2; i++){
            total_N *= positive[i];
        }
        ans = max(total_N, ans);
    }
    total_N = 1;
    //음수 0개 양수 3개
    if(cnt_P >= 3) {
        for(int i = 0; i < 3; i++){
            total_P *= positive[i];
        }
        ans = max(total_P, ans);
    }
    
    //음수 2개 양수 1개
    if(cnt_N >= 2 && cnt_P >= 1) {
        total_N *= positive[0];
        for(int i = 0; i < 2; i++){
            total_N *= negative[i];
        }
        ans = max(total_N, ans);
    }
    
    cout << ans;

    return 0;
}