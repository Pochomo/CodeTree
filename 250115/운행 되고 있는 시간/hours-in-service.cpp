#include <iostream>
#include <climits>
using namespace std;

int N;
int A[100], B[100];

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {  //fired
        int time = 0;
        for (int t = 1; t <= 1000; t++) {
            bool isOperating = false;
            for (int k = 0; k < N; k++) {
                if (k == i) continue;  // 해고
                if (A[k] <= t && t < B[k]) {
                    isOperating = true;
                    break;
                }
            }
            if (isOperating) time++;
        }
        ans = max(ans, time);
    }
    
    cout << ans;
    return 0;
}