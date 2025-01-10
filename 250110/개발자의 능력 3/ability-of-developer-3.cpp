#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int abilities[6];
int total = 0;

int getDiff(int a, int b){
    int sum1 = 0;
    int sum2 = 0;
    for(int i = a; i <= b; i++){
        sum1 += abilities[i];
    }
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
        for(int j = i+2; j < 6; j++){
            diff = getDiff(i, j); 
            ans = min(ans, diff);
        }
    }

    cout << ans;

    return 0;
}