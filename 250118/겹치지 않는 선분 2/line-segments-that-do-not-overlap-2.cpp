#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n;
int x1[MAX_N], x2[MAX_N];

int main() {
    
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> x1[i] >> x2[i];

    int ans = 0;

    for(int i = 0; i < n; i++) {
        bool overlap = false;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            if((x1[i] <= x1[j] && x2[i] >= x2[j]) || (x1[i] >= x1[j] && x2[i] <= x2[j])) {
                overlap = true;
                break;
            }
        }
        if(overlap == false)
            ans++;
    }

    cout << ans;
    
    return 0;
}
