#include <iostream>
#include <climits>

using namespace std;

int N, S;
int arr[100];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = INT_MAX;
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            num = 0;
            for(int z = 0; z < N; z++){
                if(z == i || z == j){
                    continue;
                }
                num += arr[z];
            }
            int diff = abs(num - S);
            ans = min(ans, diff);
        }
    }

    cout << ans;

    return 0;
}