#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int abilities[6];
int total = 0;

int getDiff(int a, int b, int c){
    int sum1 = 0;
    int sum2 = 0;
    sum1 = abilities[a] + abilities[b] + abilities[c];
    sum2 = total - sum1;

    return abs(sum1-sum2);
}

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> abilities[i];
        total += abilities[i];
    }

    int ans = INT_MAX;
    int diff = 0;
    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 5; j++){
            for(int k = j+1; k < 6; k++){
                diff = getDiff(i, j, k); 
                ans = min(ans, diff);
            }
        }
    }

    cout << ans;

    return 0;
}