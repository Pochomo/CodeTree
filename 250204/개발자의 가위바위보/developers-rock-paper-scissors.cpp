#include <iostream>
#include <climits>

using namespace std;

int N;
int a[100], b[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    //가위바위보가 1, 2, 3으로 주어짐
    //어떤 숫자가 무엇을 나타내는지 정해지지 않음, 적절히 매칭시켜서 첫번째 개발자가 이기는 횟수 최대로
    int ans = INT_MIN;
    for (int i = 1; i <= 6 ; i++) {
        int win_count = 0;
        if(i == 1){ //1 가위 2 바위 3 보
            for(int j = 0; j < N; j++){
                if(a[j] == 1 && b[j] == 3) win_count++;
                else if(a[j] == 2 && b[j] == 1) win_count++;
                else if(a[j] == 3 && b[j] == 2) win_count++;
            }
            ans = max(win_count, ans);
        }
        else if(i == 2){ //1 가위 2 보 3 바위
            for(int j = 0; j < N; j++){
                if(a[j] == 1 && b[j] == 2) win_count++;
                else if(a[j] == 2 && b[j] == 3) win_count++;
                else if(a[j] == 3 && b[j] == 1) win_count++;
            }
            ans = max(win_count, ans);
        }
    }

    cout << ans;

    return 0;
}