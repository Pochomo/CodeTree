#include <iostream>
#include <climits>
using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    int ans = INT_MIN;
    for(int i = X; i <= Y; i++){
        int total = 0;
        int d1 = i;
        while(d1 > 0){
            total += (d1 % 10);
            d1 /= 10;
        }
        ans = max(total, ans);
    }

    cout << ans;
    
    return 0;
}