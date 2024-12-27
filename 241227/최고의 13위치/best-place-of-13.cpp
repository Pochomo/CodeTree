#include <iostream>
#include <algorithm>
using namespace std;

int arrA[20][20] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arrA[i][j];
        }
    }
    int max_cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j ++){
            max_cnt = max(max_cnt, arrA[i][j] + arrA[i][j + 1] + arrA[i][j + 2]);
        }
    }

    cout << max_cnt;

    return 0;
}