#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int heights[1000];
int cal[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    
    int ans = INT_MAX;
    for (int base = 0; base <= 100; base++) {
        int cost = 0;
        
        for (int i = 0; i < N; i++) {
            if (heights[i] < base) {
                cost += (base - heights[i]) * (base - heights[i]);
            }
            else if (heights[i] > base + 17) {
                cost += (heights[i] - (base + 17)) * (heights[i] - (base + 17));
            }
        }
        ans = min(ans, cost);
    }
    
    cout << ans;
    return 0;
}