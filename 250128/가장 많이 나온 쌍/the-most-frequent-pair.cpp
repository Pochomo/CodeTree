#include <iostream>
#include <climits>
using namespace std;

int n, m;
int A[100], B[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> A[i] >> B[i];
    }

    //1이상 n이하의 숫자로만 이루어진 (a,b) 숫자 쌍이 총 m번 주어질 때 가장 많이 나온 숫자 쌍을 세라
    //(a, b) (b, a)는 같은 숫자 쌍

    int ans = INT_MIN;
    for(int a = 1; a <= n; a++){
        for(int b = 1; b <= n; b++){
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                if(a == A[i] && b == B[i] || b == A[i] && a == B[i]){
                    cnt ++;
                }
            }
            ans = max(cnt, ans);
        }
        
    }
    
    
    cout << ans;

    return 0;
}