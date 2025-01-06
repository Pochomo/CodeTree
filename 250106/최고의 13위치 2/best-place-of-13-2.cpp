#include <iostream>
#include <climits>

using namespace std;

int N;
int arr[20][20];

bool inrange(int i, int j, int z, int k) {
    return i < N && j < N && i >= 0 && j >= 0 && z < N && k < N && z >= 0 && k >= 0;
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    // 겹치지 않는 1 * 3 크기 격자 2개 내에 들어올 수 있는 최대 동전의 수
    int ans = INT_MIN;
    int num = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-2; j++) {
            for (int z = i; z < N; z++) {
                for (int k = 0; k < N-2; k++) {
                    num = 0;
                    
                    // 범위 벗어나면 continue
                    if(!inrange(i, j, z, k)) {
                        continue;
                    }
                    
                    // 안겹치면 더하기
                    if(!(i == z && j == k)) {
                        for(int m = 0; m < 3; m++) {
                            num += (arr[i][j+m]);
                            num += (arr[z][k+m]);
                        }
                        ans = max(num, ans);
                    }
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}