#include <iostream>
#include <climits>

using namespace std;

int n;
int a[10], b[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    //양의 정수 x로 시작하여 값에 2를 곱하는 것을 n번 반복

    //2를 곱할때 마다 ai bi 주어짐
    //가능한 x값중 최솟값

    int ans = INT_MAX;
    for (int x = 10000; x >= 1; x--) {
        int num = x;
        bool correct = true;
        for (int i = 0; i < n; i++) {
            num *= 2;
            if(num >= a[i] && num <= b[i]){
                continue;
            }
            else {
            correct = false;
            break;
            }
        }
        if(correct) ans = min(x, ans);
    }

    cout << ans;
    
    return 0;
}