#include <iostream>
#include <climits>
using namespace std;

int A, B, C;

int main() {
    cin >> A >> B >> C;

    int ableNum1 = C / A;
    int ableNum2 = C / B;

    int ans = INT_MIN;
    for(int i = 0; i <= ableNum1; i++){
        for(int j = 0; j <= ableNum2; j++){ //곱하는 숫자
            int num = ((A * i)+(B * j));
            if(num < C){
                ans = max(num, ans);
            }
        }
    }

    cout << ans;

    return 0;
}