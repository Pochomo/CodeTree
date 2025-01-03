#include <iostream>
#include <climits>

using namespace std;

int n;
int numbers[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int ans = INT_MIN;
    int temp = 0;
    for (int i = 0; i < n; i++){
        for(int j = i + 2; j < n; j++){
            if(j < n){
                temp = (numbers[i] + numbers[j]);
            }
            ans = max(temp, ans);
            temp = 0;
        } 
    }

    cout << ans;

    return 0;
}