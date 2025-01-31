#include <iostream>
#include <algorithm>

#define MAX_A 10000
#define MAX_N 100

using namespace std;

int n, m;
int a[MAX_N];

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = MAX_A;
    for(int i = 1; i <= MAX_A; i++) {
       
        bool possible = true;
        int section = 1;

        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] > i) {
                possible = false;
                break;
            }

            if(cnt + a[j] > i) {
                cnt = 0;
                section++;
            }

            cnt += a[j];
        }

        if(possible && section <= m) {
            ans = min(ans, i);
        }
    }

    cout << ans;

    return 0;
}
